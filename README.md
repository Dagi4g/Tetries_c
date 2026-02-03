# Terminal Tetris (C, ncurses)

A simple terminal-based Tetris-like program written in C using ncurses.

This project is for learning:
- terminal screen control
- non-blocking keyboard input
- basic game loops
- state-based rendering

---

## Description

The program runs inside a terminal and uses ncurses to:
- control cursor position
- draw a frame and game elements
- read keyboard input without echo
- update the screen without scrolling

All screen output is handled through ncurses.  
No `printf`, ANSI escape codes, or standard output rendering is used during gameplay.

---

## Requirements

- C compiler (`gcc` or `clang`)
- ncurses library

### Linux (Debian/Ubuntu)
```bash
sudo apt install libncurses-dev

# build

```bashe
gcc main.c frame.c -lncurses -o tetris



