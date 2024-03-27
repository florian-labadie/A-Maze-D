/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** tunnel
*/

#ifndef TUNNEL_H_
    #define TUNNEL_H_

    #include <stdbool.h>

typedef struct paths_s{
    int *path;
    int path_len;
    struct paths_s *next;
} paths_t;

typedef struct store_s {
    int *dist;
    int *parent;
    bool *checker;
} store_t;

typedef struct bfs_s{
    bool *visited;
    int *queue;
    int *parent;
    int rear;
    int front;
}  bfs_t;

typedef struct matrix_s {
    char **names;
    int rooms_nbr;

    int start_room;
    int end_room;

    int **matrix;

    paths_t *paths;
    bfs_t *bfs;
    store_t *store;
} matrix_t;

typedef struct tunnels_s {
    bool display;
    char *room1;
    char *room2;
    struct tunnels_s *next;
} tunnels_t;


#endif /* !TUNNEL_H_ */
