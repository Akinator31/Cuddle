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
    BAD_LINE,
    EMPTY_FILE,
    UNEVEN_LINES,
    COLUMN_NOT_FOUND,
};

    #define WARNINGS_START 100

enum warning_codes {
    NOT_CSV = WARNINGS_START,
    DUPLICATE_COL_NAME,
};

void *write_error(
    int error_code,
    const char *before, ssize_t number);
void *lib_exit(void);
void *lib_finish(void *ptr);

#endif
