/* sprite editor 
   by Daan, 5-1-2024
   Code heavily influence by the let's play MS-DOS tutorials by Root42
   see: https://www.youtube.com/playlist?list=PLGJnX2KGgaw2L7Uv5NThlL48G9y4rJx1X
*/

#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <conio.h>
#include "font.h"
#include "vga.h"
#include "vga.c"

unsigned char savedMouseScreen[8][8];

void beep() {
  sound(1000);
  delay(100);
  nosound();
  delay(100);
}

void showMouseCursor() {
  asm {
    mov ax, 0x1		// set mouse cursor shape
    mov cx, 0x1         // shape arrow
    int 0x33
    mov ax, 0x1		// function 0; init mouse driver
    int 0x33            // Mouse interrupt
  }
}

void hideMouseCursor() {
  asm {
    mov ax,0x0002
    int 0x33
  }
}

void showErrorAndTerminate(const char *error_message, const char *location) {
  setTextMode(); // return to text mode
  printf("Fatal error: %s\n", error_message);
  printf("Location: %s\n", location);

  // terminate execution
  exit(1);
}

void setWorkSpace() {
  int i, j, row;
  int x, y, c;

  // Draw the work area for the sprites. One sprite is 32x32
  // in the edit mode, a pixel is 5x5 'real' pixels
  // means we have to reserve a 160x160 workspace
  drawLine(9, 19, 169, 19, 15);
  drawLine(9, 19, 9, 179, 15);
  drawLine(9, 179, 169, 179, 15);
  drawLine(169, 179, 169, 19, 15);

  for (x = 14; x < 168; x += 5) {
    drawLine(x, 20, x, 178, 8);
  }
  for (y = 24; y < 178; y += 5) {
    drawLine(10, y, 168, y, 8);
  }

  // actual representation of the sprite
  drawLine (179, 19, 213, 19, 15);
  drawLine (179, 19, 179, 53, 15);
  drawLine (179, 53, 213, 53, 15);
  drawLine (213, 53, 213, 19, 15);

  // Color picker
  for (i = 0; i <= 16; i++) {
    drawLine (179, 70 + (i * 4), 243, 70 + (i * 4), 15);
    drawLine (179 + (i * 4), 70, 179 + (i * 4), 134, 15);
  }

  // Fill color picker
  for (row = 1; row <= 16; row++) {
    for (i = 0; i < 16; i++) {
      for (j = 0; j <= 2; j++) {
	x = 180 + (i * 4);
	y = 71 + j + ((row - 1) * 4);
	c = (row - 1) * 16 + i;
	drawPixel (VGA_PANE, x, y, c);
	drawPixel (VGA_PANE, x + 1, y, c);
	drawPixel (VGA_PANE, x + 2, y, c);
      }
    }
  }

  // Current color
  drawLine (180, 164, 234, 164, 15);
  drawLine (180, 164, 180, 180, 15);
  drawLine (180, 180, 234, 180, 15);
  drawLine (234, 180, 234, 164, 15);

  // Make labels
  drawString (10, 10, "Workspace", 14);
  drawString (180, 10, "Preview", 14);
  drawString (180, 61, "Colors", 14);
  drawString (180, 154, "Selected", 14);

  // Place buttons
  drawButton (248, 10, "New File");
  drawButton (240, 24, "Load file");
  drawButton (240, 38, "Save file");
  drawButton (256, 66, "Next >>");
  drawButton (256, 80, "<< Prev");
  drawButton (256, 94, "<Play >");
  drawButton (256, 108,"Insert ");
  drawButton (256, 122,"Delete ");
  drawButton (256, 136," Copy  ");
  drawButton (256, 150," Paste ");
  drawButton (280, 182,"Quit");
}

void saveScreen(unsigned int mouseX, unsigned int mouseY) {
  unsigned int x, y;

  for (y = 0; y < 8; y++) {
    for (x = 0; x < 8; x++) {
      savedMouseScreen[x][y] = getPixel(0, (mouseX + x), (mouseY + y));
      //drawPixel(0, (mouseX + x), (mouseY + y), savedMouseScreen[x][y]);
    }
  }

  for (y = 0; y < 8; y++) {
    for (x = 0; x < 8; x++) {
      //drawPixel(0, (mouseX + x), (mouseY + y), (x + 1));
    }
  }

  drawPixel(0, mouseX, mouseY, getPixel(0, mouseX, mouseY));
}

void restoreScreen(unsigned int x, unsigned int y) {
  int dx, dy;

  for (dy = 0; dy < 8; dy++) {
    for (dx = 0; dx < 8; dx++) {
      drawPixel(0, (x + dx), (y + dy), savedMouseScreen[dx][dy]);
    }
  }
}

void getMouseStatus(int *button, int *x, int *y) {
  struct REGPACK reg;
  reg.r_ax = 0x0003;
  intr(0x33, &reg);
  *button = reg.r_bx;
  *x = reg.r_cx;
  *y = reg.r_dx;
  *x /= 2;
}

void drawMouseCursor(unsigned int oldMouseX, unsigned int oldMouseY,
		     unsigned int mouseX, unsigned int mouseY) {
  int x, y;
  unsigned char mask = 0x80;

  waitForRetrace();
  restoreScreen(oldMouseX, oldMouseY);
  saveScreen(mouseX, mouseY);
  waitForRetrace();
  for (y = 0; y <= 7; y++) {
    for (x = 0; x <= 7; x++) {
//      if (mouse_cursor[y] & (1 << x)) {
//	drawPixel(VGA_PANE, mouseX + (7 - x), mouseY + y, 15);
      if (mouse_cursor[y] & (mask >> x)) {
	drawPixel(0, (mouseX + x), (mouseY + y), 15);
      }
    }
  }

}

int main(int argc, char** argv[]) {
  int x, y;
  int mouseX, mouseY, mouseButton;
  int oldMouseX, oldMouseY;
  int prevMouseButton, animationDrawn;

  // Initialise values
  prevMouseButton = 0;
  animationDrawn = 0;
  oldMouseX = 0;
  oldMouseY = 0;

  // This code is here to prevent warnings for not using argc, argv in the
  // compiler
  if (argc > 2) {
    printf("%s\n", argv[1]);
  }

  setGraphicsMode(); // Switch to 320x200x256
  setWorkSpace(); // set-up workspace

  // Initial mouse routines; save background etc.
  getMouseStatus(&mouseButton, &mouseX, &mouseY);

  saveScreen(mouseX, mouseY);
  oldMouseX = mouseX;
  oldMouseY = mouseY;

  // Main program loop
  while (!kbhit()) {
    getMouseStatus(&mouseButton, &mouseX, &mouseY);
    if ((mouseX != oldMouseX) || (mouseY != oldMouseY)) {
      // Mouse position changed
      drawMouseCursor(oldMouseX, oldMouseY, mouseX, mouseY);
      oldMouseX = mouseX;
      oldMouseY = mouseY;
    }

    if (mouseButton != prevMouseButton) {
      // Check if something needs to be animated
      if ((mouseButton == 1) && (animationDrawn == 0)) {
	if ((mouseX >= 280) && (mouseY >= 182)) {
	  // Animate 'quit' button
	  drawPushedButton(280, 182, "Quit");
	  animationDrawn= 1;
	}
      }
      // Action on the release of the button
      if (mouseButton == 0) {		// indicates release
	if ((mouseX >= 280) && (mouseY >= 182)) {
	  break; //quit pressed
	}
      }
      prevMouseButton = mouseButton;
    }
  } // main program loop

  hideMouseCursor();
  setTextMode();

  printf("\n\nHave a happy DOS!\n");

  return 0;
}