#pragma once

#include <complex>

using namespace std;

namespace JuliaSetVisualiser {

	class JuliaSet {
	public:
		explicit JuliaSet(double c, double r) : c_(c), r_(r) {}

		double c() { return c_; }
		double r() { return r_; }

		bool isInSet(complex<double> num, int maxIterations, int* iterations);

	private:
		double c_;
		double r_;
	};

}