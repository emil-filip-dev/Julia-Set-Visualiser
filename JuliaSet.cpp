#include "JuliaSet.h"
#include <cmath>

namespace JuliaSetVisualiser {

	bool JuliaSet::isInSet(complex<double> num, int maxIterations, int* iterations) {
		int i = 0;
		complex<double> n = num;
		for (; real(n * conj(n)) < pow(r_, 2); i++) {
			n = pow(n, 2) + c_;
		}
		*iterations = i;
		return i == maxIterations;
	}

}