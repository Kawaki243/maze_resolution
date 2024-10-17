# Maze Generator and Solver

This project is a maze generator and solver written in C. It allows you to create mazes of various sizes, display them in ASCII, and check if there is a path from the entrance to the exit.

**--> WORKING PROGRESS <--**

<hr>

## Project Structure

├── include/  
│   ├── maze.h  
│   └── maze_generator.h 
|   └── path_finding.h 
├── src/  
│   ├── main.c  
│   ├── maze.c  
│   ├── maze_generator.c  
│   └── path_finding.c  
└── tests/  
│   └── test_maze.c  
├── LICENSE  
├── .gitignore  
├── makefile  

<hr>

## Compilation

To compile the project, use `make`:
```bash
>  make
```
If you want compile and try with 50 x 50 maze, use :
```bash
>  make test_laby
```

This will generate the `maze` executable in the `bin` directory.

<hr>

## Execution

To run the maze generator, use the following command:
```bash
>  ./bin/maze <width> <height>
```

<hr>

## Tests

To run the unit tests, use `make test`:
```bash
>  make test
```

This will compile and run the tests defined in `tests/test_maze.c`.

<hr>

## Screenshots

![Maze Example](https://raw.githubusercontent.com/Kylian-Project/Maze-Problem/refs/heads/main/dist/maze_ex.png?token=GHSAT0AAAAAACYRCR6YJQQQYZ4OTG5DSLBWZYKLMWA)

<hr>

## Features

- **Maze Generation**: The project generates mazes using a recursive division method.
- **ASCII Display**: The generated mazes are displayed in ASCII.
- **Maze Solving**: Working progress...

<hr>

## TODO

- Improve the generation algorithm to create more complex mazes.
- Implement solving algorithm for mazes.
- Add additional unit tests to cover more cases.
- (Add a graphical interface to display the mazes, for fun ^^).

<hr>

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
