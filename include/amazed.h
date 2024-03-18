/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** amazed
*/

#ifndef AMAZED_H_
    #define AMAZED_H_
    #define COMMENT_CHAR '#'
    #define COMMAND_STR "##"

    #include "my.h"
    #include <stdio.h>

typedef struct room_s {
    char *name;
    int x;
    int y;
    struct room_s *next;
} room_t;

typedef struct matrix_s {
    int **matrix;
    int rooms_number;
} matrix_t;

typedef struct amazed_s {
    int nb_robot;
    room_t *room;
    matrix_t *matrix;
} amazed_t;

int launch_amazed(void);
int parse(amazed_t *amazed);
void check_commentary(char **line);

#endif /* !AMAZED_H_ */
