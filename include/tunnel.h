/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** tunnel
*/

#ifndef TUNNEL_H_
    #define TUNNEL_H_

    #include "my.h"

    #include <stdbool.h>

typedef struct matrix_s {
    int **matrix;
    int rooms_nbr;
} matrix_t;

typedef struct tunnels_s {
    bool display;
    char *room1;
    char *room2;
    struct tunnels_s *next;
} tunnels_t;

#endif /* !TUNNEL_H_ */
