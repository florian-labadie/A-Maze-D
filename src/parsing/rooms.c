/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** room
*/

#include "my.h"

static int check_room_name(char *tmp)
{
    for (int i = 0; i == 0 || tmp[i] != '\0'; i += 1) {
        if (!tmp || alpha_num(tmp[i]) == KO) {
            my_put_errstr("Your name must be in alpha-numeric characters!\n");
            return KO;
        }
    }
    return OK;
}

static int check_room(char *line)
{
    char *tmp = my_strdup(line);

    tmp = my_strtok(tmp, " \t\n");
    if (check_room_name(tmp) == KO)
        return KO;
    tmp = my_strtok(NULL, " \t\n");
    for (int i = 0; i == 0 || tmp[i] != '\0'; i += 1) {
        if (!tmp || numeric(tmp[i]) == KO) {
            my_put_errstr("Your x coordonate must be a number !\n");
            return KO;
        }
    }
    tmp = my_strtok(NULL, " \t\n");
    for (int i = 0; i == 0 || tmp[i] != '\0'; i += 1) {
        if (!tmp || numeric(tmp[i]) == KO) {
            my_put_errstr("Your y coordonate must be a number !\n");
            return KO;
        }
    }
    return my_strtok(NULL, " \t\n") != NULL ? KO : OK;
}

static int add_room(room_t **room, char *line, room_status_t status)
{
    if ((*room) == NULL) {
        (*room) = malloc(sizeof(room_t));
        (*room)->name = my_strdup(my_strtok(line, " \t\n"));
        (*room)->x = my_getnbr(my_strtok(NULL, " \t\n"));
        (*room)->y = my_getnbr(my_strtok(NULL, " \t\n"));
        (*room)->status = status;
        (*room)->next = NULL;
        return OK;
    }
    return add_room(&(*room)->next, line, status);
}

int put_room(amazed_t *amazed, room_status_t *status, char *line)
{
    if (check_room(line) == KO)
        return KO;
    add_room(&amazed->room, line, *status);
    *status = NONE;
    return OK;
}
