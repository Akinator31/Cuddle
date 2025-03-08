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
static const char *const error_strings[] = {"Not a csv file", "Incorrect line",
    "File is empty", "File columns are uneven"};

void *write_error(
    int error_code,
    const char *before, ssize_t number)
{
    if (before)
        printf("%s:", before);
    if (number != -1)
        printf("%ld:", number);
    printf(" %s\n", error_strings[error_code]);
    return NULL;
}

void *lib_exit(void)
{
    free_garbage();
    return NULL;
}
