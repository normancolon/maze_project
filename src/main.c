#include "../headers/main.h"
#include "../headers/weapon.h"
#include "../headers/enemy.h"

bool GameRunning = false;
int TicksLastFrame;
bool isMiniMapVisible = true;

int currentWeaponIndex = 0;
bool isWeaponVisible = true;
const char *weaponFiles[] = {
    "./images/gun1.png",
    "./images/gun2.png",
    "./images/gun3.png",
    "./images/gun5.png",
    "./images/gun6.png"
};

int main(void)
{
    setupGame();

    while (GameRunning) {
        handleInput();
        updateGame();
        renderGame();
        SDL_Delay(10);
    }

    destroyGame();
    return 0;
}

void setupGame(void)
{
    GameRunning = initializeWindow();
    if (!GameRunning) {
        printf("Failed to initialize window\n");
        return;
    }
    initializePlayer();
    initializeRaindrops();

    loadFloorTextures();
    loadCeilingTextures();
    loadWallTextures();
    loadEnemyTexture();

    initializeEnemy(WINDOW_WIDTH / 2 - 84, WINDOW_HEIGHT / 2 - 144); /* Center the enemy */
}

void updateGame(void)
{
    srand(SDL_GetTicks());

    float deltaTime;
    int timeToWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - TicksLastFrame);

    if (timeToWait > 0 && timeToWait <= FRAME_TIME_LENGTH) {
        SDL_Delay(timeToWait);
    }

    deltaTime = (SDL_GetTicks() - TicksLastFrame) / 1000.0f;
    TicksLastFrame = SDL_GetTicks();

    movePlayer(deltaTime);

    castAllRays();
}

void renderGame(void)
{
    clearColorBuffer(0xFF000000);
    renderWalls();
    if (isMiniMapVisible) {
        renderMap();
        renderRays();
        renderPlayer();
    }
    renderEnemy(); /* Render the enemy */
    renderColorBuffer();
    renderWeapon();
    if (isRaining) {
        updateRaindrops();
        renderRaindrops();
    }
    SDL_RenderPresent(renderer);
}

void destroyGame(void)
{
    freeWallTextures();
    freeCeilingTextures();
    freeFloorTextures();
    freeEnemyTexture(); /* Free enemy texture */
    destroyWindow();
}

