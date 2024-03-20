/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** amazed
*/

#ifndef AMAZED_H_
    #define AMAZED_H_

    #include "room.h"
    #include "tunnel.h"

typedef enum recovery_s {
    ROBOT,
    ROOM,
    TUNNEL
} recovery_t;

typedef struct amazed_s {
    int nb_robot;

    room_t *room;
    tunnels_t *tunnels;

    matrix_t *matrix;
} amazed_t;

#endif /* !AMAZED_H_ */
