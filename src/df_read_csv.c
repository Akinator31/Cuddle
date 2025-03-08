/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_read_csv
*/

#include <stddef.h>
#include <stdio.h>
#include "cuddle.h"
#include "dataframe.h"
#include "garbage_collector.h"

static char *read_file(FILE *fptr, size_t bytes)
{
    char *content = NULL;
    long read_bytes = 0;

    content = my_malloc(bytes);
    read_bytes = fread(content, 1, bytes, fptr);
    printf("%d\n", feof(fptr));
}

dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    FILE *fptr = NULL;
    char *file_content = NULL;

    fptr = fopen(filename, READ_ONLY);
    read_file(fptr, sizeof(char) * 50);
}
