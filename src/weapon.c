#include "../headers/weapon.h"

extern int currentWeaponIndex;
extern bool isWeaponVisible;
extern const char *weaponFiles[];

/**
 * renderWeapon - render the weapon texture
 */
void renderWeapon(void) {
    if (!isWeaponVisible)
        return;

    SDL_Surface *loadedSurface = IMG_Load(weaponFiles[currentWeaponIndex]);
    if (!loadedSurface) {
        printf("Failed to load weapon texture: %s\n", IMG_GetError());
        return;
    }

    uint32_t weaponWidth = loadedSurface->w;
    uint32_t weaponHeight = loadedSurface->h;

    int weaponX = (WINDOW_WIDTH - 200) / 2;
    int weaponY = WINDOW_HEIGHT - 270;

    SDL_Rect weaponRect = {weaponX, weaponY, weaponWidth, weaponHeight};

    SDL_Texture *weaponTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (!weaponTexture) {
        printf("Failed to create weapon texture: %s\n", SDL_GetError());
        SDL_FreeSurface(loadedSurface);
        return;
    }

    SDL_RenderCopy(renderer, weaponTexture, NULL, &weaponRect);
    SDL_DestroyTexture(weaponTexture);
    SDL_FreeSurface(loadedSurface);
}

