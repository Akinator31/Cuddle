/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** cuddle
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "garbage_collector.h"
#include "errors.h"

// dissociate warnings and errors to add colors
static const char *const error_strings[] = {"Incorrect line",
    "File is empty", "File columns are uneven"};
static const char *const warning_strings[] = {"Not a csv file"};

void *write_error(
    int error_code,
    const char *before,
    ssize_t number)
{
    const char *string = NULL;

    if (error_code < WARNINGS_START) {
        string = error_strings[error_code];
        printf("\033[31m");
    } else {
        string = warning_strings[error_code - WARNINGS_START];
        printf("\033[36m");
    }
    if (before)
        printf("%s:", before);
    if (number != -1)
        printf("%ld:", number);
    printf(" %s\033[0m\n", string);
    return NULL;
}

void *lib_exit(void)
{
    free_garbage();
    return NULL;
}
