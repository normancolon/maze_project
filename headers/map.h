#ifndef MAP_H
#define MAP_H

#include <stdbool.h>
#include "draw.h"

#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20
#define TILE_SIZE 50

#define MINIMAP_SCALE_FACTOR 0.25

/* Define the coordinates of the winning square */
#define WINNING_ROW 10
#define WINNING_COL 15

/* External variable declaration */
extern const int map[MAP_NUM_ROWS][MAP_NUM_COLS];

/* Function prototypes */
bool isInsideMap(float x, float y);
int getMapValue(int row, int col);
void renderMap(void);
void checkWinCondition(void);

#endif /* MAP_H */

