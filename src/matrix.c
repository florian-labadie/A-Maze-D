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

static int malloc_matrix(matrix_t **matrix, int len)
{
    (*matrix) = malloc(sizeof(matrix_t));
    (*matrix)->rooms_nbr = len;
    (*matrix)->matrix = malloc(sizeof(int *) * len);
    (*matrix)->names = malloc(sizeof(char *) * (len + 1));
    (*matrix)->bfs = NULL;
    (*matrix)->names[len] = NULL;
    (*matrix)->start_room = -1;
    (*matrix)->end_room = -1;
    for (int i = 0; i < (*matrix)->rooms_nbr; i++) {
        (*matrix)->matrix[i] = malloc(sizeof(int) *
                                            (*matrix)->rooms_nbr);
        for (int j = 0; j < (*matrix)->rooms_nbr; j++)
            (*matrix)->matrix[i][j] = 0;
    }
    if (!(*matrix) || !(*matrix)->names || !(*matrix)->matrix)
        return -KO;
    return len;
}

static int get_rooms(matrix_t **matrix, room_t *room)
{
    int len = 0;

    if (!room)
        return KO;
    len = malloc_matrix(matrix, number_of_rooms(room));
    if (len == -KO)
        return KO;
    for (int i = 0; i < len; room = room->next) {
        (*matrix)->names[i] = my_strdup(room->name);
        if (room->status == START)
            (*matrix)->start_room = i;
        if (room->status == END)
            (*matrix)->end_room = i;
        i++;
    }
    if ((*matrix)->start_room < 0 || (*matrix)->end_room < 0) {
        my_put_errstr("Error : no START or no END room found\n");
        return KO;
    }
    return OK;
}

static int put_tunnels_in_matrix(matrix_t **matrix, tunnels_t *tunnels)
{
    int room1 = -KO;
    int room2 = -KO;

    if (!tunnels)
        return KO;
    for (; tunnels; tunnels = tunnels->next) {
        room1 = get_room_pos((*matrix)->names, tunnels->room1);
        room2 = get_room_pos((*matrix)->names, tunnels->room2);
        if (room1 == -KO || room2 == -KO)
            return KO;
        (*matrix)->matrix[room1][room2] += 1;
        (*matrix)->matrix[room2][room1] += 1;
    }
    return OK;
}

int init_matrix(amazed_t *amazed)
{
    if (!amazed)
        return KO;
    if (get_rooms(&amazed->matrix, amazed->room) == KO)
        return KO;
    if (put_tunnels_in_matrix(&amazed->matrix, amazed->tunnels) == KO)
        return KO;
    return OK;
}
