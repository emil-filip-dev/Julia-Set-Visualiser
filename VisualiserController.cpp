#include "VisualiserController.h"

namespace JuliaSetVisualiser 
{
    void VisualiserController::render(Bitmap^ image, bool useCPU) 
    {
        uint32_t w, h;
        w = image->Width;
        h = image->Height;
        uint32_t dataLength = w * h;

        if (pixelBuffer.capacity() != dataLength) {
            pixelBuffer.resize(dataLength);
        }

        juliaSet_->render(pixelBuffer, w, h, renderIterations, useCPU);

        for (int i = 0; i < w * h; i++) {
            image->SetPixel(i / h, i % h, Color::FromArgb(pixelBuffer[i]));
        }
    }
}