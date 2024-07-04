#include "../headers/color_buffer.h"

/**
 * clearColorBuffer - clear buffer for every frame
 * @color: Color buffer
 */
void clearColorBuffer(color_t color) {
    int i;

    for (i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++) {
        colorBuffer[i] = color;
    }
}

/**
 * renderColorBuffer - render buffer for every frame
 */
void renderColorBuffer(void) {
    SDL_UpdateTexture(colorBufferTexture, NULL, colorBuffer, (int)(WINDOW_WIDTH * sizeof(color_t)));
    SDL_RenderCopy(renderer, colorBufferTexture, NULL, NULL);
}

