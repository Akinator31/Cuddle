/*
** EPITECH PROJECT, 2025
** G-AIA-200-TLS-2-1-cuddle-pavel.de-wavrechin
** File description:
** df_head
*/

#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dataframe.h"
#include "errors.h"
#include "utils.h"

dataframe_t *df_head(
    dataframe_t *dataframe,
    int nb_rows)
{
    dataframe_t *new_dataframe = NULL;

    if (!dataframe || nb_rows < 0)
        return write_error(NO_DATAFRAME, NULL, -1);
    if ((size_t)nb_rows > dataframe->nb_rows)
        nb_rows = (int)dataframe->nb_rows;
    new_dataframe = create_dataframe((size_t)nb_rows,
        dataframe->nb_columns, dataframe->delimiter);
    for (size_t i = 0; i < dataframe->nb_columns; i++)
        copy_column_content_from_head(&dataframe->columns[i],
            &new_dataframe->columns[i], (size_t)nb_rows);
    return new_dataframe;
}
