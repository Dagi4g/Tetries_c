#include <stdio.h>
#include "frame/frame.h"
#include <unistd.h> // For usleep()
#include <stdbool.h>

#define WIDTH 30
#define HEIGHT 20


int main() {
    // Clear the screen first
    struct Block b = {WIDTH/2,1};

    frame_start();
    frame_init(WIDTH, HEIGHT);
    
    frame_clear();
    // Animate a piece falling down
    while (true){

	    frame_draw();
	    animatePiece(WIDTH, HEIGHT,&b);
	    moveCursor(HEIGHT + 4,0);
	    
} return 0;
    }

