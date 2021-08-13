#include "JuliaSetRenderer.h"

#define MAX_ITERATIONS 76

namespace JuliaSetVisualiser {

    void JuliaSetRenderer::render(Bitmap^ image) {
        int w, h;
        w = image->Width;
        h = image->Height;

        int iterations = 0;
        float ratio = 0;
        int color = 0;
        for (int i = 0; i < image->Width; i++) {
            for (int j = 0; j < image->Height; j++) {
                color = 0xFF000000;
                if (juliaSet_->isInSet(complex<double>(1 * juliaSet_->r() * (i - w / 2) / (double)w,
                                                       1 * juliaSet_->r() * (j - h / 2) / (double)h),
                                       MAX_ITERATIONS,
                                       &iterations)) {
                    color = 0xFF000000;
                } else {
                    ratio = (float)iterations / (float)MAX_ITERATIONS;
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
                image->SetPixel(i, j, Color::FromArgb(color));
            }
        }
    }
}