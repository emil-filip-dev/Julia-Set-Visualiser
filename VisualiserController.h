#pragma once
#include "JuliaSet.h"

using namespace System::Drawing;

namespace JuliaSetVisualiser {

	public class VisualiserController {

		JuliaSet* juliaSet_ = nullptr;

	public:
		VisualiserController() {
			juliaSet_ = new JuliaSet(complex<double>(0.7885, 0) * exp(complex<double>(0, M_PI * 2.0 * 170.0 / 360.0)), 2.0);
		}

		~VisualiserController() {
			delete juliaSet_;
		}

		void render(Bitmap^ image, bool useCPU = false);
	};
}