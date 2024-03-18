/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** amazed
*/

#include "my.h"

int launch_amazed(void)
{
    amazed_t *amazed = malloc(sizeof(amazed_t));

    if (amazed == NULL)
        return KO;
    if (parse(amazed) == KO)
        return KO;
    return OK;
}
