/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** main
*/

#include "dataframe.h"
#include <stdio.h>
#include <sys/ucontext.h>

int main(__attribute__((unused))int argc, char **argv)
{
    dataframe_t *data = df_read_csv(argv[1], ",");

    if (!data)
        return 84;
    df_write_csv(data, argv[2]);
    df_free(data);
    return 0;
}
