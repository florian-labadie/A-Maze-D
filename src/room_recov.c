/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** room_recov
*/

#include "my.h"

int create_ll(room_t **room, char *arg)
{
    if ((*room) == NULL) {
        (*room) = malloc(sizeof(room_t));
        (*room)->name = my_strtok(arg, " \t\n");
        (*room)->x = my_getnbr(my_strtok(NULL, " \t\n"));
        (*room)->y = my_getnbr(my_strtok(NULL, " \t\n"));
        (*room)->next = NULL;
        return OK;
    }
    return create_ll(&(*room)->next, arg);
}