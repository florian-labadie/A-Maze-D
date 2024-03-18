/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_putarray
*/

#include "my.h"

void my_putarray(char const *const *array)
{
    if (!array)
        return;
    for (int i = 0; array[i] != NULL; i += 1)
        my_putstr(array[i]);
}
