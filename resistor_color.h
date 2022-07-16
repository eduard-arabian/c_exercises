#ifndef RESISTOR_COLOR_H_
#define RESISTOR_COLOR_H_

typedef enum {
    BLACK, BROWN, RED, ORANGE, YELLOW,
    GREEN, BLUE, VIOLET, GREY, WHITE
} resistor_band_t;

int color_code(resistor_band_t color);
const resistor_band_t *colors(void);

#endif  // RESISTOR_COLOR_H_
