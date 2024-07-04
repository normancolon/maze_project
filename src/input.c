#include "../headers/input.h"

/**
 * handleInput - Function to handle user input events
 */
void handleInput(void)
{
    SDL_Event event;

    /* Process each event in the event queue */
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            /* Quit event: Exit the game */
            GameRunning = false;
            break;
        case SDL_KEYDOWN:
            /* Keydown event: Handle key press */
            handleKeyDown(event.key.keysym.sym);
            break;
        case SDL_KEYUP:
            /* Keyup event: Handle key release */
            handleKeyUp(event.key.keysym.sym);
            break;
        }
    }

    /* Check if 'R' key is pressed to toggle rain effect */
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
    if (keyboardState[SDL_SCANCODE_R])
        isRaining = !isRaining; /* Toggle rain effect on/off */
}

/**
 * handleKeyDown - Function to handle key press events
 * @key: SDL_Keycode key that was pressed
 */
void handleKeyDown(SDL_Keycode key)
{
    switch (key)
    {
    case SDLK_ESCAPE:
        /* Escape key: Exit the game */
        GameRunning = false;
        break;
    case SDLK_UP:
    case SDLK_w:
        /* Movement keys: Update player's movement direction */
        player.walkDirection = +1;
        break;
    case SDLK_DOWN:
    case SDLK_s:
        player.walkDirection = -1;
        break;
    case SDLK_RIGHT:
    case SDLK_d:
        /* Rotation keys: Update player's turning direction */
        player.turnDirection = +1;
        break;
    case SDLK_LEFT:
    case SDLK_a:
        player.turnDirection = -1;
        break;
    case SDLK_q:
        /* Toggle weapon visibility */
        isWeaponVisible = !isWeaponVisible;
        break;
    case SDLK_TAB:
        /* Cycle through weapons */
        currentWeaponIndex = (currentWeaponIndex + 1) % 5;
        break;
    case SDLK_m:
        /* Toggle mini-map visibility */
        isMiniMapVisible = !isMiniMapVisible;
        break;
    }
}

/**
 * handleKeyUp - Function to handle key release events
 * @key: SDL_Keycode key that was released
 */
void handleKeyUp(SDL_Keycode key)
{
    switch (key)
    {
    case SDLK_UP:
    case SDLK_DOWN:
    case SDLK_w:
    case SDLK_s:
        /* Stop player's movement when up or down keys are released */
        player.walkDirection = 0;
        break;
    case SDLK_RIGHT:
    case SDLK_LEFT:
    case SDLK_d:
    case SDLK_a:
        /* Stop player's turning when left or right keys are released */
        player.turnDirection = 0;
        break;
    }
}

