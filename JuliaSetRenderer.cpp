#include "JuliaSetRenderer.h"

//#define MAX_ITERATIONS 76
#define MAX_ITERATIONS 10

namespace JuliaSetVisualiser {

    void JuliaSetRenderer::render(Bitmap^ image) {
        int w, h;
        w = image->Width;
        h = image->Height;

        double r = juliaSet_->r();

        if (zoomFactor_ == 0.0) {
            zoomFactor_ = 2 * r / min(w, h);
        }

        int iterations = 0;
        double ratio = 0;
        int color = 0;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                color = 0xFF000000;
                if (juliaSet_->isInSet(focus_ + complex<double>((double)(i - w / 2) * zoomFactor_, (double)(j - h / 2) * zoomFactor_),
                                       MAX_ITERATIONS,
                                       &iterations)) {
                    color = 0xFF000000;
                } else {
                    ratio = (double)iterations / (double)MAX_ITERATIONS;
                    ratio = 1.0 - abs(ratio - 0.5) / 0.5;
                    if (ratio < 0.25) {
                        color = 0xFF0000FF | (int)(0xFF * ((ratio - 0.0f) / 0.25f)) << 8;
                    }
                    else if (ratio < 0.5) {
                        color = 0xFF00FF00 | ((int)(0xFF * ((ratio - 0.25f) / 0.25f)) << 16) | (int)(0xFF * ((0.5f - ratio) / 0.25f));
                    }
                    else if (ratio < 0.75) {
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