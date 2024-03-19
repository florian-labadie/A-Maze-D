/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** room
*/

#include "my.h"

static int check_room(char *line)
{
    char *tmp = my_strdup(line);

    tmp = my_strtok(tmp, " \t\n");
    for (int i = 0; tmp[i] != '\0'; i += 1) {
        if (alpha_num(tmp[i]) == KO)
            return KO;
    }
    tmp = my_strtok(NULL, " \t\n");
    for (int i = 0; tmp[i] != '\0'; i += 1) {
        if (numeric(tmp[i]) == KO)
            return KO;
    }
    tmp = my_strtok(NULL, " \t\n");
    for (int i = 0; tmp[i] != '\0'; i += 1) {
        if (numeric(tmp[i]) == KO)
            return KO;
    }
    return my_strtok(NULL, " \t\n") ? KO : OK;
}

int add_room(room_t **room, char *arg, room_status_t status)
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

int put_room(amazed_t *amazed, room_status_t *status, char *line)
{
    if (check_room(line) == KO)
        return KO;
    add_room(&amazed->room, line, *status);
    *status = NONE;
    return OK;
}
