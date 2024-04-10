/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** paths
*/

#include "my.h"

static int check_same_path(paths_t *path, int *parent, int len)
{
    int same = 0;

    for (int i = 0; i < len; i++) {
        if ((i == len - 1 && path->path_len > len) ||
            (i == path->path_len - 1 && len > path->path_len))
            return KO;
        if (path->path[i] == parent[i])
            same += 1;
    }
    return (same == len) ? OK : KO;
}

static int path_len(int *parent, int room)
{
    if (parent[room] == -1)
        return 1;
    return 1 + path_len(parent, parent[room]);
}

static void put_path(int **path, int *parent, int room, int len)
{
    if (parent[room] != -1)
        put_path(path, parent, parent[room], len - 1);
    (*path)[len] = room;
}

static void add_path(paths_t **path, int *parent, int len)
{
    if ((*path) == NULL) {
        (*path) = malloc(sizeof(paths_t));
        (*path)->path = malloc(sizeof(int) * len);
        for (int i = 0; i < len; i++)
            (*path)->path[i] = parent[i];
        (*path)->path_len = len;
        (*path)->next = NULL;
        return;
    }
    if (check_same_path(*path, parent, len) == OK)
        return;
    return add_path(&(*path)->next, parent, len);
}

int get_path(matrix_t *matrix, int *parent)
{
    int *path = NULL;
    int len = 0;

    if (!matrix || !parent)
        return KO;
    len = path_len(parent, matrix->end_room);
    if (len == 1) {
        matrix->bfs->path = false;
        return OK;
    }
    path = malloc(sizeof(int) * (len));
    put_path(&path, parent, matrix->end_room, len - 1);
    add_path(&matrix->paths, path, len);
    free(path);
    return OK;
}
