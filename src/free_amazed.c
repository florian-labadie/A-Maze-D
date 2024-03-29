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
        free(*tunnels);
    }
    return OK;
}

static void free_bfs(bfs_t **bfs)
{
    if (*bfs) {
        if ((*bfs)->visited)
            free((*bfs)->visited);
        if ((*bfs)->queue)
            free((*bfs)->queue);
        if ((*bfs)->parent)
            free((*bfs)->parent);
        free(*bfs);
    }
}

static void free_paths(paths_t **paths)
{
    if (*paths) {
        if ((*paths)->next)
            free_paths(&(*paths)->next);
        if ((*paths)->path)
            free((*paths)->path);
        free(*paths);
    }
}

static void free_matrix(matrix_t *matrix)
{
    if (matrix != NULL) {
        for (int i = 0; matrix->names && matrix->names[i]; i += 1)
            free(matrix->names[i]);
        free(matrix->names);
        for (int i = 0; matrix->matrix && i < matrix->rooms_nbr; i += 1)
            free(matrix->matrix[i]);
        free(matrix->matrix);
        free_bfs(&matrix->bfs);
        free_paths(&matrix->paths);
        if (matrix != NULL) {
            free(matrix);
        }
    }
}

int free_amazed(amazed_t *amazed, int ret)
{
    if (amazed != NULL) {
        free_room(&amazed->room);
        free_tunnels(&amazed->tunnels);
        free_matrix(amazed->matrix);
    }
    return ret == 0 || ret == 84 ? ret : KO;
}
