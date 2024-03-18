/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** room_recov
*/

#include "my.h"

int add_room(room_t **room, char *arg, char status)
{
    if ((*room) == NULL) {
        (*room) = malloc(sizeof(room_t));
        (*room)->status = status;
        (*room)->name = my_strtok(arg, " \t\n");
        (*room)->x = my_getnbr(my_strtok(NULL, " \t\n"));
        (*room)->y = my_getnbr(my_strtok(NULL, " \t\n"));
        (*room)->next = NULL;
        return OK;
    }
    return add_room(&(*room)->next, arg, status);
}
