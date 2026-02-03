Terminal Tetris (C, ncurses)

A simple terminal-based Tetris-like program written in C using ncurses.

This project is for learning:

terminal screen control

non-blocking keyboard input

basic game loops

state-based rendering



---

Description

The program runs inside a terminal and uses ncurses to:

control cursor position

draw a frame and game elements

read keyboard input without echo

update the screen without scrolling


All screen output is handled through ncurses.
No printf, ANSI escape codes, or standard output rendering is used during gameplay.


---

Requirements

C compiler (gcc or clang)

ncurses library


Linux (Debian/Ubuntu)

sudo apt install libncurses-dev

macOS

brew install ncurses

Windows

Use WSL, or

Use PDCurses (ncurses-compatible)



---

Build

gcc main.c frame.c -lncurses -o tetris

Run:

./tetris

The program must be run from a terminal.


---

Controls

(Current implementation)

j : move piece left


More controls will be added later.


---

Project Structure

.
├── main.c      // main loop, input handling
├── frame.c     // frame drawing with ncurses
├── frame.h
└── README.md


---

Notes

The terminal is treated as a 2D grid

The game redraws the screen each frame

Input is non-blocking

Cursor visibility is disabled during runtime

The terminal state is restored on exit



---

Status

Work in progress.
Focus is on correctness and understanding, not completeness.


---

If you want, I can make an even more stripped-down version (almost man-page style), or adjust it to match how Linux CLI tools document themselves.
