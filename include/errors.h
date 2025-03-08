/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** cuddle
*/

#ifndef ERRORS_H
    #define ERRORS_H

    #include <stdio.h>

enum error_codes {
    NOT_CSV,
    BAD_LINE,
    EMPTY_FILE,
    UNEVEN_LINES,
};

void *write_error(
    int error_code,
    const char *before, ssize_t number);
void *lib_exit(void);

#endif
