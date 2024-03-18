/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** room
*/

#ifndef ROOM_H_
    #define ROOM_H_

    #define START_STR "##start"
    #define END_STR "##end"

    #include "my.h"

typedef enum room_status_s {
    NONE,
    START,
    END
} room_status_t;

typedef struct room_s {
    char status;
    char *name;
    int x;
    int y;
    struct room_s *next;
} room_t;

#endif /* !ROOM_H_ */
