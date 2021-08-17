#include "JuliaSet.h"
#include <cmath>
#include <amp.h>

#define MAX_ITERATIONS 75
#define TILE_SIZE 16

using namespace concurrency;
using namespace JuliaSetVisualiser;

int iterate(double z_r, double z_i, double c_r, double c_i, double r, int maxIterations) restrict(cpu, amp) {
	int i;
	double zr_temp = 0;
	for (i = 0; z_r * z_r + z_i * z_i < r * r && i < maxIterations; ++i) {
		zr_temp = z_r * z_r - z_i * z_i;
		z_i = 2 * z_r * z_i + c_i;
		z_r = zr_temp + c_r;
	}
	return i;
}

uint32_t colour(int iterations) restrict(cpu, amp) {
	uint32_t colour = 0xFF000000;
	double ratio = (double)iterations / (double)MAX_ITERATIONS;
	if (ratio != 1.0) {
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
}

void renderCPU(uint32_t* colours, int width, int height, JuliaSet* set) {
	cdouble focus = set->focus();
	double zoom = set->zoom();
	int* iterations;
	int ind = 0;
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++, ind++) {
			cdouble num = focus + cdouble((double)(i - width / 2) * zoom + zoom / 2, (double)(j - height / 2) * zoom + zoom / 2);
			if (set->isInSet(num, MAX_ITERATIONS, iterations)) {
				colours[ind] = 0xFF000000;
			}
			else {
				colours[ind] = colour(*iterations);
			}
		}
	}
}

void renderGPU(uint32_t* colours, int width, int height, JuliaSet* set) {

}

namespace JuliaSetVisualiser {

	bool JuliaSet::isInSet(cdouble num, int maxIterations, int* iterations) {
		return maxIterations == (*iterations = iterate(real(num), imag(num), real(c_), imag(c_), r_, maxIterations));
	}

	void JuliaSet::render(uint32_t* colours, int width, int height, bool useCPU) {
		if (zoomFactor_ == 0.0) {
			zoomFactor_ = 1 * r_ / min(width, height);
		}
		if (useCPU) {
			renderCPU(colours, width, height, this);
		}
		else {
			//renderGPU(colours, width, height);
		}
	}
}

