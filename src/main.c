/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** main
*/

#include "dataframe.h"
#include "garbage_collector.h"

int main(void)
{
    df_read_csv("test.csv", ",");
    free_garbage();
    return 0;
}
