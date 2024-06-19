#include "../hdrs/h.h"

// Define the wallTextures array
texture_t wallTextures[NUM_TEXTURES];

static const char *textureFileNames[NUM_TEXTURES] = {
    "./img/redbrick.png",
    "./img/purplestone.png",
    "./img/mossystone.png",
    "./img/graystone.png",
    "./img/colorstone.png",
    "./img/bluestone.png",
    "./img/wood.png",
    "./img/eagle.png"};

/**
 * WallTexturesready - load textures in the respective position
 */
void WallTexturesready(void)
{
    int i;

    for (i = 0; i < NUM_TEXTURES; i++)
    {
        upng_t *upng = upng_new_from_file(textureFileNames[i]);

        if (upng != NULL)
        {
            upng_decode(upng);
            if (upng_get_error(upng) == UPNG_EOK)
            {
                wallTextures[i].upngTexture = upng;
                wallTextures[i].width = upng_get_width(upng);
                wallTextures[i].height = upng_get_height(upng);
                wallTextures[i].texture_buffer = (color_t *)upng_get_buffer(upng);
            }
        }
    }
}

/**
 * freeWallTextures - free wall textures
 */
void freeWallTextures(void)
{
    int i;

    for (i = 0; i < NUM_TEXTURES; i++)
    {
        upng_free(wallTextures[i].upngTexture);
    }
}
