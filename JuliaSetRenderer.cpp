#include "JuliaSetRenderer.h"

namespace JuliaSetVisualiser {

	void JuliaSetRenderer::render(JuliaSet* juliaSet) {
		int width = graphics_->VisibleClipBounds.Width;
		int height = graphics_->VisibleClipBounds.Height;
		Bitmap^ img = gcnew Bitmap(width, height);

		int maxIterations = 76;
		int iterations = 0;
		float ratio = 0;
		int color = 0;
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				color = 0xFF000000;
				if (juliaSet->isInSet(complex<double>(1 * juliaSet->r() * (i - width / 2) / (double)width,
					              		     	      1 * juliaSet->r() * (j - height / 2) / (double)height),
									  maxIterations,
									  &iterations)) {
					color = 0xFF000000;
				} else {
					ratio = (float)iterations / (float)maxIterations;
					ratio = 1.0 - abs(ratio - 0.5f) / 0.5f;
					if (ratio < 0.25f) {
						color = 0xFF0000FF | (int)(0xFF * ((ratio - 0.0f) / 0.25f)) << 8;
					}
					else if (ratio < 0.5f) {
						color = 0xFF00FF00 | ((int)(0xFF * ((ratio - 0.25f) / 0.25f)) << 16) | (int)(0xFF * ((0.5f - ratio) / 0.25f));
					}
					else if (ratio < 0.75f) {
						color = 0xFFFF0000 | (int)(0xFF * ((0.75f - ratio) / 0.25f)) << 8;
					}
					else {
						color = 0xFF000000 | (int)(0xFF * (0.5f + (1.0f - ratio) / 0.5f)) << 16;
					}
				}
				img->SetPixel(i, j, Color::FromArgb(color));
			}
		}
		graphics_->DrawImageUnscaled(img, 0, 0);
	}
}