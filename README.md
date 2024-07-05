# README.md for Maze 3D Game

Welcome to the Maze 3D  project! This repository contains the source code for a raycasting-based 3D game implemented in C using the SDL library. Below is an overview of each file in the project, explaining its purpose and the functions it contains.

## File Summaries

### main.c
- **Purpose**: Serves as the entry point of the program and orchestrates the game loop.
- **Functions**: 
  - `main`
  - `setupGame`
  - `updateGame`
  - `renderGame`
  - `destroyGame`

### window.h
- **Purpose**: Manages window initialization and destruction using SDL.
- **Functions**: 
  - `initializeWindow`
  - `destroyWindow`

### input.c
- **Purpose**: Handles user input, including keyboard events.
- **Functions**: 
  - `handleInput`
  - `handleKeyDown`
  - `handleKeyUp`

### walls.c
- **Purpose**: Handles rendering walls and managing wall textures.
- **Functions**: 
  - `loadWallTextures`
  - `freeWallTextures`
  - `renderWalls`
  - `adjustColorIntensity`

### floor.c
- **Purpose**: Handles rendering the floor projection and managing floor textures.
- **Functions**: 
  - `loadFloorTextures`
  - `freeFloorTextures`
  - `renderFloor`

### ceiling.c
- **Purpose**: Handles rendering the ceiling projection and managing ceiling textures.
- **Functions**: 
  - `loadCeilingTextures`
  - `freeCeilingTextures`
  - `renderCeiling`

### color_buffer.c
- **Purpose**: Manages the color buffer for rendering.
- **Functions**: 
  - `clearColorBuffer`
  - `renderColorBuffer`

### draw.c
- **Purpose**: Provides drawing functions like drawing pixels, lines, and rectangles.
- **Functions**: 
  - `drawPixel`
  - `drawLine`
  - `drawRect`

### player.c
- **Purpose**: Manages the player's position, movement, and rotation.
- **Functions**: 
  - `initializePlayer`
  - `renderPlayer`
  - `movePlayer`

### rays.c
- **Purpose**: Handles raycasting for rendering 3D environments in 2D. These functions work together to cast rays, detect intersections with walls, and calculate distances, allowing for accurate rendering of the game environment.
- **Functions**: 
  - `castRay`
  - `castAllRays`
  - `distanceBetweenPoints`
  - `renderRays`
  - `vertIntersection`
  - `horzIntersection`
  - `isRayFacingDown`
  - `isRayFacingUp`
  - `isRayFacingRight`
  - `isRayFacingLeft`
  - `calculateHorizontalIntercept`
  - `checkHorizontalWallCollision`
  - `calculateVerticalIntercept`
  - `checkVerticalWallCollision`

### rain.c
- **Purpose**: Manages rendering raindrops and updating their positions.
- **Functions**: 
  - `initializeRaindrops`
  - `updateRaindrops`
  - `renderRaindrops`

### upng.h
- **Purpose**: Provides functionality for handling PNG image files.
- **Functions**: Various functions for loading PNG images.

### collision.h
- **Purpose**: Provides collision detection functionality.
- **Functions**: 
  - `DetectCollision`

### map.h
- **Purpose**: Handles rendering and managing the game map.
- **Functions**: 
  - `isInsideMap`
  - `getMapValue`
  - `renderMap`

### weapon.h
- **Purpose**: Manages weapon textures and rendering.
- **Functions**: 
  - `renderWeapon`

## How to Run the Game

1. Clone the repository:
   ```sh
   git clone https://github.com/normancolon/maze_project.git
   cd maze_project
   ```

2. Compile the project:
   ```sh
   gcc -g src/*.c -lm -lSDL2 -lSDL2_image -o maze_game
   ```

3. Run the game:
   ```sh
   ./maze_game
   ```

## Contributing

Feel free to explore and contribute to this Maze 3D Game project! If you have any questions or suggestions, please don't hesitate to reach out.

## Author

This project is maintained by Norman Colon. You can find more of his work on [GitHub](https://github.com/normancolon).


