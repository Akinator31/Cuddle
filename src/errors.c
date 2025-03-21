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

static const char *const error_strings[] = {"Incorrect line",
    "File is empty", "File columns are uneven", "Column not found",
    "Bad downcast, can't change type", "Apply function is NULL"};
static const char *const warning_strings[] = {"Not a csv file",
    "Duplicate column name"};

void *write_error(
    int error_code,
    const char *before,
    ssize_t number)
{
    return NULL;
}

void *lib_finish(void *ptr)
{
    forget_garbage();
    return ptr;
}

void *lib_exit(void)
{
    free_garbage();
    return NULL;
}
