#ifndef FRAME_H
#define FRAME_H

// Initialize ncurses and set up terminal for drawing
void frame_start(void);

// Initialize the frame dimensions
void frame_init(int width, int height);

// move cursor
void moveCursor(int row, int col);

struct Block {
        int x;
        int y;
};

void animatePiece(int WIDTH, int HEIGHT, struct Block *b);
// Clear the screen (virtual screen)
void frame_clear(void);

// Draw the frame (borders + empty inside)
void frame_draw(void);

// End ncurses mode and restore terminal
void frame_end(void);

#endif // FRAME_H
