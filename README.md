# Game of Life

The Game of Life is a cellular automaton devised by the British mathematician John Horton Conway in 1970. It consists of a grid of cells, which can be either alive or dead. Each cell interacts with its eight neighbors, and the state of the grid evolves over time according to a set of simple rules.

This C++ implementation of the Game of Life creates a randomly seeded grid and displays the evolution of the grid in the terminal until a stable state is reached.

## Requirements

- C++ compiler
- Terminal with ANSI escape code support (for moving the cursor)

## How to Compile

```sh
g++ game-of-life.cpp -o game_of_life
```
or
```sh
clang++ game-of-life.cpp -o game_of_life
```
or, simply,
```sh
make
```
