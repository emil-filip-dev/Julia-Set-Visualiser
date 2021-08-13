#pragma once
#include "JuliaSet.h"

using namespace System::Drawing;

namespace JuliaSetVisualiser {

	public class JuliaSetRenderer {

	public:
		JuliaSetRenderer(JuliaSet* juliaSet) : juliaSet_(juliaSet) {}

		void render(Bitmap^ image);

		void changeZoom(double amount) { 
			zoomFactor_ += amount; 
		}

	private:
		JuliaSet* juliaSet_;
		double zoomFactor_ = 0.0;
		complex<double> focus_ = complex<double>(0.0, 0.0);
	};
}