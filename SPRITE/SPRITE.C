/* sprite editor */

#include <stdio.h>
#include <dos.h>
#include <string.h>
#include "font.h"

unsigned char far *videoBuffer = (unsigned char far *)0xA0000000; // video

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

void setGraphicsMode() {
  union REGS inregs, outregs;

  inregs.h.ah = 0; // set video mode function
  inregs.h.al = 0x13; // Mode 13h == 320x200x256
  int86(0x10, &inregs, &outregs); // BIOS call
}

void setTextMode () {
  union REGS inregs, outregs;

  inregs.h.ah = 0; // set video mode
  inregs.h.al = 0x03; // Mode 3h = 80x25 text mode
  int86(0x10, &inregs, &outregs);
}

void showErrorAndTerminate(const char *error_message, const char *location) {
  setTextMode(); // return to text mode
  printf("Fatal error: %s\n", error_message);
  printf("Location: %s\n", location);

  // terminate execution
  exit(1);
}

void drawPixel(int x, int y, unsigned char color) {
  unsigned int offset = y * 320 + x; // calculate offset
  videoBuffer[offset] = color;
}

void drawLetter(char letter, int char_x, int char_y, unsigned char char_color) {
  int x, y;
  unsigned int index;
  index = (int)letter;
  for (y = 0; y <= 7; y++) {
    for (x = 7; x >= 0; x--) {
      if (thin_font[index][y] & (1 << x)) {
	drawPixel(char_x + (6 - x), char_y + y, char_color);
      }
    }
  }
}

void drawString(int x, int y, char *str, unsigned char color) {
  int i;
  for (i = 0; str[i] != 0; i++) {
    drawLetter(str[i], x + (i * 7), y, color);
  }
}


void drawLine(int x1, int y1, int x2, int y2, unsigned char color) {
  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  int sx = x1 < x2 ? 1 : -1;
  int sy = y1 < y2 ? 1 : -1;
  int err = dx - dy;
  int err2;

  while (x1 != x2 || y1 != y2) {
    drawPixel(x1, y1, color);
    err2 = 2 * err;
    if (err2 > -dy) {
      err -= dy;
      x1 += sx;
    }
    if (err2 < dx) {
      err += dx;
      y1 += sy;
    }
  }

  drawPixel(x2, y2, color);
}

void drawButton(int x, int y, char* text) {
  int width, height;
  int i;

  width = ((strlen(text) - 1) * 8) + 10;
  height = 12;
  drawLine(x, y, x + width, y, 15);
  drawLine(x, y, x, y + height, 15);
  drawLine(x + width, y, x + width, y + height, 8);
  drawLine(x + width, y + height, x, y + height, 8);
  for (i = 1; i < height; i++) {
    drawLine((x + 1), (y + i), (x + width - 1), (y + i), 7);
  }
  drawString (x + 3, y  + 3, text, 0);
}
void drawPushedButton(int x, int y, char* text) {
  int width, height;
  int i;

  width = ((strlen(text) - 1) * 8) + 10;
  height = 12;
  drawLine(x, y, x + width, y, 8);
  drawLine(x, y, x, y + height, 8);
  drawLine(x + width, y, x + width, y + height, 15);
  drawLine(x + width, y + height, x, y + height, 15);
  for (i = 1; i < height; i++) {
    drawLine((x + 1), (y + i), (x + width - 1), (y + i), 7);
  }
  drawString (x + 4, y  + 4, text, 8);
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
	drawPixel (x, y, c);
	drawPixel (x + 1, y, c);
	drawPixel (x + 2, y, c);
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

void getMouseStatus(int *button, int *x, int *y) {
  struct REGPACK reg;
  reg.r_ax = 0x0003;
  intr(0x33, &reg);
  *button = reg.r_bx;
  *x = reg.r_cx;
  *y = reg.r_dx;
}

int main(int argc, char** argv[]) {
  int x, y;
  int mouseX, mouseY, mouseButton;
  int prevMouseButton, animationDrawn;
  prevMouseButton = 0;
  animationDrawn = 0;

  // This code is here to prevent warnings for not using argc, argv in the
  // compiler
  if (argc > 2) {
    printf("%s\n", argv[1]);
  }

  setGraphicsMode(); // Switch to 320x200x256
  showMouseCursor();
  setWorkSpace(); // set-up workspace

  // Main program loop
  while (1) {
    getMouseStatus(&mouseButton, &mouseX, &mouseY);

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
  printf("Have a happy DOS!\n");
  return 0;
}