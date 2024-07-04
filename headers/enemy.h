#ifndef ENEMY_H
#define ENEMY_H

#include <SDL2/SDL.h>

/**
 * struct Enemy - struct for enemy attributes
 * @x: x coordinate
 * @y: y coordinate
 * @width: enemy width
 * @height: enemy height
 * @texture: enemy texture
 */
typedef struct {
    float x;
    float y;
    int width;
    int height;
    SDL_Texture *texture;
} Enemy;

/* Function prototypes */
void loadEnemyTexture(void);
void initializeEnemy(float x, float y);
void renderEnemy(void);
void freeEnemyTexture(void);

/* External variable declaration */
extern Enemy enemy;

#endif /* ENEMY_H */

