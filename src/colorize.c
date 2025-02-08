#include "colorize.h"

Color* color_from_rgb(const char* rgb) {
    int r, g, b;
    if (sscanf(rgb, "%d,%d,%d", &r, &g, &b) != 3) {
        return NULL;
    }

    Color* color = (Color*)malloc(sizeof(Color));
    if (color == NULL) return NULL;
    color->r = (unsigned char)r;
    color->g = (unsigned char)g;
    color->b = (unsigned char)b;
    return color;
}

Color* color_from_hex(const char* hex) {
    if (hex[0] != '#' || strlen(hex) != 7) return NULL;

    int r, g, b;
    if (sscanf(hex + 1, "%2x%2x%2x", &r, &g, &b) != 3) {
        return NULL;
    }

    Color* color = (Color*)malloc(sizeof(Color));
    if (color == NULL) return NULL;
    color->r = (unsigned char)r;
    color->g = (unsigned char)g;
    color->b = (unsigned char)b;
    return color;
}

void color_free(Color* color) {
    if (color != NULL) {
        free(color);
    }
}

char* apply_color(const char* text, const char* color) {
    Color* c = color_from_rgb(color);
    if (c == NULL) {
        c = color_from_hex(color);
    }

    if (c == NULL) return strdup(text);

    char* result = (char*)malloc(strlen(text) + 20);
    if (result == NULL) {
        color_free(c);
        return NULL;
    }

    sprintf(result, "\x1b[38;2;%d;%d;%dm%s\x1b[0m", c->r, c->g, c->b, text);
    color_free(c);
    return result;
}

char* apply_bg_color(const char* text, const char* color) {
    Color* c = color_from_rgb(color);
    if (c == NULL) {
        c = color_from_hex(color);
    }

    if (c == NULL) return strdup(text);

    char* result = (char*)malloc(strlen(text) + 20);
    if (result == NULL) {
        color_free(c);
        return NULL;
    }

    sprintf(result, "\x1b[48;2;%d;%d;%dm%s\x1b[0m", c->r, c->g, c->b, text);
    color_free(c);
    return result;
}

char* apply_bold(const char* text) {
    char* result = (char*)malloc(strlen(text) + 10);
    if (result == NULL) return NULL;
    sprintf(result, "\x1b[1m%s\x1b[0m", text);
    return result;
}

char* apply_italic(const char* text) {
    char* result = (char*)malloc(strlen(text) + 10);
    if (result == NULL) return NULL;
    sprintf(result, "\x1b[3m%s\x1b[0m", text);
    return result;
}

char* apply_underline(const char* text) {
    char* result = (char*)malloc(strlen(text) + 10);
    if (result == NULL) return NULL;
    sprintf(result, "\x1b[4m%s\x1b[0m", text);
    return result;
}

char* apply_strikethrough(const char* text) {
    char* result = (char*)malloc(strlen(text) + 10);
    if (result == NULL) return NULL;
    sprintf(result, "\x1b[9m%s\x1b[0m", text);
    return result;
}

char* apply_dim(const char* text) {
    char* result = (char*)malloc(strlen(text) + 10);
    if (result == NULL) return NULL;
    sprintf(result, "\x1b[2m%s\x1b[0m", text);
    return result;
}

char* apply_invert(const char* text) {
    char* result = (char*)malloc(strlen(text) + 10);
    if (result == NULL) return NULL;
    sprintf(result, "\x1b[7m%s\x1b[0m", text);
    return result;
}