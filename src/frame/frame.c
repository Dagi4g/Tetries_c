#include <ncurses.h>
#include <unistd.h>
#include "frame.h"

static int frame_width;
static int frame_height;


// Initialize ncurses
void frame_start(void) {
    initscr();        // start curses mode
    noecho();         // do not print typed keys
    cbreak();         // disable line buffering
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);      // hide cursor


}

// Initialize frame size
void frame_init(int width, int height) {
    frame_width = width;
    frame_height = height;
}

// Clear the frame
void frame_clear(void) {
    clear();          // clear the virtual screen
}

// Move cursor
void moveCursor(int row, int col){
	move(row , col);
}


// Draw the frame
void frame_draw(void) {
    int x, y;

    // Draw top border
    mvaddch(0, 0, '+');
    for (x = 1; x <= frame_width; x++)
        mvaddch(0, x, '-');
    mvaddch(0, frame_width + 1, '+');

    // Draw side borders and empty inside
    for (y = 1; y <= frame_height; y++) {
        mvaddch(y, 0, '|');                     // left border
        for (x = 1; x <= frame_width; x++)
            mvaddch(y, x, ' ');                // inside space
        mvaddch(y, frame_width + 1, '|');       // right border
    }

    // Draw bottom border
    mvaddch(frame_height + 1, 0, '+');
    for (x = 1; x <= frame_width; x++)
        mvaddch(frame_height + 1, x, '-');
    mvaddch(frame_height + 1, frame_width + 1, '+');

    refresh(); // push changes to the terminal
}
void animatePiece(int WIDTH,int HEIGHT , struct Block *p) {
    int ch;

    while (p->y < HEIGHT-1) {
        // --- INPUT ---
        ch = getch();          // non-blocking
        if (ch == 'j') {
            if (p->x > -1)  // prevent crossing left wall
                p->x--;
        }
	else if (ch == 'k') {
		if (p->x < WIDTH-2){
			p->x ++;
		}
	}

        // --- DRAW ---
        mvaddch(2 + p->y, 2 + p->x ,'#');

        refresh();

        // --- DELAY (gravity tick) ---
        usleep(300000); // 200 ms

        // --- ERASE OLD POSITION ---
        mvaddch(2 + p->y, 2 + p->x, ' ');

        // --- UPDATE STATE ---
        p->y ++;
    }
    p->y = 1;
    p->x = WIDTH/2;
}
// End curses mode (restore terminal)
void frame_end(void) {
    endwin();
}
