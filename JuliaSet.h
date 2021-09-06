#pragma once

#define _USE_MATH_DEFINES

#include <stdint.h>
#include <complex>
#include <cmath>

using std::complex;

typedef complex<double> cdouble;

namespace JuliaSetVisualiser {

	class JuliaSet {

		cdouble c_;
		double r_;
		double zoomFactor_ = 0.0;
		cdouble focus_ = cdouble(0.0, 0.0);

	public:
		explicit JuliaSet(cdouble c, double r) : c_(c), r_(r) {}

		bool isInSet(cdouble num, int maxIterations, int* iterations);
		void render(uint32_t* colours, int width, int height, int maxIterations, bool useCPU = false);

		auto c()       ->       cdouble& { return c_; }
		auto c() const -> const cdouble& { return c_; }

		auto r()       ->       double& { return r_; }
		auto r() const -> const double& { return r_; }

		auto zoom()       ->       double& { return zoomFactor_; }
		auto zoom() const -> const double& { return zoomFactor_; }
		
		auto focus()       ->       cdouble& { return focus_; }
		auto focus() const -> const cdouble& { return focus_; }
	};

}