# Rush01 — Skyscraper Puzzle Solver

A collaborative C project completed during the 42 Singapore Piscine.

## Overview

This program solves a 4 × 4 Skyscraper puzzle using visibility clues provided from all four sides of the grid.

Each row and column must contain the numbers 1 to 4 without repetition. The completed grid must also satisfy all supplied visibility constraints.

## Features

- Parses and validates the puzzle clues
- Constructs and checks the puzzle grid
- Enforces row and column uniqueness
- Evaluates visibility conditions from all four directions
- Prints a valid solution or an error message

## Technologies

- C
- GCC
- Linux command line

## Concepts Applied

- Arrays and pointers
- Input validation
- Constraint checking
- Modular programming
- Debugging
- Team-based software development

## Project Structure

- `border_printsol.c` — handles border processing and solution output
- `input_grid.c` — processes input and initialises the puzzle grid
- `is_in.c` — checks whether values already exist in rows or columns
- `loop.c` — manages the main solving process
- `view.c` — checks visibility constraints
- `remove_header.h` — contains function declarations and shared definitions

## My Contributions

- Contributed to the implementation and integration of the puzzle-solving program
- Assisted with debugging, validation and testing of the grid logic
- Collaborated with teammates to combine individual program components into a working solution

## Contributors

Developed collaboratively during the 42 Singapore Piscine.
