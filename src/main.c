#include <stdio.h>
#include "frame/frame.h"
#include <unistd.h> // For usleep()
#include <stdbool.h>

#define WIDTH 30
#define HEIGHT 20


int main() {
    // Clear the screen first
    

    // Animate a piece falling down
    while (true){
	    frame_start();
	    frame_init(WIDTH, HEIGHT);
	    
	    frame_clear();
	    frame_draw();
	    animatePiece(WIDTH, HEIGHT);
	    moveCursor(HEIGHT + 4,0);
	    
} return 0;
    }

