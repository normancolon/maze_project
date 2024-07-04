#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdbool.h>

#include "window.h"
#include "rain.h"
#include "walls.h"
#include "ceiling.h"
#include "floor.h"
#include "weapon.h"
#include "color_buffer.h"
#include "input.h"
#include "player.h"
#include "enemy.h"

/* Constants */
#define FPS 60
#define FRAME_TIME_LENGTH (1000 / FPS)

/**
 * struct texture_s - struct for textures
 * @width: texture width
 * @height: texture height
 * @texture_buffer: buffer for texture data
 * @upngTexture: PNG texture
 */
typedef struct texture_s
{
    int width;
    int height;
    color_t *texture_buffer;
    upng_t *upngTexture;
} texture_t;

/* Function prototypes */
void setupGame(void);
void updateGame(void);
void renderGame(void);
void destroyGame(void);

/* External variable declarations */
extern bool GameRunning;
extern int TicksLastFrame;
extern bool isMiniMapVisible;

#endif /* MAIN_H */

