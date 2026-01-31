#include <stdio.h>
#include <unistd.h> // For usleep()

#define WIDTH 10
#define HEIGHT 20

// Function to move the cursor to (row, col)
void moveCursor(int row, int col) {
    printf("\033[%d;%dH\e[?25l", row, col);
}

// Function to draw the empty grid/frame
void drawFrame() {
    // Top border
    printf("+");
    for(int i = 0; i < WIDTH; i++) printf("-");
    printf("+\n");

    // Middle rows
    for(int i = 0; i < HEIGHT; i++) {
        printf("|");
        for(int j = 0; j < WIDTH; j++) {
            printf(" "); // empty space inside the grid
        }
        printf("|\n");
    }

    // Bottom border
    printf("+");
    for(int i = 0; i < WIDTH; i++) printf("-");
    printf("+\n");
}

// Example: move a "piece" inside the grid
void animatePiece() {
    int pieceRow = 1;
    int pieceCol = WIDTH / 2;

    for(pieceRow = 1; pieceRow < HEIGHT; pieceRow++) {
        // Move cursor to the start of the grid inside
        moveCursor(2 + pieceRow, 2 + pieceCol);
        printf("O"); // print the piece
	fflush(stdout);

        // Pause so we can see it
        usleep(200000); // 200 ms

        // Erase the piece for the next frame
        moveCursor(2 + pieceRow, 2 + pieceCol);
        printf(" ");
        fflush(stdout);
    }
}

int main() {
    // Clear the screen first
    printf("\033[2J");
    drawFrame();

    // Animate a piece falling down
    while (1==1){
	    animatePiece();
    }

    // Move cursor below the frame after finishing
    moveCursor(HEIGHT + 4, 0);
    return 0;
}
