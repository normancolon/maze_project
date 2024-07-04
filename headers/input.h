#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "main.h"

/* Function prototypes */
void handleInput(void);
void handleKeyDown(SDL_Keycode key);
void handleKeyUp(SDL_Keycode key);

#endif /* INPUT_H */

