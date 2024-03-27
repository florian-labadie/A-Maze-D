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

static void recurse(matrix_t *matrix, bfs_t **bfs, int start_room)
{
    int current_room = -1;

    (*bfs)->visited[start_room] = true;
    (*bfs)->queue[++((*bfs)->rear)] = start_room;
    while ((*bfs)->front < (*bfs)->rear) {
        current_room = (*bfs)->queue[++((*bfs)->front)];
        for (int i = 0; i < matrix->rooms_nbr; i++) {
            if (matrix->matrix[current_room][i] && !(*bfs)->visited[i]) {
                (*bfs)->visited[i] = true;
                (*bfs)->queue[++((*bfs)->rear)] = i;
                (*bfs)->parent[i] = current_room;
            }
        }
    }
}

static void print_shortest_path(bfs_t *bfs, int end_room)
{
    int current_room = end_room;

    while (current_room != -1) {
        current_room = bfs->parent[current_room];
    }
}

int my_bfs(matrix_t *matrix)
{
    if (!matrix->bfs)
        set_up_bfs(&matrix->bfs, matrix->rooms_nbr);
    recurse(matrix, &matrix->bfs, matrix->start_room);
    print_shortest_path(matrix->bfs, matrix->end_room);
    return 0;
}

