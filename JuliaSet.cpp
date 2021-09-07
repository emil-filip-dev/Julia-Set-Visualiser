#include "JuliaSet.h"
#include <boost/compute.hpp>
#include <vector>

using JuliaSetVisualiser::JuliaSet;

namespace compute = boost::compute;

int iterate(double z_r, double z_i, double c_r, double c_i, double r, int maxIterations) 
{
	int i = 0;
	double zr_temp = 0;
	for (; z_r * z_r + z_i * z_i < r * r && i < maxIterations; ++i) {
		zr_temp = z_r * z_r - z_i * z_i;
		z_i = 2 * z_r * z_i + c_i;
		z_r = zr_temp + c_r;
	}
	return i;
}

uint32_t calcColours(int iterations, int maxIterations) 
{
	uint32_t colour = 0xFF000000;
	if (iterations < maxIterations) {
		double ratio = iterations / (double)maxIterations;
		ratio -= 0.5;
		ratio = 1.0 - (ratio < 0.0 ? -ratio : ratio) / 0.5;
		if (ratio < 0.25) {
			colour = 0xFF0000FF | (uint32_t)(0xFF * ((ratio - 0.0f) / 0.25f)) << 8;
		}
		else if (ratio < 0.5) {
			colour = 0xFF00FF00 | ((uint32_t)(0xFF * ((ratio - 0.25f) / 0.25f)) << 16) | (uint32_t)(0xFF * ((0.5f - ratio) / 0.25f));
		}
		else if (ratio < 0.75) {
			colour = 0xFFFF0000 | (uint32_t)(0xFF * ((0.75f - ratio) / 0.25f)) << 8;
		}
		else {
			colour = 0xFF000000 | (uint32_t)(0xFF * (0.5f + (1.0f - ratio) / 0.5f)) << 16;
		}
	}
	return colour;
}

void renderCPU(JuliaSet& set, std::vector<uint32_t>& pixelBuffer, int width, int height, int maxIterations)
{
	const cdouble focus = set.focus;
	const double zoom = set.zoom;
	int iterations;
	int ind = 0;
	cdouble num;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++, ind++) {
			num = focus + cdouble((i - width / 2.0) * zoom, (j - height / 2.0) * zoom);
			if (set.isInSet(num, maxIterations, &iterations)) {
				pixelBuffer[ind] = 0xff000000;
			}
			else {
				pixelBuffer[ind] = calcColours(iterations, maxIterations);
			}
		}
	}
}

void renderGPU(JuliaSet& set, std::vector<uint32_t>& pixelBuffer, int width, int height, int maxIterations)
{
	using compute::float2_;

	int dataLength = width * height;
	double f_r = real(set.focus);
	double f_i = imag(set.focus);
	double c_r = real(set.c);
	double c_i = imag(set.c);
	double zoom = set.zoom;
	double r = set.r;

	compute::vector<int> indexesVector(dataLength);
	compute::vector<int> iterationsVector(dataLength);
	compute::vector<uint32_t> coloursVector(dataLength);

	BOOST_COMPUTE_CLOSURE(int, iterate, (int index), (width, height, f_r, f_i, c_r, c_i, zoom, r, maxIterations),
	{
		int x = index / height;
		int y = index % height;
		double z_r = f_r + (x - width / 2.0) * zoom;
		double z_i = f_i + (y - height / 2.0) * zoom;
		int i = 0;
		double zr_temp = 0.0;
		for (; z_r * z_r + z_i * z_i < r * r && i < maxIterations; ++i) {
			zr_temp = z_r * z_r - z_i * z_i;
			z_i = 2 * z_r * z_i + c_i;
			z_r = zr_temp + c_r;
		}
		return i;
	});

	BOOST_COMPUTE_CLOSURE(uint32_t, calcColour, (int iterations), (maxIterations),
	{
		int colour = 0xFF000000;
		if (iterations < maxIterations) {
			float ratio = iterations / (float)maxIterations;
			ratio -= 0.5;
			ratio = 1.0 - (ratio < 0.0 ? -ratio : ratio) / 0.5;
			if (ratio < 0.25) {
				colour = 0xFF0000FF | (int)(0xFF * ((ratio - 0.0f) / 0.25f)) << 8;
			}
			else if (ratio < 0.5) {
				colour = 0xFF00FF00 | ((int)(0xFF * ((ratio - 0.25f) / 0.25f)) << 16) | (int)(0xFF * ((0.5f - ratio) / 0.25f));
			}
			else if (ratio < 0.75) {
				colour = 0xFFFF0000 | (int)(0xFF * ((0.75f - ratio) / 0.25f)) << 8;
			}
			else {
				colour = 0xFF000000 | (int)(0xFF * (0.5f + (1.0f - ratio) / 0.5f)) << 16;
			}
		}
		return colour;
	});

	compute::iota(indexesVector.begin(), indexesVector.end(), 0);
	compute::transform(indexesVector.begin(), indexesVector.end(), iterationsVector.begin(), iterate);
	compute::transform(iterationsVector.begin(), iterationsVector.end(), coloursVector.begin(), calcColour);
	compute::copy(coloursVector.begin(), coloursVector.end(), pixelBuffer.begin());
}

namespace JuliaSetVisualiser 
{
	bool JuliaSet::isInSet(cdouble num, int maxIterations, int* iterations) 
	{
		return maxIterations == (*iterations = iterate(real(num), imag(num), real(c), imag(c), r, maxIterations));
	}

	void JuliaSet::render(std::vector<uint32_t>& pixelBuffer, int width, int height, int maxIterations, bool useCPU)
	{
		if (zoom == 0.0) {
			zoom = 1 * r / std::min(width, height);
		}
		if (useCPU) {
			renderCPU(*this, pixelBuffer, width, height, maxIterations);
		} else {
			renderGPU(*this, pixelBuffer, width, height, maxIterations);
		}
	}
}

