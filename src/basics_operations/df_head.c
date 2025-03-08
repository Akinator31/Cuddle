/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_head
*/

#include <stdlib.h>
#include <assert.h>
#include "dataframe.h"

dataframe_t *df_head(
    dataframe_t *dataframe,
    int nb_rows)
{
    dataframe_t *new_dataframe = malloc(sizeof(dataframe_t));

    if (!dataframe)
        return NULL;
}
