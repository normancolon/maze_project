#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>

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
#include "map.h"

#define FPS 60
#define FRAME_TIME_LENGTH (1000 / FPS)

typedef struct texture_s
{
    int width;
    int height;
    color_t *texture_buffer;
    upng_t *upngTexture;
} texture_t;

void setupGame(void);
void updateGame(void);
void renderGame(void);
void destroyGame(void);

extern bool GameRunning;
extern int TicksLastFrame;
extern bool isMiniMapVisible;
extern bool GameWon;
extern SDL_Texture *winTexture;

#endif /* MAIN_H */

