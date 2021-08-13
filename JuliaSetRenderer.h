#pragma once
#include "JuliaSet.h"

using namespace System::Drawing;

namespace JuliaSetVisualiser {

	public ref class JuliaSetRenderer {

	public:
		JuliaSetRenderer(Graphics^ ptr_graphics) : ptr_graphics_(ptr_graphics) {}

		void render(JuliaSet* set);

	private:
		Graphics^ ptr_graphics_;
	};
}