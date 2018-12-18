
#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <stdint.h>

#if TREZOR_MODEL == T

// ILI9341V, GC9307 and ST7789V drivers support 240px x 320px display resolution
#define MAX_DISPLAY_RESX    240
#define MAX_DISPLAY_RESY    320
#define DISPLAY_RESX        240
#define DISPLAY_RESY        240

#elif TREZOR_MODEL == 1

#define MAX_DISPLAY_RESX    128
#define MAX_DISPLAY_RESY    64
#define DISPLAY_RESX        128
#define DISPLAY_RESY        64

#else
#error Unknown TREZOR Model
#endif

#define FONT_BPP            4
#define FONT_SIZE           20
#define AVATAR_IMAGE_SIZE   144
#define LOADER_ICON_SIZE    64

#define RGB16(R, G, B)      ((R & 0xF8) << 8) | ((G & 0xFC) << 3) | ((B & 0xF8) >> 3)
#define COLOR_WHITE         0xFFFF
#define COLOR_BLACK         0x0000

#ifdef TREZOR_FONT_NORMAL_ENABLE
#define FONT_NORMAL         (-1)
#endif
#ifdef TREZOR_FONT_BOLD_ENABLE
#define FONT_BOLD           (-2)
#endif
#ifdef TREZOR_FONT_MONO_ENABLE
#define FONT_MONO           (-3)
#endif
#ifdef TREZOR_FONT_MONO_BOLD_ENABLE
#define FONT_MONO_BOLD      (-4)
#endif

// provided by port

void display_init(void);
void display_refresh(void);
void display_save(const char *prefix);

// provided by common

void display_clear(void);

void display_bar(int x, int y, int w, int h, uint16_t c);
void display_bar_radius(int x, int y, int w, int h, uint16_t c, uint16_t b, uint8_t r);

void display_image(int x, int y, int w, int h, const void *data, int datalen);
void display_avatar(int x, int y, const void *data, int datalen, uint16_t fgcolor, uint16_t bgcolor);
void display_icon(int x, int y, int w, int h, const void *data, int datalen, uint16_t fgcolor, uint16_t bgcolor);
void display_loader(uint16_t progress, int yoffset, uint16_t fgcolor, uint16_t bgcolor, const uint8_t *icon, uint32_t iconlen, uint16_t iconfgcolor);

#ifndef TREZOR_PRINT_DISABLE
void display_print_color(uint16_t fgcolor, uint16_t bgcolor);
void display_print(const char *text, int textlen);
void display_printf(const char *fmt, ...) __attribute__ ((__format__ (__printf__, 1, 2)));
#endif

void display_text(int x, int y, const char *text, int textlen, int font, uint16_t fgcolor, uint16_t bgcolor);
void display_text_center(int x, int y, const char *text, int textlen, int font, uint16_t fgcolor, uint16_t bgcolor);
void display_text_right(int x, int y, const char *text, int textlen, int font, uint16_t fgcolor, uint16_t bgcolor);
int display_text_width(const char *text, int textlen, int font);

void display_qrcode(int x, int y, const char *data, int datalen, uint8_t scale);

void display_offset(int set_xy[2], int *get_x, int *get_y);
int display_orientation(int degrees);
int display_backlight(int val);
void display_fade(int start, int end, int delay);

#endif
