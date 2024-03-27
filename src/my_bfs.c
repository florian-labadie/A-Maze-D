/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** my_bfs
*/

#include "my.h"

static void set_up_bfs(bfs_t **bfs, int rooms_nbr)
{
    *bfs = malloc(sizeof(bfs_t));
    (*bfs)->visited = malloc(sizeof(bool) * rooms_nbr);
    (*bfs)->queue = malloc(sizeof(int) * rooms_nbr);
    (*bfs)->parent = malloc(sizeof(int) * rooms_nbr);
    (*bfs)->rear = -1;
    (*bfs)->front = -1;
    for (int i = 0; i < rooms_nbr; i++) {
        (*bfs)->visited[i] = false;
        (*bfs)->queue[i] = 0;
        (*bfs)->parent[i] = -1;
    }
}

static void check_parent(matrix_t *matrix, bfs_t **bfs, int i, int current)
{
    if (matrix->matrix[current][i] && !(*bfs)->visited[i]) {
        (*bfs)->visited[i] = true;
        (*bfs)->rear += 1;
        (*bfs)->queue[(*bfs)->rear] = i;
        (*bfs)->parent[i] = current;
    }
}

static void recurse(matrix_t *matrix, bfs_t **bfs, int start_room)
{
    int current_room = -1;

    (*bfs)->visited[start_room] = true;
    (*bfs)->rear += 1;
    (*bfs)->queue[(*bfs)->rear] = start_room;
    while ((*bfs)->front < (*bfs)->rear) {
        (*bfs)->front += 1;
        current_room = (*bfs)->queue[(*bfs)->front];
        for (int i = 0; i < matrix->rooms_nbr; i++)
            check_parent(matrix, bfs, i, current_room);
    }
}

int my_bfs(matrix_t *matrix)
{
    if (!matrix->bfs)
        set_up_bfs(&matrix->bfs, matrix->rooms_nbr);
    recurse(matrix, &matrix->bfs, matrix->start_room);
    get_path(matrix, matrix->bfs->parent);
    return 0;
}
