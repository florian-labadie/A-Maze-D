/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** amazed
*/

#ifndef AMAZED_H_
    #define AMAZED_H_
    #define COMMENT_CHAR '#'

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
} amazed_t;

int launch_amazed(void);
int parse(amazed_t *amazed);
void check_commentary(char **line);
int put_room(amazed_t *amazed, room_status_t *status, char *line);
int display(amazed_t *amazed, recovery_t *rec);

#endif /* !AMAZED_H_ */
