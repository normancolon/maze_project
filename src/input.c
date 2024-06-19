#include "../hdrs/h.h"

/**
 * SDL_KEYDOWN_FUNC - process input when a key is down
 * @event: union that contains structures for the different event types
 */
void SDL_KEYDOWN_FUNC(SDL_Event event)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        GameRunning = false;
        break;
    case SDLK_UP:
    case SDLK_w:
        player.walkDirection = +1;
        break;
    case SDLK_DOWN:
    case SDLK_s:
        player.walkDirection = -1;
        break;
    case SDLK_RIGHT:
    case SDLK_d:
        player.turnDirection = +1;
        break;
    case SDLK_LEFT:
    case SDLK_a:
        player.turnDirection = -1;
        break;
    default:
        break;
    }
}

/**
 * SDL_KEYUP_FUNC - process input when a key is up
 * @event: union that contains structures for the different event types
 */
void SDL_KEYUP_FUNC(SDL_Event event)
{
    switch (event.key.keysym.sym)
    {
    case SDLK_UP:
    case SDLK_w:
    case SDLK_DOWN:
    case SDLK_s:
        player.walkDirection = 0;
        break;
    case SDLK_RIGHT:
    case SDLK_d:
    case SDLK_LEFT:
    case SDLK_a:
        player.turnDirection = 0;
        break;
    default:
        break;
    }
}

/**
 * handleInput - process input from the keyboard
 */
void handleInput(void)
{
    SDL_Event event;

    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT)
    {
        GameRunning = false;
    }
    else if (event.type == SDL_KEYDOWN)
    {
        SDL_KEYDOWN_FUNC(event);
    }
    else if (event.type == SDL_KEYUP)
    {
        SDL_KEYUP_FUNC(event);
    }
}
