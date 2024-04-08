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
    if (put_tunnels_in_matrix(&amazed->matrix, amazed->tunnels) == KO)
        return KO;
    return OK;
}
