//
// Created by carl- on 2020/2/13.
//

#ifndef DATASTRUCTURE_PRINTINCOLOR_H

/**
 * color used by printf_in_color_win
 */
enum console_color {
    Red = 4,
    Green = 2,
    Blue = 1
};

/**
 * Print string in color (Windows API),
 * then restore to the original state
 * @param string
 * @param color
 */
void printf_in_color_win(enum console_color color, char *str);

void printf_in_red_ansi(char *str);

#define DATASTRUCTURE_PRINTINCOLOR_H

#endif //DATASTRUCTURE_PRINTINCOLOR_H
