/*
  VGA procedures
  Code heavily influenced by the Let's Play series by Root42 on YouTube
  See: https://www.youtube.com/playlist?list=PLGJnX2KGgaw2L7Uv5NThlL48G9y4rJx1X
*/

#include "vga.h"
#include <dos.h>
#include <stdio.h>

// Procedure to go back to text mode
void setTextMode () {
  union REGS inregs, outregs;

  inregs.h.ah = SET_MODE; // set video mode
  inregs.h.al = TEXT_MODE; // Mode 3h = 80x25 text mode
  int86(VIDEO_INT, &inregs, &outregs);
}

void setModeY() {
  // Clear vga pages
  vga_page[0] = 0;
  vga_page[1] = (SCREEN_WIDTH * SCREEN_HEIGHT) / 4 * 1;
  vga_page[2] = (SCREEN_WIDTH * SCREEN_HEIGHT) / 4 * 2;
  vga_page[3] = (SCREEN_WIDTH * SCREEN_HEIGHT) / 4 * 3;


  // Switch to mode Y, to allow 256KiB memory @ 70 Hz

  // disable chain 4
  outportb (SC_INDEX, MEMORY_MODE);
  outportb (SC_DATA, 0x06);

  // disable doubleword mode
  outportb (CRTC_INDEX, UNDERLINE_LOCATION);
  outportb (CRTC_DATA, 0x00);

  // Disable word mode
  outportb (CRTC_INDEX, MODE_CONTROL);
  outportb (CRTC_DATA, 0xE3);

  // Clear all VGA video memory
  outportb (SC_INDEX, MAP_MASK);
  outportb (SC_DATA, 0xFF);  // select all planes

  // write 2^16 nulls
  memset (VGA + 0x0000, 0, 0x8000);
  memset (VGA + 0x8000, 0, 0x8000);

}

void setGraphicsMode() {

  // Initialise as 320x200x256 mode 13h
  union REGS inregs, outregs;

  inregs.h.ah = SET_MODE; // set video mode function
  inregs.h.al = VGA_256_COLOR_MODE; // Mode 13h == 320x200x256
  int86(VIDEO_INT, &inregs, &outregs); // BIOS call

  setModeY();
}

void drawPixel(int page, int x, int y, unsigned char color) {
  unsigned int offset;

  outportb (SC_INDEX, MAP_MASK);
  outportb (SC_DATA, 1 << (x & 3));

  offset = page + ((SCREEN_WIDTH * y) >> 2) + (x >> 2); // calculate offset
							// x / 4 == x >> 2
  VGA[offset] = color;
}

unsigned char getPixel(int page, int x, int y) {
  // GetPixel routine based on Mike Hawk
  // https://qbmikehawk.neocities.org/articles/mode-y/
  unsigned int offset;

  outportb (GC_INDEX, READ_MAP_SELECT);
  outportb (GC_DATA, (x & 3));

  offset = page + ((y * SCREEN_WIDTH) >> 2) + (x >> 2);
  return VGA[offset];
}


void pageFlip(unsigned int *page1, unsigned int *page2) {
  unsigned int temp;
  unsigned int high_address, low_address;

  temp = *page1;
  *page1 = *page2;
  *page2 = temp;

  /*
    instead of:
    outportb (CRTC_INDEX, HIGH_ADDRESS);
    outportb (CRTC_DATA, *page1 & 0xFF00 >> 8);

    do this:
    high_address = HIGH_ADDRESS | (*page1 & 0xFF00);
    outportb(CRTC_INDEX, high_address);
  */

  high_address = HIGH_ADDRESS | (*page1 & 0xFF00);
  low_address = LOW_ADDRESS | (*page1 << 8);

  while (inp(INPUT_STATUS) & DISPLAY_ENABLE); // wait for Vertical Retrace
  outportb (CRTC_INDEX, high_address);
  outportb (CRTC_INDEX, low_address);

  while (!(inp(INPUT_STATUS) & VRETRACE));
}

void copyToPage(unsigned char far *s, unsigned int page, int h)
{
  int x, y;
  unsigned char c;

  for (y = 0; y < h; y++) {
    for (x = 0; x < SCREEN_WIDTH; x++) {
      c = s[y * SCREEN_WIDTH + x];
      drawPixel(page, x, y, c);
    }
  }
}

void drawLetter(char letter, int char_x, int char_y, unsigned char char_color) {
  int x, y;
  unsigned int index;
  index = (int)letter;
  for (y = 0; y <= 7; y++) {
    for (x = 7; x >= 0; x--) {
      if (thin_font[index][y] & (1 << x)) {
	drawPixel(VGA_PANE, char_x + (6 - x), char_y + y, char_color);
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
    drawPixel(VGA_PANE, x1, y1, color);
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
  drawPixel(VGA_PANE, x2, y2, color);
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

void waitForRetrace() {
  while (inp(INPUT_STATUS) & VRETRACE);
  while (!(inp(INPUT_STATUS) & VRETRACE));
}