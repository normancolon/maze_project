#include "../headers/main.h"
#include "../headers/weapon.h"
#include "../headers/enemy.h"
#include "../headers/player.h"
#include "../headers/map.h"

bool GameRunning = false;
bool GameWon = false;
int TicksLastFrame;
bool isMiniMapVisible = true;

SDL_Texture *winTexture = NULL;

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
        if (!GameWon) {
            updateGame();
        }
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

    initializeEnemy(400, 400);

    SDL_Surface *winSurface = IMG_Load("./images/2bw1030.png");
    if (!winSurface) {
        printf("Failed to load win image: %s\n", IMG_GetError());
        GameRunning = false;
    } else {
        winTexture = SDL_CreateTextureFromSurface(renderer, winSurface);
        SDL_FreeSurface(winSurface);
    }
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
    if (GameWon) {
        SDL_Rect winRect = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};
        SDL_RenderCopy(renderer, winTexture, NULL, &winRect);
        SDL_RenderPresent(renderer);
        return;
    }

    clearColorBuffer(0xFF000000);
    renderWalls();
    if (isMiniMapVisible) {
        renderMap();
        renderRays();
        renderPlayer();
    }
    renderEnemy();
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
    if (winTexture) {
        SDL_DestroyTexture(winTexture);
    }
    freeWallTextures();
    freeCeilingTextures();
    freeFloorTextures();
    freeEnemyTexture();
    destroyWindow();
}

