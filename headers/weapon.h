#ifndef WEAPON_H
#define WEAPON_H

#include <SDL2/SDL_image.h>
#include "window.h"

/* Function prototypes */
void renderWeapon(void);

/* Declare external variables */
extern bool isWeaponVisible;
extern int currentWeaponIndex;
extern const char *weaponFiles[];

#endif /* WEAPON_H */

