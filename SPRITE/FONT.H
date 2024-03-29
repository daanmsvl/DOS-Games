// font.h -- defines fonts
// Created by Daan, 5-1-2024
//
// Source for the font files: https://github.com/epto/epto-fonts
// convert .font file to C output, use the command line:
// ```
// hexdump -C thin-8x8.font | cut -c 11-59 | sed 's/  / /g' | awk ' { for (i=1; i<=NF; i++) { printf "0x%s, ", $i; if (i % 8 == 0) printf "\n" } }' | sed 's/..$//' | sed -e 's/^/{/' -e 's/$/},/'
// ```

#ifndef FONT_H
#define FONT_H

char mouse_cursor[8] = {0x40, 0x60, 0x70, 0x78, 0x7C, 0x7E, 0x18, 0x0C};
//char mouse_cursor[8] = {0x00, 0x40, 0x60, 0x70, 0x78, 0x7c, 0x7e, 0x00};
//char mouse_cursor[8] = {0xff, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xff};

char thin_font[256][8] = {
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x7e, 0x81, 0xa5, 0x81, 0xbd, 0x99, 0x81, 0x7e},
  {0x7e, 0xff, 0xdb, 0xff, 0xc3, 0xe7, 0xff, 0x7e},
  {0x6c, 0xfe, 0xfe, 0xfe, 0x7c, 0x38, 0x10, 0x00},
  {0x10, 0x38, 0x7c, 0xfe, 0x7c, 0x38, 0x10, 0x00},
  {0x38, 0x38, 0x38, 0xfe, 0xfe, 0xd6, 0x10, 0x38},
  {0x10, 0x10, 0x38, 0x7c, 0xfe, 0x7c, 0x10, 0x38},
  {0x00, 0x00, 0x18, 0x3c, 0x3c, 0x18, 0x00, 0x00},
  {0xff, 0xff, 0xe7, 0xc3, 0xc3, 0xe7, 0xff, 0xff},
  {0x00, 0x3c, 0x66, 0x42, 0x42, 0x66, 0x3c, 0x00},
  {0xff, 0xc3, 0x99, 0xbd, 0xbd, 0x99, 0xc3, 0xff},
  {0x0f, 0x03, 0x05, 0x7d, 0x84, 0x84, 0x84, 0x78},
  {0x3c, 0x42, 0x42, 0x42, 0x3c, 0x18, 0x7e, 0x18},
  {0x3f, 0x21, 0x3f, 0x20, 0x20, 0x60, 0xe0, 0xc0},
  {0x3f, 0x21, 0x3f, 0x21, 0x23, 0x67, 0xe6, 0xc0},
  {0x18, 0xdb, 0x3c, 0xe7, 0xe7, 0x3c, 0xdb, 0x18},
  {0x80, 0xe0, 0xf8, 0xfe, 0xf8, 0xe0, 0x80, 0x00},
  {0x02, 0x0e, 0x3e, 0xfe, 0x3e, 0x0e, 0x02, 0x00},
  {0x18, 0x3c, 0x7e, 0x18, 0x18, 0x7e, 0x3c, 0x18},
  {0x24, 0x24, 0x24, 0x24, 0x24, 0x00, 0x24, 0x00},
  {0x7f, 0x92, 0x92, 0x72, 0x12, 0x12, 0x12, 0x00},
  {0x3e, 0x63, 0x38, 0x44, 0x44, 0x38, 0xcc, 0x78},
  {0x00, 0x00, 0x00, 0x00, 0x7e, 0x7e, 0x7e, 0x00},
  {0x18, 0x3c, 0x7e, 0x18, 0x7e, 0x3c, 0x18, 0xff},
  {0x10, 0x38, 0x7c, 0x54, 0x10, 0x10, 0x10, 0x00},
  {0x10, 0x10, 0x10, 0x54, 0x7c, 0x38, 0x10, 0x00},
  {0x00, 0x18, 0x0c, 0xfe, 0x0c, 0x18, 0x00, 0x00},
  {0x00, 0x30, 0x60, 0xfe, 0x60, 0x30, 0x00, 0x00},
  {0x00, 0x00, 0x40, 0x40, 0x40, 0x7e, 0x00, 0x00},
  {0x00, 0x24, 0x66, 0xff, 0x66, 0x24, 0x00, 0x00},
  {0x00, 0x10, 0x38, 0x7c, 0xfe, 0xfe, 0x00, 0x00},
  {0x00, 0xfe, 0xfe, 0x7c, 0x38, 0x10, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x10, 0x00},
  {0x24, 0x24, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x24, 0x24, 0x7e, 0x24, 0x7e, 0x24, 0x24, 0x00},
  {0x18, 0x3e, 0x40, 0x3c, 0x02, 0x7c, 0x18, 0x00},
  {0x00, 0x62, 0x64, 0x08, 0x10, 0x26, 0x46, 0x00},
  {0x30, 0x48, 0x30, 0x56, 0x88, 0x88, 0x76, 0x00},
  {0x10, 0x10, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x10, 0x20, 0x40, 0x40, 0x40, 0x20, 0x10, 0x00},
  {0x20, 0x10, 0x08, 0x08, 0x08, 0x10, 0x20, 0x00},
  {0x00, 0x44, 0x38, 0xfe, 0x38, 0x44, 0x00, 0x00},
  {0x00, 0x10, 0x10, 0x7c, 0x10, 0x10, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x20},
  {0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00},
  {0x00, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x00},
  {0x3c, 0x42, 0x46, 0x4a, 0x52, 0x62, 0x3c, 0x00},
  {0x10, 0x30, 0x50, 0x10, 0x10, 0x10, 0x7c, 0x00},
  {0x3c, 0x42, 0x02, 0x0c, 0x30, 0x42, 0x7e, 0x00},
  {0x3c, 0x42, 0x02, 0x1c, 0x02, 0x42, 0x3c, 0x00},
  {0x08, 0x18, 0x28, 0x48, 0xfe, 0x08, 0x1c, 0x00},
  {0x7e, 0x40, 0x7c, 0x02, 0x02, 0x42, 0x3c, 0x00},
  {0x1c, 0x20, 0x40, 0x7c, 0x42, 0x42, 0x3c, 0x00},
  {0x7e, 0x42, 0x04, 0x08, 0x10, 0x10, 0x10, 0x00},
  {0x3c, 0x42, 0x42, 0x3c, 0x42, 0x42, 0x3c, 0x00},
  {0x3c, 0x42, 0x42, 0x3e, 0x02, 0x04, 0x38, 0x00},
  {0x00, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 0x00},
  {0x00, 0x10, 0x10, 0x00, 0x00, 0x10, 0x10, 0x20},
  {0x08, 0x10, 0x20, 0x40, 0x20, 0x10, 0x08, 0x00},
  {0x00, 0x00, 0x7e, 0x00, 0x00, 0x7e, 0x00, 0x00},
  {0x10, 0x08, 0x04, 0x02, 0x04, 0x08, 0x10, 0x00},
  {0x3c, 0x42, 0x02, 0x04, 0x08, 0x00, 0x08, 0x00},
  {0x3c, 0x42, 0x5e, 0x52, 0x5e, 0x40, 0x3c, 0x00},
  {0x18, 0x24, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x00},
  {0x7c, 0x22, 0x22, 0x3c, 0x22, 0x22, 0x7c, 0x00},
  {0x1c, 0x22, 0x40, 0x40, 0x40, 0x22, 0x1c, 0x00},
  {0x78, 0x24, 0x22, 0x22, 0x22, 0x24, 0x78, 0x00},
  {0x7e, 0x22, 0x28, 0x38, 0x28, 0x22, 0x7e, 0x00},
  {0x7e, 0x22, 0x28, 0x38, 0x28, 0x20, 0x70, 0x00},
  {0x1c, 0x22, 0x40, 0x40, 0x4e, 0x22, 0x1e, 0x00},
  {0x42, 0x42, 0x42, 0x7e, 0x42, 0x42, 0x42, 0x00},
  {0x38, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00},
  {0x0e, 0x04, 0x04, 0x04, 0x44, 0x44, 0x38, 0x00},
  {0x62, 0x24, 0x28, 0x30, 0x28, 0x24, 0x63, 0x00},
  {0x70, 0x20, 0x20, 0x20, 0x20, 0x22, 0x7e, 0x00},
  {0x63, 0x55, 0x49, 0x41, 0x41, 0x41, 0x41, 0x00},
  {0x62, 0x52, 0x4a, 0x46, 0x42, 0x42, 0x42, 0x00},
  {0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00},
  {0x7c, 0x22, 0x22, 0x3c, 0x20, 0x20, 0x70, 0x00},
  {0x3c, 0x42, 0x42, 0x42, 0x4a, 0x3c, 0x03, 0x00},
  {0x7c, 0x22, 0x22, 0x3c, 0x28, 0x24, 0x72, 0x00},
  {0x3c, 0x42, 0x40, 0x3c, 0x02, 0x42, 0x3c, 0x00},
  {0x7f, 0x49, 0x08, 0x08, 0x08, 0x08, 0x1c, 0x00},
  {0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00},
  {0x41, 0x41, 0x41, 0x41, 0x22, 0x14, 0x08, 0x00},
  {0x41, 0x41, 0x41, 0x49, 0x49, 0x49, 0x36, 0x00},
  {0x41, 0x22, 0x14, 0x08, 0x14, 0x22, 0x41, 0x00},
  {0x41, 0x22, 0x14, 0x08, 0x08, 0x08, 0x1c, 0x00},
  {0x7f, 0x42, 0x04, 0x08, 0x10, 0x21, 0x7f, 0x00},
  {0x78, 0x40, 0x40, 0x40, 0x40, 0x40, 0x78, 0x00},
  {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00},
  {0x78, 0x08, 0x08, 0x08, 0x08, 0x08, 0x78, 0x00},
  {0x10, 0x28, 0x44, 0x82, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff},
  {0x10, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x3c, 0x02, 0x3e, 0x42, 0x3f, 0x00},
  {0x60, 0x20, 0x20, 0x2e, 0x31, 0x31, 0x2e, 0x00},
  {0x00, 0x00, 0x3c, 0x42, 0x40, 0x42, 0x3c, 0x00},
  {0x06, 0x02, 0x02, 0x3a, 0x46, 0x46, 0x3b, 0x00},
  {0x00, 0x00, 0x3c, 0x42, 0x7e, 0x40, 0x3c, 0x00},
  {0x0c, 0x12, 0x10, 0x38, 0x10, 0x10, 0x38, 0x00},
  {0x00, 0x00, 0x3d, 0x42, 0x42, 0x3e, 0x02, 0x7c},
  {0x60, 0x20, 0x2c, 0x32, 0x22, 0x22, 0x62, 0x00},
  {0x10, 0x00, 0x30, 0x10, 0x10, 0x10, 0x38, 0x00},
  {0x02, 0x00, 0x06, 0x02, 0x02, 0x42, 0x42, 0x3c},
  {0x60, 0x20, 0x24, 0x28, 0x30, 0x28, 0x26, 0x00},
  {0x30, 0x10, 0x10, 0x10, 0x10, 0x10, 0x38, 0x00},
  {0x00, 0x00, 0x76, 0x49, 0x49, 0x49, 0x49, 0x00},
  {0x00, 0x00, 0x5c, 0x62, 0x42, 0x42, 0x42, 0x00},
  {0x00, 0x00, 0x3c, 0x42, 0x42, 0x42, 0x3c, 0x00},
  {0x00, 0x00, 0x6c, 0x32, 0x32, 0x2c, 0x20, 0x70},
  {0x00, 0x00, 0x36, 0x4c, 0x4c, 0x34, 0x04, 0x0e},
  {0x00, 0x00, 0x6c, 0x32, 0x22, 0x20, 0x70, 0x00},
  {0x00, 0x00, 0x3e, 0x40, 0x3c, 0x02, 0x7c, 0x00},
  {0x10, 0x10, 0x7c, 0x10, 0x10, 0x12, 0x0c, 0x00},
  {0x00, 0x00, 0x42, 0x42, 0x42, 0x46, 0x3a, 0x00},
  {0x00, 0x00, 0x41, 0x41, 0x22, 0x14, 0x08, 0x00},
  {0x00, 0x00, 0x41, 0x49, 0x49, 0x49, 0x36, 0x00},
  {0x00, 0x00, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00},
  {0x00, 0x00, 0x42, 0x42, 0x42, 0x3e, 0x02, 0x7c},
  {0x00, 0x00, 0x7c, 0x08, 0x10, 0x20, 0x7c, 0x00},
  {0x0c, 0x10, 0x10, 0x60, 0x10, 0x10, 0x0c, 0x00},
  {0x10, 0x10, 0x10, 0x00, 0x10, 0x10, 0x10, 0x00},
  {0x30, 0x08, 0x08, 0x06, 0x08, 0x08, 0x30, 0x00},
  {0x32, 0x4c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x08, 0x14, 0x22, 0x41, 0x41, 0x7f, 0x00},
  {0x3c, 0x42, 0x40, 0x42, 0x3c, 0x0c, 0x02, 0x3c},
  {0x00, 0x44, 0x00, 0x44, 0x44, 0x44, 0x3e, 0x00},
  {0x0c, 0x00, 0x3c, 0x42, 0x7e, 0x40, 0x3c, 0x00},
  {0x3c, 0x42, 0x38, 0x04, 0x3c, 0x44, 0x3e, 0x00},
  {0x42, 0x00, 0x38, 0x04, 0x3c, 0x44, 0x3e, 0x00},
  {0x30, 0x00, 0x38, 0x04, 0x3c, 0x44, 0x3e, 0x00},
  {0x10, 0x00, 0x38, 0x04, 0x3c, 0x44, 0x3e, 0x00},
  {0x00, 0x00, 0x3c, 0x40, 0x40, 0x3c, 0x06, 0x1c},
  {0x3c, 0x42, 0x3c, 0x42, 0x7e, 0x40, 0x3c, 0x00},
  {0x42, 0x00, 0x3c, 0x42, 0x7e, 0x40, 0x3c, 0x00},
  {0x30, 0x00, 0x3c, 0x42, 0x7e, 0x40, 0x3c, 0x00},
  {0x24, 0x00, 0x18, 0x08, 0x08, 0x08, 0x1c, 0x00},
  {0x7c, 0x82, 0x30, 0x10, 0x10, 0x10, 0x38, 0x00},
  {0x30, 0x00, 0x18, 0x08, 0x08, 0x08, 0x1c, 0x00},
  {0x42, 0x18, 0x24, 0x42, 0x7e, 0x42, 0x42, 0x00},
  {0x18, 0x18, 0x00, 0x3c, 0x42, 0x7e, 0x42, 0x00},
  {0x0c, 0x00, 0x7c, 0x20, 0x38, 0x20, 0x7c, 0x00},
  {0x00, 0x00, 0x33, 0x0c, 0x3f, 0x44, 0x3b, 0x00},
  {0x1f, 0x24, 0x44, 0x7f, 0x44, 0x44, 0x47, 0x00},
  {0x18, 0x24, 0x00, 0x3c, 0x42, 0x42, 0x3c, 0x00},
  {0x00, 0x42, 0x00, 0x3c, 0x42, 0x42, 0x3c, 0x00},
  {0x20, 0x10, 0x00, 0x3c, 0x42, 0x42, 0x3c, 0x00},
  {0x18, 0x24, 0x00, 0x42, 0x42, 0x42, 0x3c, 0x00},
  {0x20, 0x10, 0x00, 0x42, 0x42, 0x42, 0x3c, 0x00},
  {0x00, 0x42, 0x00, 0x42, 0x42, 0x3e, 0x02, 0x3c},
  {0x42, 0x18, 0x24, 0x42, 0x42, 0x24, 0x18, 0x00},
  {0x42, 0x00, 0x42, 0x42, 0x42, 0x42, 0x3c, 0x00},
  {0x08, 0x08, 0x3e, 0x40, 0x40, 0x3e, 0x08, 0x08},
  {0x18, 0x24, 0x20, 0x70, 0x20, 0x42, 0x7c, 0x00},
  {0x44, 0x28, 0x7c, 0x10, 0x7c, 0x10, 0x10, 0x00},
  {0xf8, 0x4c, 0x78, 0x44, 0x4f, 0x44, 0x45, 0xe6},
  {0x1c, 0x12, 0x10, 0x7c, 0x10, 0x10, 0x90, 0x60},
  {0x0c, 0x00, 0x38, 0x04, 0x3c, 0x44, 0x3e, 0x00},
  {0x0c, 0x00, 0x18, 0x08, 0x08, 0x08, 0x1c, 0x00},
  {0x04, 0x08, 0x00, 0x3c, 0x42, 0x42, 0x3c, 0x00},
  {0x00, 0x04, 0x08, 0x42, 0x42, 0x42, 0x3c, 0x00},
  {0x32, 0x4c, 0x00, 0x7c, 0x42, 0x42, 0x42, 0x00},
  {0x32, 0x4c, 0x00, 0x62, 0x52, 0x4a, 0x46, 0x00},
  {0x3c, 0x44, 0x44, 0x3e, 0x00, 0x7e, 0x00, 0x00},
  {0x38, 0x44, 0x44, 0x38, 0x00, 0x7c, 0x00, 0x00},
  {0x10, 0x00, 0x10, 0x20, 0x40, 0x42, 0x3c, 0x00},
  {0x00, 0x00, 0x00, 0x7e, 0x40, 0x40, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x7e, 0x02, 0x02, 0x00, 0x00},
  {0x42, 0xc4, 0x48, 0xf6, 0x29, 0x43, 0x8c, 0x1f},
  {0x42, 0xc4, 0x4a, 0xf6, 0x2a, 0x5f, 0x82, 0x02},
  {0x00, 0x10, 0x00, 0x10, 0x10, 0x10, 0x10, 0x00},
  {0x00, 0x12, 0x24, 0x48, 0x24, 0x12, 0x00, 0x00},
  {0x00, 0x48, 0x24, 0x12, 0x24, 0x48, 0x00, 0x00},
  {0x22, 0x88, 0x22, 0x88, 0x22, 0x88, 0x22, 0x88},
  {0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa},
  {0xdb, 0x77, 0xdb, 0xee, 0xdb, 0x77, 0xdb, 0xee},
  {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0x10, 0x10, 0xf0, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0xf0, 0x10, 0xf0, 0x10, 0x10, 0x10},
  {0x14, 0x14, 0x14, 0x14, 0xf4, 0x14, 0x14, 0x14},
  {0x00, 0x00, 0x00, 0x00, 0xfc, 0x14, 0x14, 0x14},
  {0x00, 0x00, 0xf0, 0x10, 0xf0, 0x10, 0x10, 0x10},
  {0x14, 0x14, 0xf4, 0x04, 0xf4, 0x14, 0x14, 0x14},
  {0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14, 0x14},
  {0x00, 0x00, 0xfc, 0x04, 0xf4, 0x14, 0x14, 0x14},
  {0x14, 0x14, 0xf4, 0x04, 0xfc, 0x00, 0x00, 0x00},
  {0x14, 0x14, 0x14, 0x14, 0xfc, 0x00, 0x00, 0x00},
  {0x10, 0x10, 0xf0, 0x10, 0xf0, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0xf0, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0x10, 0x10, 0x1f, 0x00, 0x00, 0x00},
  {0x10, 0x10, 0x10, 0x10, 0xff, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0xff, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0x10, 0x10, 0x1f, 0x10, 0x10, 0x10},
  {0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00},
  {0x10, 0x10, 0x10, 0x10, 0xff, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0x1f, 0x10, 0x1f, 0x10, 0x10, 0x10},
  {0x14, 0x14, 0x14, 0x14, 0x17, 0x14, 0x14, 0x14},
  {0x14, 0x14, 0x17, 0x10, 0x1f, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x1f, 0x10, 0x17, 0x14, 0x14, 0x14},
  {0x14, 0x14, 0xf7, 0x00, 0xff, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0xff, 0x00, 0xf7, 0x14, 0x14, 0x14},
  {0x14, 0x14, 0x17, 0x10, 0x17, 0x14, 0x14, 0x14},
  {0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0x00},
  {0x14, 0x14, 0xf7, 0x00, 0xf7, 0x14, 0x14, 0x14},
  {0x10, 0x10, 0xff, 0x00, 0xff, 0x00, 0x00, 0x00},
  {0x14, 0x14, 0x14, 0x14, 0xff, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0xff, 0x00, 0xff, 0x10, 0x10, 0x10},
  {0x00, 0x00, 0x00, 0x00, 0xff, 0x14, 0x14, 0x14},
  {0x14, 0x14, 0x14, 0x14, 0x1f, 0x00, 0x00, 0x00},
  {0x10, 0x10, 0x1f, 0x10, 0x1f, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x1f, 0x10, 0x1f, 0x10, 0x10, 0x10},
  {0x00, 0x00, 0x00, 0x00, 0x1f, 0x14, 0x14, 0x14},
  {0x14, 0x14, 0x14, 0x14, 0xff, 0x14, 0x14, 0x14},
  {0x10, 0x10, 0xff, 0x10, 0xff, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x1f, 0x10, 0x10, 0x10},
  {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},
  {0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff},
  {0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0},
  {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f},
  {0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x31, 0x4a, 0x44, 0x4a, 0x31, 0x00},
  {0x00, 0x3c, 0x42, 0x7c, 0x42, 0x7c, 0x40, 0x40},
  {0x00, 0x7e, 0x42, 0x40, 0x40, 0x40, 0x40, 0x00},
  {0x00, 0x3f, 0x54, 0x14, 0x14, 0x14, 0x14, 0x00},
  {0x7e, 0x42, 0x20, 0x18, 0x20, 0x42, 0x7e, 0x00},
  {0x00, 0x00, 0x3e, 0x48, 0x48, 0x48, 0x30, 0x00},
  {0x00, 0x44, 0x44, 0x44, 0x7a, 0x40, 0x40, 0x80},
  {0x00, 0x33, 0x4c, 0x08, 0x08, 0x08, 0x08, 0x00},
  {0x7c, 0x10, 0x38, 0x44, 0x44, 0x38, 0x10, 0x7c},
  {0x18, 0x24, 0x42, 0x7e, 0x42, 0x24, 0x18, 0x00},
  {0x18, 0x24, 0x42, 0x42, 0x24, 0x24, 0x66, 0x00},
  {0x1c, 0x20, 0x18, 0x3c, 0x42, 0x42, 0x3c, 0x00},
  {0x00, 0x62, 0x95, 0x89, 0x95, 0x62, 0x00, 0x00},
  {0x02, 0x04, 0x3c, 0x4a, 0x52, 0x3c, 0x40, 0x80},
  {0x0c, 0x10, 0x20, 0x3c, 0x20, 0x10, 0x0c, 0x00},
  {0x3c, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x00},
  {0x00, 0x7e, 0x00, 0x7e, 0x00, 0x7e, 0x00, 0x00},
  {0x10, 0x10, 0x7c, 0x10, 0x10, 0x00, 0x7c, 0x00},
  {0x10, 0x08, 0x04, 0x08, 0x10, 0x00, 0x7e, 0x00},
  {0x08, 0x10, 0x20, 0x10, 0x08, 0x00, 0x7e, 0x00},
  {0x0c, 0x12, 0x12, 0x10, 0x10, 0x10, 0x10, 0x10},
  {0x10, 0x10, 0x10, 0x10, 0x10, 0x90, 0x90, 0x60},
  {0x18, 0x18, 0x00, 0x7e, 0x00, 0x18, 0x18, 0x00},
  {0x00, 0x32, 0x4c, 0x00, 0x32, 0x4c, 0x00, 0x00},
  {0x30, 0x48, 0x48, 0x30, 0x00, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00},
  {0x0f, 0x08, 0x08, 0x08, 0x08, 0xc8, 0x28, 0x18},
  {0x78, 0x44, 0x44, 0x44, 0x44, 0x00, 0x00, 0x00},
  {0x30, 0x48, 0x10, 0x20, 0x78, 0x00, 0x00, 0x00},
  {0x00, 0x00, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x00}
};

char digital_font[128][8] = {
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // '\x00' (NULL)
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x38, 0x38, 0x38, 0x38, 0x38, 0x00, 0x38, 0x00}, // '!'
  {0x6c, 0x6c, 0x24, 0x48, 0x00, 0x00, 0x00, 0x00}, // '"'
  {0x44, 0xfe, 0x44, 0x44, 0x44, 0xfe, 0x44, 0x00}, // '#'
  {0x10, 0x7c, 0x40, 0x7c, 0x04, 0x7c, 0x10, 0x00}, // '$'
  {0xe2, 0xa4, 0xe8, 0x10, 0x2e, 0x4a, 0x8e, 0x00}, // '%'
  {0x30, 0x48, 0x40, 0x20, 0x50, 0x48, 0x74, 0x00}, // '&'
  {0x38, 0x38, 0x08, 0x30, 0x00, 0x00, 0x00, 0x00}, // '''
  {0x18, 0x30, 0x60, 0x60, 0x60, 0x30, 0x18, 0x00}, // '('
  {0x60, 0x30, 0x18, 0x18, 0x18, 0x30, 0x60, 0x00}, // ')'
  {0x20, 0xa8, 0x70, 0x20, 0x70, 0xa8, 0x20, 0x00}, // '*'
  {0x00, 0x10, 0x10, 0x7c, 0x18, 0x18, 0x00, 0x00}, // '+'
  {0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x08, 0x30}, // ','
  {0x00, 0x00, 0x00, 0x7c, 0x7c, 0x00, 0x00, 0x00}, // '-'
  {0x00, 0x00, 0x00, 0x00, 0x38, 0x38, 0x38, 0x00}, // '.'
  {0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00}, // '/'
  {0xf8, 0x88, 0x98, 0xa8, 0xc8, 0xc8, 0xf8, 0x00}, // '0'
  {0xe0, 0x20, 0x20, 0x20, 0x20, 0x20, 0xf8, 0x00}, // '1'
  {0xfc, 0x04, 0x04, 0xfc, 0xc0, 0xc0, 0xfc, 0x00}, // '2'
  {0x78, 0x08, 0x08, 0x78, 0x18, 0x18, 0xf8, 0x00}, // '3'
  {0x88, 0x88, 0x88, 0x88, 0xfc, 0x18, 0x18, 0x00}, // '4'
  {0xf8, 0x80, 0x80, 0xf8, 0x18, 0x98, 0xf8, 0x00}, // '5'
  {0xf8, 0x88, 0x80, 0xf8, 0xc8, 0xc8, 0xf8, 0x00}, // '6'
  {0xf8, 0x88, 0x10, 0x20, 0x60, 0x60, 0x60, 0x00}, // '7'
  {0xf8, 0x88, 0x88, 0xf8, 0xc8, 0xc8, 0xf8, 0x00}, // '8'
  {0xf8, 0x88, 0x88, 0xf8, 0x18, 0x98, 0xf8, 0x00}, // '9'
  {0x00, 0x38, 0x38, 0x00, 0x38, 0x38, 0x00, 0x00}, // ':'
  {0x00, 0x38, 0x38, 0x00, 0x38, 0x38, 0x08, 0x30}, // ';'
  {0x08, 0x10, 0x20, 0xc0, 0x20, 0x10, 0x08, 0x00}, // '<'
  {0x00, 0x7c, 0x7c, 0x00, 0x7c, 0x7c, 0x00, 0x00}, // '='
  {0x80, 0x40, 0x20, 0x18, 0x20, 0x40, 0x80, 0x00}, // '>'
  {0x7e, 0x42, 0x02, 0x1e, 0x10, 0x00, 0x10, 0x00}, // '?'
  {0x3c, 0x24, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00}, // '@'
  {0xf8, 0x88, 0xfc, 0x84, 0xc4, 0xc4, 0xc4, 0x00}, // 'A'
  {0xf8, 0x88, 0xfc, 0x84, 0xc4, 0xc4, 0xfc, 0x00}, // 'B'
  {0xfc, 0x84, 0x80, 0xc0, 0xc0, 0xc4, 0xfc, 0x00}, // 'C'
  {0xf8, 0x84, 0x84, 0xc4, 0xc4, 0xc4, 0xf8, 0x00}, // 'D'
  {0xfc, 0x80, 0xf0, 0x80, 0xc0, 0xc0, 0xfc, 0x00}, // 'E'
  {0xfc, 0x80, 0xf8, 0x80, 0xc0, 0xc0, 0xc0, 0x00}, // 'F'
  {0xfc, 0x84, 0x80, 0x9c, 0xc4, 0xc4, 0xfc, 0x00}, // 'G'
  {0x84, 0x84, 0xfc, 0x84, 0xc4, 0xc4, 0xc4, 0x00}, // 'H'
  {0x20, 0x20, 0x20, 0x30, 0x30, 0x30, 0x30, 0x00}, // 'I'
  {0x04, 0x04, 0x04, 0x0c, 0x0c, 0x8c, 0x78, 0x00}, // 'J'
  {0x84, 0x88, 0x90, 0xf0, 0xc8, 0xc4, 0xc4, 0x00}, // 'K'
  {0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xfc, 0x00}, // 'L'
  {0xfc, 0x92, 0x92, 0x92, 0xd2, 0xd2, 0xd2, 0x00}, // 'M'
  {0xe4, 0x94, 0x94, 0x94, 0xd4, 0xd4, 0xcc, 0x00}, // 'N'
  {0xfc, 0x84, 0x84, 0x84, 0xc4, 0xc4, 0xfc, 0x00}, // 'O'
  {0xfc, 0x84, 0x84, 0xfc, 0xc0, 0xc0, 0xc0, 0x00}, // 'P'
  {0xfc, 0x84, 0x84, 0x94, 0xd4, 0xc8, 0xf4, 0x00}, // 'Q'
  {0xfc, 0x84, 0x84, 0xfc, 0xc8, 0xc4, 0xc4, 0x00}, // 'R'
  {0xfc, 0x80, 0x80, 0xfc, 0x0c, 0x0c, 0xfc, 0x00}, // 'S'
  {0xfc, 0x20, 0x20, 0x20, 0x30, 0x30, 0x30, 0x00}, // 'T'
  {0x84, 0x84, 0x84, 0xc4, 0xc4, 0xc4, 0xfc, 0x00}, // 'U'
  {0x84, 0x84, 0xc4, 0xc4, 0x44, 0x28, 0x10, 0x00}, // 'V'
  {0x82, 0x82, 0x92, 0x92, 0xd2, 0xd2, 0xfe, 0x00}, // 'W'
  {0x84, 0x48, 0x30, 0x30, 0x48, 0x84, 0x84, 0x00}, // 'X'
  {0x84, 0x84, 0x84, 0xfc, 0x20, 0x30, 0x30, 0x00}, // 'Y'
  {0xfc, 0x08, 0x10, 0x20, 0x40, 0xc0, 0xfc, 0x00}, // 'Z'
  {0x78, 0x40, 0x40, 0x40, 0x40, 0x40, 0x78, 0x00}, // '['
  {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x00}, // '\'
  {0x3c, 0x04, 0x04, 0x04, 0x04, 0x04, 0x3c, 0x00}, // ']'
  {0x00, 0x10, 0x38, 0x6c, 0xc6, 0x00, 0x00, 0x00}, // '^'
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x7c, 0x04, 0x7c, 0x44, 0x7c, 0x00}, // 'a'
  {0x40, 0x40, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00}, // 'b'
  {0x00, 0x00, 0x7c, 0x40, 0x40, 0x40, 0x7c, 0x00}, // 'c'
  {0x04, 0x04, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00}, // 'd'
  {0x00, 0x00, 0x7c, 0x44, 0x7c, 0x40, 0x7c, 0x00}, // 'e'
  {0x3c, 0x20, 0x78, 0x20, 0x20, 0x20, 0x20, 0x00}, // 'f'
  {0x00, 0x00, 0x7c, 0x44, 0x44, 0x7c, 0x04, 0x7c}, // 'g'
  {0x40, 0x40, 0x7c, 0x44, 0x44, 0x44, 0x44, 0x00}, // 'h'
  {0x18, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00}, // 'i'
  {0x00, 0x08, 0x00, 0x08, 0x08, 0x08, 0x48, 0x78}, // 'j'
  {0x40, 0x40, 0x48, 0x50, 0x60, 0x50, 0x48, 0x00}, // 'k'
  {0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x00}, // 'l'
  {0x00, 0x00, 0xfe, 0x92, 0x92, 0x92, 0x92, 0x00}, // 'm'
  {0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x44, 0x00}, // 'n'
  {0x00, 0x00, 0x7c, 0x44, 0x44, 0x44, 0x7c, 0x00}, // 'o'
  {0x00, 0x00, 0x7c, 0x44, 0x44, 0x7c, 0x40, 0x40}, // 'p'
  {0x00, 0x00, 0x7c, 0x44, 0x44, 0x7c, 0x04, 0x04}, // 'q'
  {0x00, 0x00, 0x7c, 0x44, 0x40, 0x40, 0x40, 0x00}, // 'r'
  {0x00, 0x00, 0x7c, 0x40, 0x7c, 0x04, 0x7c, 0x00}, // 's'
  {0x00, 0x20, 0x7c, 0x20, 0x20, 0x20, 0x3c, 0x00}, // 't'
  {0x00, 0x00, 0x24, 0x24, 0x24, 0x24, 0x3c, 0x00}, // 'u'
  {0x00, 0x00, 0x44, 0x44, 0x44, 0x28, 0x10, 0x00}, // 'v'
  {0x00, 0x00, 0x82, 0x92, 0x92, 0x92, 0xfe, 0x00}, // 'w'
  {0x00, 0x00, 0x44, 0x28, 0x10, 0x28, 0x44, 0x00}, // 'x'
  {0x00, 0x00, 0x44, 0x44, 0x44, 0x7c, 0x04, 0x7c}, // 'y'
  {0x00, 0x00, 0x7c, 0x08, 0x10, 0x20, 0x7c, 0x00}, // 'z'
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10}, // '|'
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, // ' '
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00} // ' '
};

char normal_font[128][8] = {
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0000 (nul)
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0001
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0002
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0003
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0004
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0005
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0006
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0007
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0008
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0009
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000A
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000B
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000C
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000D
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000E
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000F
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0010
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0011
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0012
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0013
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0014
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0015
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0016
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0017
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0018
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0019
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001A
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001B
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001C
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001D
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001E
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001F
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0020 (space)
    { 0x18, 0x3C, 0x3C, 0x18, 0x18, 0x00, 0x18, 0x00},   // U+0021 (!)
    { 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0022 (")
    { 0x36, 0x36, 0x7F, 0x36, 0x7F, 0x36, 0x36, 0x00},   // U+0023 (#)
    { 0x0C, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x0C, 0x00},   // U+0024 ($)
    { 0x00, 0x63, 0x33, 0x18, 0x0C, 0x66, 0x63, 0x00},   // U+0025 (%)
    { 0x1C, 0x36, 0x1C, 0x6E, 0x3B, 0x33, 0x6E, 0x00},   // U+0026 (&)
    { 0x06, 0x06, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0027 (')
    { 0x18, 0x0C, 0x06, 0x06, 0x06, 0x0C, 0x18, 0x00},   // U+0028 (()
    { 0x06, 0x0C, 0x18, 0x18, 0x18, 0x0C, 0x06, 0x00},   // U+0029 ())
    { 0x00, 0x66, 0x3C, 0xFF, 0x3C, 0x66, 0x00, 0x00},   // U+002A (*)
    { 0x00, 0x0C, 0x0C, 0x3F, 0x0C, 0x0C, 0x00, 0x00},   // U+002B (+)
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x06},   // U+002C (,)
    { 0x00, 0x00, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00},   // U+002D (-)
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00},   // U+002E (.)
    { 0x60, 0x30, 0x18, 0x0C, 0x06, 0x03, 0x01, 0x00},   // U+002F (/)
    { 0x3E, 0x63, 0x73, 0x7B, 0x6F, 0x67, 0x3E, 0x00},   // U+0030 (0)
    { 0x0C, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x3F, 0x00},   // U+0031 (1)
    { 0x1E, 0x33, 0x30, 0x1C, 0x06, 0x33, 0x3F, 0x00},   // U+0032 (2)
    { 0x1E, 0x33, 0x30, 0x1C, 0x30, 0x33, 0x1E, 0x00},   // U+0033 (3)
    { 0x38, 0x3C, 0x36, 0x33, 0x7F, 0x30, 0x78, 0x00},   // U+0034 (4)
    { 0x3F, 0x03, 0x1F, 0x30, 0x30, 0x33, 0x1E, 0x00},   // U+0035 (5)
    { 0x1C, 0x06, 0x03, 0x1F, 0x33, 0x33, 0x1E, 0x00},   // U+0036 (6)
    { 0x3F, 0x33, 0x30, 0x18, 0x0C, 0x0C, 0x0C, 0x00},   // U+0037 (7)
    { 0x1E, 0x33, 0x33, 0x1E, 0x33, 0x33, 0x1E, 0x00},   // U+0038 (8)
    { 0x1E, 0x33, 0x33, 0x3E, 0x30, 0x18, 0x0E, 0x00},   // U+0039 (9)
    { 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x00},   // U+003A (:)
    { 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x0C, 0x0C, 0x06},   // U+003B (;)
    { 0x18, 0x0C, 0x06, 0x03, 0x06, 0x0C, 0x18, 0x00},   // U+003C (<)
    { 0x00, 0x00, 0x3F, 0x00, 0x00, 0x3F, 0x00, 0x00},   // U+003D (=)
    { 0x06, 0x0C, 0x18, 0x30, 0x18, 0x0C, 0x06, 0x00},   // U+003E (>)
    { 0x1E, 0x33, 0x30, 0x18, 0x0C, 0x00, 0x0C, 0x00},   // U+003F (?)
    { 0x3E, 0x63, 0x7B, 0x7B, 0x7B, 0x03, 0x1E, 0x00},   // U+0040 (@)
    { 0x0C, 0x1E, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x00},   // U+0041 (A)
    { 0x3F, 0x66, 0x66, 0x3E, 0x66, 0x66, 0x3F, 0x00},   // U+0042 (B)
    { 0x3C, 0x66, 0x03, 0x03, 0x03, 0x66, 0x3C, 0x00},   // U+0043 (C)
    { 0x1F, 0x36, 0x66, 0x66, 0x66, 0x36, 0x1F, 0x00},   // U+0044 (D)
    { 0x7F, 0x46, 0x16, 0x1E, 0x16, 0x46, 0x7F, 0x00},   // U+0045 (E)
    { 0x7F, 0x46, 0x16, 0x1E, 0x16, 0x06, 0x0F, 0x00},   // U+0046 (F)
    { 0x3C, 0x66, 0x03, 0x03, 0x73, 0x66, 0x7C, 0x00},   // U+0047 (G)
    { 0x33, 0x33, 0x33, 0x3F, 0x33, 0x33, 0x33, 0x00},   // U+0048 (H)
    { 0x1E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00},   // U+0049 (I)
    { 0x78, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E, 0x00},   // U+004A (J)
    { 0x67, 0x66, 0x36, 0x1E, 0x36, 0x66, 0x67, 0x00},   // U+004B (K)
    { 0x0F, 0x06, 0x06, 0x06, 0x46, 0x66, 0x7F, 0x00},   // U+004C (L)
    { 0x63, 0x77, 0x7F, 0x7F, 0x6B, 0x63, 0x63, 0x00},   // U+004D (M)
    { 0x63, 0x67, 0x6F, 0x7B, 0x73, 0x63, 0x63, 0x00},   // U+004E (N)
    { 0x1C, 0x36, 0x63, 0x63, 0x63, 0x36, 0x1C, 0x00},   // U+004F (O)
    { 0x3F, 0x66, 0x66, 0x3E, 0x06, 0x06, 0x0F, 0x00},   // U+0050 (P)
    { 0x1E, 0x33, 0x33, 0x33, 0x3B, 0x1E, 0x38, 0x00},   // U+0051 (Q)
    { 0x3F, 0x66, 0x66, 0x3E, 0x36, 0x66, 0x67, 0x00},   // U+0052 (R)
    { 0x1E, 0x33, 0x07, 0x0E, 0x38, 0x33, 0x1E, 0x00},   // U+0053 (S)
    { 0x3F, 0x2D, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00},   // U+0054 (T)
    { 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x3F, 0x00},   // U+0055 (U)
    { 0x33, 0x33, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00},   // U+0056 (V)
    { 0x63, 0x63, 0x63, 0x6B, 0x7F, 0x77, 0x63, 0x00},   // U+0057 (W)
    { 0x63, 0x63, 0x36, 0x1C, 0x1C, 0x36, 0x63, 0x00},   // U+0058 (X)
    { 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x0C, 0x1E, 0x00},   // U+0059 (Y)
    { 0x7F, 0x63, 0x31, 0x18, 0x4C, 0x66, 0x7F, 0x00},   // U+005A (Z)
    { 0x1E, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1E, 0x00},   // U+005B ([)
    { 0x03, 0x06, 0x0C, 0x18, 0x30, 0x60, 0x40, 0x00},   // U+005C (\)
    { 0x1E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1E, 0x00},   // U+005D (])
    { 0x08, 0x1C, 0x36, 0x63, 0x00, 0x00, 0x00, 0x00},   // U+005E (^)
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF},   // U+005F (_)
    { 0x0C, 0x0C, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0060 (`)
    { 0x00, 0x00, 0x1E, 0x30, 0x3E, 0x33, 0x6E, 0x00},   // U+0061 (a)
    { 0x07, 0x06, 0x06, 0x3E, 0x66, 0x66, 0x3B, 0x00},   // U+0062 (b)
    { 0x00, 0x00, 0x1E, 0x33, 0x03, 0x33, 0x1E, 0x00},   // U+0063 (c)
    { 0x38, 0x30, 0x30, 0x3e, 0x33, 0x33, 0x6E, 0x00},   // U+0064 (d)
    { 0x00, 0x00, 0x1E, 0x33, 0x3f, 0x03, 0x1E, 0x00},   // U+0065 (e)
    { 0x1C, 0x36, 0x06, 0x0f, 0x06, 0x06, 0x0F, 0x00},   // U+0066 (f)
    { 0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x1F},   // U+0067 (g)
    { 0x07, 0x06, 0x36, 0x6E, 0x66, 0x66, 0x67, 0x00},   // U+0068 (h)
    { 0x0C, 0x00, 0x0E, 0x0C, 0x0C, 0x0C, 0x1E, 0x00},   // U+0069 (i)
    { 0x30, 0x00, 0x30, 0x30, 0x30, 0x33, 0x33, 0x1E},   // U+006A (j)
    { 0x07, 0x06, 0x66, 0x36, 0x1E, 0x36, 0x67, 0x00},   // U+006B (k)
    { 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1E, 0x00},   // U+006C (l)
    { 0x00, 0x00, 0x33, 0x7F, 0x7F, 0x6B, 0x63, 0x00},   // U+006D (m)
    { 0x00, 0x00, 0x1F, 0x33, 0x33, 0x33, 0x33, 0x00},   // U+006E (n)
    { 0x00, 0x00, 0x1E, 0x33, 0x33, 0x33, 0x1E, 0x00},   // U+006F (o)
    { 0x00, 0x00, 0x3B, 0x66, 0x66, 0x3E, 0x06, 0x0F},   // U+0070 (p)
    { 0x00, 0x00, 0x6E, 0x33, 0x33, 0x3E, 0x30, 0x78},   // U+0071 (q)
    { 0x00, 0x00, 0x3B, 0x6E, 0x66, 0x06, 0x0F, 0x00},   // U+0072 (r)
    { 0x00, 0x00, 0x3E, 0x03, 0x1E, 0x30, 0x1F, 0x00},   // U+0073 (s)
    { 0x08, 0x0C, 0x3E, 0x0C, 0x0C, 0x2C, 0x18, 0x00},   // U+0074 (t)
    { 0x00, 0x00, 0x33, 0x33, 0x33, 0x33, 0x6E, 0x00},   // U+0075 (u)
    { 0x00, 0x00, 0x33, 0x33, 0x33, 0x1E, 0x0C, 0x00},   // U+0076 (v)
    { 0x00, 0x00, 0x63, 0x6B, 0x7F, 0x7F, 0x36, 0x00},   // U+0077 (w)
    { 0x00, 0x00, 0x63, 0x36, 0x1C, 0x36, 0x63, 0x00},   // U+0078 (x)
    { 0x00, 0x00, 0x33, 0x33, 0x33, 0x3E, 0x30, 0x1F},   // U+0079 (y)
    { 0x00, 0x00, 0x3F, 0x19, 0x0C, 0x26, 0x3F, 0x00},   // U+007A (z)
    { 0x38, 0x0C, 0x0C, 0x07, 0x0C, 0x0C, 0x38, 0x00},   // U+007B ({)
    { 0x18, 0x18, 0x18, 0x00, 0x18, 0x18, 0x18, 0x00},   // U+007C (|)
    { 0x07, 0x0C, 0x0C, 0x38, 0x0C, 0x0C, 0x07, 0x00},   // U+007D (})
    { 0x6E, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+007E (~)
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}    // U+007F
};


#endif
