# Maze Project

## Overview

The Maze Project is a simple 2D maze game built using C and the SDL2 library. The game features texture mapping, collision detection, and player movement within a maze environment.

## Features

- 2D maze rendering
- Player movement
- Collision detection
- Texture mapping for walls
- Minimap rendering

## Installation

### Prerequisites

- SDL2 library
- SDL2_image library

### Building the Project

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/maze_project.git
    cd maze_project
    ```

2. Install the required libraries (Linux):
    ```bash
    sudo apt-get install libsdl2-dev libsdl2-image-dev
    ```

3. Compile the project:
    ```bash
    gcc -Wall -Werror -Wextra -pedantic ./src/*.c -lm -o maze `sdl2-config --cflags` `sdl2-config --libs`
    ```

## Usage

Run the compiled executable:
```bash
./maze

File Structure
css
Copy code
maze_project/
├── hdrs/
│   ├── h.h
│   └── upng.h
├── img/
│   ├── redbrick.png
│   ├── purplestone.png
│   ├── mossystone.png
│   ├── graystone.png
│   ├── colorstone.png
│   ├── bluestone.png
│   ├── wood.png
│   └── eagle.png
├── src/
│   ├── main.c
│   ├── texture.c
│   ├── wall.c
│   ├── player.c
│   ├── map.c
│   └── draw.c
└── README.md
Dependencies
SDL2: Simple DirectMedia Layer library for 2D graphics
SDL2_image: Image file loading library for SDL2
