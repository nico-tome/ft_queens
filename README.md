# ft_queens

A fast and elegant **N-Queens puzzle solver** written in C, featuring visual board representation and algebraic notation output.

## Overview

The N-Queens problem is a classic combinatorial puzzle: place N queens on an N×N chessboard such that no two queens attack each other (no shared rows, columns, or diagonals). This solver finds all possible solutions using backtracking with constraint checking.

## Features

**Fast Backtracking Algorithm** - Efficient constraint satisfaction using diagonal and column checking  
**Beautiful Output** - Colored chessboard visualization with queen symbols  
**Algebraic Notation** - Solutions in standard chess notation (e.g., A8;B6;C4;D2)  
**Low Overhead** - Minimal memory footprint, pure C implementation  
**Makefile Build System** - Professional build configuration with colored output

## Installation

### Prerequisites
- GCC or Clang compiler
- GNU Make
- Standard C libraries

### Build

```bash
make            # Build the project
make clean      # Remove object files
make fclean     # Remove all generated files
make help       # Display available targets
