/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** free_amazed
*/

#include "my.h"

static int free_room(room_t **room)
{
    if (*room != NULL) {
        if ((*room)->next)
            free_room(&(*room)->next);
        free((*room)->name);
        free(*room);
    }
    return OK;
}

static int free_tunnels(tunnels_t **tunnels)
{
    if (*tunnels != NULL) {
        if ((*tunnels)->next)
            free_tunnels(&(*tunnels)->next);
        free((*tunnels)->room1);
        free((*tunnels)->room2);
        if (*tunnels != NULL)
            free(*tunnels);
    }
    return OK;
}

static int free_matrix(matrix_t *matrix)
{
    if (matrix != NULL) {
        for (int i = 0; matrix->names && matrix->names[i]; i += 1) {
            free(matrix->names[i]);
        }
        free(matrix->names);
        for (int i = 0; matrix->matrix && i < matrix->rooms_nbr; i += 1)
            free(matrix->matrix[i]);
        free(matrix->matrix);
        if (matrix != NULL) {
            free(matrix);
        }
    }
    return OK;
}

int free_amazed(amazed_t *amazed, int ret)
{
    if (amazed != NULL) {
        if (amazed->room != NULL && amazed->room->next)
            free_room(&amazed->room);
        if (amazed->tunnels != NULL && amazed->tunnels->next)
            free_tunnels(&amazed->tunnels);
        free_matrix(amazed->matrix);
    }
    return ret == 0 || ret == 84 ? ret : KO;
}
