#ifndef COLOREX_C_LIBRARY_H
#define COLOREX_C_LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    unsigned char r, g, b;
} Color;

Color* color_from_rgb(const char* rgb);
Color* color_from_hex(const char* hex);
void color_free(Color* color);
char* apply_color(const char* text, const char* color);
char* apply_bg_color(const char* text, const char* color);
char* apply_bold(const char* text);
char* apply_italic(const char* text);
char* apply_underline(const char* text);
char* apply_strikethrough(const char* text);
char* apply_dim(const char* text);
char* apply_invert(const char* text);

#endif //COLOREX_C_LIBRARY_H
