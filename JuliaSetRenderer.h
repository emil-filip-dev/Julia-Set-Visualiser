#pragma once
#include "JuliaSet.h"

using namespace System::Drawing;

namespace JuliaSetVisualiser {

	public ref class JuliaSetRenderer {

	public:
		JuliaSetRenderer(JuliaSet* juliaSet) : juliaSet_(juliaSet) {}

		void render(Bitmap^ image);

	private:
		JuliaSet* juliaSet_;
	};
}