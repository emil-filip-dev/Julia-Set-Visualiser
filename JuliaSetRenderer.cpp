#include "JuliaSetRenderer.h"

namespace JuliaSetVisualiser {

	void JuliaSetRenderer::render(JuliaSet* ptr_set) {
		Brush^ b = gcnew SolidBrush(Color::Red);
		ptr_graphics_->FillRectangle(b, 0, 0, 100, 100);
	}
}