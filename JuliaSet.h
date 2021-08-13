#pragma once

#define _USE_MATH_DEFINES

#include <complex>
#include <cmath>

using namespace std;

namespace JuliaSetVisualiser {

	class JuliaSet {
	public:
		explicit JuliaSet(complex<double> c, double r) : c_(c), r_(r) {}

		complex <double > c() { return c_; }
		double r() { return r_; }

		bool isInSet(complex<double> num, int maxIterations, int* iterations);

	private:
		complex<double> c_;
		double r_;
	};

}