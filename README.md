

# The Maze

The Maze is a game created using the C programming language, SDL2, and the concept of raycasting. On the map, the player can move in all four directions and rotate their field of view. This game includes collision detection on walls and an objective point in yellow on the minimap.

## Installation

Clone this repo:
```bash
git clone git@github.com:normancolon/maze_project.git
```

First, ensure SDL2 is installed. Then execute the following command to compile all the files and create the executable of the game:

```bash
make
```

## Usage

After successfully compiling, run the program using the following command:

```bash
./maze
```

## Controls

- **W** - Move forward
- **S** - Move backward
- **A** - Look left
- **D** - Look right
- **Left arrow** - Turn left
- **Right arrow** - Turn right
- **M** - Enable and disable minimap view
- **Q** - Enable and disable weapon view

***Have fun!***

## Directories

[`src`](https://github.com/normancolon/maze_project/tree/main/src)
- Contains all the source code files written in C.

[`h`](https://github.com/normancolon/maze_project/tree/main/h)
- Contains all the header files.

[`maps`](https://github.com/normancolon/maze_project/tree/main/maps)
- Contains map data files used by the program to output the map layout.

[`img`](https://github.com/normancolon/maze_project/tree/main/images)
- Contains image files.

## Contributing

- Read the source files in the `src` folder and the header files in the `h` folder.
- Clone the repo and make a new branch:
  ```bash
  git checkout -b [name_of_new_branch]
  ```
- Add a feature, fix a bug, or refactor some code :)
- Write/update tests for the changes you made, if necessary.
- Open a Pull Request with a comprehensive description of changes.

## Related

Resources on SDL and Raycasting:
- [SDL2 tutorial](https://lazyfoo.net/tutorials/SDL/index.php)
- [SDL2 Functions](https://wiki.libsdl.org/SDL2/CategoryAPI)
- [Raycasting tutorial 1](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- [Raycasting tutorial 2](https://lodev.org/cgtutor/raycasting.html)

## License

*BSD*

## Author

Norman Colon Cruz <acolon@slc53.com>

