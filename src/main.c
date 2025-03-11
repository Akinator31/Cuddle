/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** main
*/

#include "dataframe.h"

int main(__attribute__((unused)) int argc, char **argv)
{
    dataframe_t *data = df_read_csv(argv[1], ",");

    dataframe_t *test = df_tail(data, 0);
    dataframe_t *test1 = df_head(data, 0);

    df_dump(data);
    printf("\n");
    df_dump(test);
    printf("\n");
    df_dump(test1);

    df_free(data);
    df_free(test);
    df_free(test1);
    return 0;
}
