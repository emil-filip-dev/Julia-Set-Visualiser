#pragma once

#define _USE_MATH_DEFINES

#include <stdint.h>
#include <complex>
#include <cmath>
#include <vector>

using std::complex;

typedef complex<double> cdouble;

namespace JuliaSetVisualiser 
{
	class JuliaSet 
	{
	public:
		cdouble c;
		cdouble focus;
		double r;
		double zoom = 0.0;

		explicit JuliaSet(cdouble c_, double r_) : c(c_), r(r_) {}

		bool isInSet(cdouble num, int maxIterations, int* iterations);
		void render(std::vector<uint32_t>& pixelBuffer, int width, int height, int maxIterations, bool useCPU = false);
	};

}