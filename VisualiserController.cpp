#include "VisualiserController.h"
#include "AcceleratedCalculator.h"

//#define MAX_ITERATIONS 76
#define MAX_ITERATIONS 76

namespace JuliaSetVisualiser {

    void VisualiserController::render(Bitmap^ image, bool useCPU) {
        int w, h;
        w = image->Width;
        h = image->Height;

        uint32_t* colours = new uint32_t[w * h];

        juliaSet_->render(colours, w, h, useCPU);

        uint32_t colour;
        for (int i = 0; i < w * h; i++) {
            image->SetPixel(i / h, i % h, Color::FromArgb(colours[i]));
        }

        delete colours;
    }
}