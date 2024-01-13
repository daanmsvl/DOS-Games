/* sprite editor
   by Daan, 5-1-2024
   Code heavily influence by the let's play MS-DOS tutorials by Root42
   see: https://www.youtube.com/playlist?list=PLGJnX2KGgaw2L7Uv5NThlL48G9y4rJx1X
*/

#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include "font.h"
#include "vga.h"
#include "vga.c"

// Structs
struct Sprite {
  unsigned char pixels[32][32];
  unsigned char transparencyColor;
};

struct Palette {
  unsigned char red[256];
  unsigned char green[256];
  unsigned char blue[256];
};

struct SpriteSet {
  struct Sprite sprites[12];
  struct Palette palette;
  int currentSprite;
};

// global variables
unsigned char savedMouseScreen[8][8];
struct SpriteSet spriteSet;

void clearSprites() {
  int i;
  int x, y;
  for (i = 0; i < 12; i++) {
    for (x = 0; x < 32; x++) {
      for (y = 0; y < 32; y++) {
	spriteSet.sprites[i].pixels[x][y] = 0;
      }
    }
    spriteSet.sprites[i].transparencyColor = 0;
  }
  spriteSet.currentSprite = 0; // set current sprite to 0
}

void fillPreviewArea() {
  /*
    drawLine (179, 19, 213, 19, 15);
    drawLine (179, 19, 179, 53, 15);
    drawLine (179, 53, 213, 53, 15);
    drawLine (213, 53, 213, 19, 15);
   */
  int x, y;
  int cs, color; // easier to type

  for (x = 0; x < 32; x++) {
    for (y = 0; y < 32; y++) {
      cs = spriteSet.currentSprite;
      color = spriteSet.sprites[cs].pixels[x][y];
      drawPixel(0, 180 + x, 20 + y, color);
    }
  }
}

void fillSpriteArea() {
  int x, y;
  int dx, dy;
  int i;
  int cs;
  int color;

  cs = spriteSet.currentSprite; // cs is easier to type...
  for (x = 0; x < 32; x++) {
    for (y = 0; y < 32; y++) {
      dx = 10 + (x * 5);
      dy = 20 + (y * 5);
      color = spriteSet.sprites[cs].pixels[x][y];
      for (i = 0; i < 4; i ++) {
	drawLine(dx, dy + i, dx + 3, dy + i, color);
      }
    }
  }
}

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

void drawColorSelected(int color) {
  int i;
  // Draw rectangle
  drawLine (180, 164, 234, 164, 15);
  drawLine (180, 164, 180, 180, 15);
  drawLine (180, 180, 234, 180, 15);
  drawLine (234, 180, 234, 164, 15);

  for (i = 0; i < 15; i++) {
    drawLine(181, 165 + i, 233, 165 + i, color);
  }
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

  // Fill with the actual sprite data
  fillSpriteArea();

  // actual representation of the sprite
  drawLine (179, 19, 212, 19, 15);
  drawLine (179, 19, 179, 52, 15);
  drawLine (179, 52, 212, 52, 15);
  drawLine (212, 52, 212, 19, 15);

  // Fill with the actual sprite
  fillPreviewArea();

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

  drawColorSelected(0);

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
  char coords[100];

  waitForRetrace();
  restoreScreen(oldMouseX, oldMouseY);
  saveScreen(mouseX, mouseY);
  waitForRetrace();
  for (y = 0; y <= 7; y++) {
    for (x = 0; x <= 7; x++) {
      if (mouse_cursor[y] & (mask >> x)) {
	drawPixel(0, (mouseX + x), (mouseY + y), 15);
      }
    }
  }

  for (y = 0; y < 12; y++) {
    drawLine(0, y, 320, y, 0);
  }
  sprintf(coords, "X: %d, Y: %d", mouseX, mouseY);
  drawString(0, 0, coords, 15);

}

int main(int argc, char** argv[]) {
  // General purpose variables
  int x, y;
  int i;
  int color;
  int mouseX, mouseY, mouseButton;
  int oldMouseX, oldMouseY;
  int prevMouseButton, animationDrawn;
  char s[100];
  FILE *file;

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

  // Initialise work area
  setGraphicsMode(); 	// Switch to 320x200x256; mode Y
  clearSprites();	// Start with an empty file
  setWorkSpace(); 	// set-up workspace

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

    if ((mouseButton == 1)) {		// Click without release
      if ((mouseX >= 10) && (mouseX <= 169) &&
	  (mouseY >= 20) && (mouseY <= 179)) {	// Work area click
	// Calculate X and Y of the grid
	x = ceil((float)((mouseX - 10)/5));
	y = ceil((float)((mouseY - 20)/5));
	i = spriteSet.currentSprite; // cs is easier to type...

	// Color the pixel
	spriteSet.sprites[i].pixels[x][y] = getPixel(0, 182, 166);

	// Remove the mouse cursor
	restoreScreen(mouseX, mouseY);

	// Update what we did
	fillSpriteArea();
	fillPreviewArea();

	// update what lies under the mouse cursor
	saveScreen(mouseX, mouseY);
      }
    } // Click without release

    if (mouseButton != prevMouseButton) {		// click with release
      // Check if something needs to be animated
      if ((mouseButton == 1) && (animationDrawn == 0)) {
	if ((mouseX >= 280) && (mouseY >= 182) &&    // Quit pressed
	    (mouseX <= 313) && (mouseY <= 194)) {
	  // Animate 'quit' button
	  drawPushedButton(280, 182, "Quit");
	  animationDrawn= 1;
	}
	if ((mouseX >= 180) && (mouseX <= 243) &&
	    (mouseY >= 71) && (mouseY <= 135)) {    // Color picker
	    // Calculate the color selected
	    x = ceil((float)((mouseX - 180)/4));
	    y = ceil((float)((mouseY - 71)/4));
	    y = (y == 4 && y % 4 != 0) ? 1 : y;
	    color = (y * 16) + x;
	    drawColorSelected(color);
	}
	prevMouseButton = mouseButton;
      }
      // Action on the release of the button
      if (mouseButton == 0) {		// indicates release
	if ((mouseX >= 280) && (mouseY >= 182) &&
	    (mouseX <= 313) && (mouseY <= 194)) {
	  break; //quit pressed
	}
	prevMouseButton = mouseButton;
      }
    }
  } // main program loop

  hideMouseCursor();

  setTextMode();
  file = fopen("test.spr", "wb");
  if (file == NULL) {
    printf ("Error opening file for writing...");
    return 1;
  }
  fwrite(&spriteSet, sizeof(struct SpriteSet), 1, file);
  fclose(file);

  printf("Have a nice DOS!\n");

  return 0;
}