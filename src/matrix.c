/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** matrix
*/

#include "my.h"

int get_room_pos(char **names, char *name)
{
    int pos = -KO;

    for (int i = 0; names[i] != NULL; i++) {
        if (my_strcmp(names[i], name) == OK) {
            pos = i;
            break;
        }
    }
    return pos;
}

static int number_of_rooms(room_t *room)
{
    int len = 0;

    for (room_t *tmp = room; tmp; tmp = tmp->next)
        len++;
    return len;
}

static int malloc_matrix(amazed_t *amazed)
{
    int len = 0;

    len = number_of_rooms(amazed->room);
    amazed->matrix = malloc(sizeof(matrix_t));
    amazed->matrix->rooms_nbr = len;
    amazed->matrix->matrix = malloc(sizeof(int *) * len);
    amazed->matrix->names = malloc(sizeof(char *) * (len + 1));
    amazed->matrix->bfs = NULL;
    amazed->matrix->names[len] = NULL;
    amazed->matrix->start_room = -1;
    amazed->matrix->end_room = -1;
    for (int i = 0; i < amazed->matrix->rooms_nbr; i++) {
        amazed->matrix->matrix[i] = malloc(sizeof(int) *
                                            amazed->matrix->rooms_nbr);
        for (int j = 0; j < amazed->matrix->rooms_nbr; j++)
            amazed->matrix->matrix[i][j] = 0;
    }
    if (!amazed->matrix || !amazed->matrix->names || !amazed->matrix->matrix)
        return -KO;
    return len;
}

static int get_rooms(amazed_t *amazed)
{
    int len = 0;

    if (!amazed->room)
        return KO;
    len = malloc_matrix(amazed);
    if (len == -KO)
        return KO;
    for (int i = 0; i < len; amazed->room = amazed->room->next) {
        amazed->matrix->names[i] = my_strdup(amazed->room->name);
        if (amazed->room->status == START)
            amazed->matrix->start_room = i;
        if (amazed->room->status == END)
            amazed->matrix->end_room = i;
        i++;
    }
    if (amazed->matrix->start_room < 0 || amazed->matrix->end_room < 0)
        return KO;
    return OK;
}

static int put_tunnels_in_matrix(amazed_t *amazed)
{
    int room1 = -KO;
    int room2 = -KO;

    if (!amazed->tunnels)
        return KO;
    for (; amazed->tunnels; amazed->tunnels = amazed->tunnels->next) {
        room1 = get_room_pos(amazed->matrix->names, amazed->tunnels->room1);
        room2 = get_room_pos(amazed->matrix->names, amazed->tunnels->room2);
        if (room1 == -KO || room2 == -KO)
            return KO;
        amazed->matrix->matrix[room1][room2] += 1;
        amazed->matrix->matrix[room2][room1] += 1;
    }
    return OK;
}

int init_matrix(amazed_t *amazed)
{
    if (!amazed)
        return KO;
    if (get_rooms(amazed) == KO)
        return KO;
    if (put_tunnels_in_matrix(amazed) == KO)
        return KO;
    return OK;
}
