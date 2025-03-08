/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** main
*/

#include "dataframe.h"
#include "garbage_collector.h"
#include <stdio.h>
#include <sys/ucontext.h>

int main(void)
{
    dataframe_t *data = df_read_csv("data_medium.csv", ",");

    if (!data) {
        printf("ERROR");
        return 84;
    }
    printf("%s\n", data->columns[0]->column_content[0]);
    free_garbage();
    return 0;
}
