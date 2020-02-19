//
// Created by carl- on 2020/2/13.
//

#ifndef DATASTRUCTURE_PRINTINCOLOR_H

/**
 * Windows API
 * color used by printf_in_color_win
 */
enum console_color {
    Black = 0,
    White = 7,
    Gray = 8,
    Red = 4,
    Green = 2,
    Blue = 1,
    Yellow = 6,
    Purple = 5,
    Aqua = 3
};

/**
 * Print string in color (Windows API),
 * then restore to the original state
 * @param string
 * @param color
 */
void printf_in_color_win(enum console_color color, char *str);

/**
 * Print string in red
 */

void printf_in_red_ansi(char *str);

char *str_joint(char *a, char *b);

#define DATASTRUCTURE_PRINTINCOLOR_H

#endif //DATASTRUCTURE_PRINTINCOLOR_H
