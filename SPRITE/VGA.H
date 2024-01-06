// vga.h - contains all VGA procedures and constants
// Created by Daan, 6-1-2024

#ifndef VGA_H
#define VGA_H

unsigned char far * const VGA = (unsigned char far *)0xA0000000L;
unsigned int vga_page[4];
unsigned int SCREEN_WIDTH = 320;
unsigned int SCREEN_HEIGHT = 200;
unsigned int VGA_PANE = 0;

// VGA parameters
#define VGA_256_COLOR_MODE 0x13
#define TEXT_MODE 0x03
#define VIDEO_INT 0x10
#define SET_MODE 0x00
#define NUM_COLORS 256

// VGA Ports
#define PALETTE_INDEX 0x3C8
#define PALETTE_DATA 0x3C9
#define INPUT_STATUS 0x03DA
#define MISC_OUTPUT 0x3C2
#define SC_INDEX 0x3C4
#define SC_DATA 0x3C5
#define GC_INDEX 0x03CE
#define GC_DATA 0x03CF
#define CRTC_INDEX 0x03D4
#define CRTC_DATA 0x03D5

// VGA Status bits
#define DISPLAY_ENABLE 0x01
#define VRETRACE 0x08

// Sequence controller registers
#define MAP_MASK 0x02
#define ALL_PLANES 0xFF02
#define MEMORY_MODE 0x04

// CRT Controller registers
#define HIGH_ADDRESS 0x0C
#define LOW_ADDRESS 0x0D
#define UNDERLINE_LOCATION 0x14
#define MODE_CONTROL 0x17

// Function prototypes
void setTextMode();
void setModeY();
void setGraphicsMode();
void drawPixel(int page, int x, int y, unsigned char color);
unsigned char getPixel(int page, int x, int y);
void pageFlip(unsigned int *page1, unsigned int *page2);
void copyToPage(unsigned char far *s, unsigned int page, int h);
void drawLetter(char letter, int char_x, int char_y, unsigned char char_color);
void drawString(int x, int y, char *str, unsigned char color);
void drawLine(int x1, int y1, int x2, int y2, unsigned char color);
void drawButton(int x, int y, char* text);
void drawPushedButton(int x, int y, char* text);
void waitForRetrace();


#endif