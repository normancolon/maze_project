#include "../headers/enemy.h"
#include "../headers/window.h"
#include <SDL2/SDL_image.h>

Enemy enemy;

void loadEnemyTexture(void)
{
    SDL_Surface *loadedSurface = IMG_Load("./images/enemy1.png");
    if (!loadedSurface) {
        printf("Failed to load enemy texture: %s\n", IMG_GetError());
        return;
    }

    /* Enable transparency for the texture */
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 0, 255));  /* Adjust the RGB value to match the transparency color */

    enemy.texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (!enemy.texture) {
        printf("Failed to create texture from surface: %s\n", SDL_GetError());
    } else {
        printf("Enemy texture loaded successfully\n");
    }

    enemy.width = loadedSurface->w;
    enemy.height = loadedSurface->h;

    SDL_FreeSurface(loadedSurface);
}

void initializeEnemy(float x, float y)
{
    enemy.x = x;
    enemy.y = y;
    printf("Enemy initialized at position (%f, %f)\n", enemy.x, enemy.y);
}

void renderEnemy(void)
{
    SDL_Rect enemyRect = { (int)enemy.x, (int)enemy.y, enemy.width, enemy.height };
    SDL_RenderCopy(renderer, enemy.texture, NULL, &enemyRect);
    printf("Rendering enemy at position (%d, %d) with size (%d, %d)\n", (int)enemy.x, (int)enemy.y, enemy.width, enemy.height);
}

void freeEnemyTexture(void)
{
    SDL_DestroyTexture(enemy.texture);
}

