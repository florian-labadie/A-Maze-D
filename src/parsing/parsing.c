/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-robotfactory-florian.labadie
** File description:
** parsing
*/

#include "my.h"

static int rm_blankline(char *line)
{
    for (int i = 0; line[i] != '\0'; i += 1) {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return ERR;
    }
    return OK;
}

static int put_robot(amazed_t *amazed, char *recovery, char *line)
{
    if (!amazed)
        amazed = malloc(sizeof(amazed_t));
    amazed->nb_robot = my_getnbr(line);
    if (amazed->nb_robot == 0 && line[0] != '0')
        return KO;
    *recovery = ROOM;
    return OK;
}

static int get_status(char *room, char *line)
{
    if (my_strcmp(line, START_STR) == 0) {
        *room = START;
        return OK;
    }
    if (my_strcmp(line, END_STR) == 0) {
        *room = END;
        return OK;
    }
    return KO;
}

int parse(amazed_t *amazed)
{
    char *line = NULL;
    size_t len = 0;
    char recovery = ROBOT;
    char room = NONE;

    while ((getline(&line, &len, stdin)) != ERR) {
        check_commentary(&line);
        if (rm_blankline(line) == OK || get_status(&room, line) == OK)
            continue;
        if (recovery == ROBOT && put_robot(amazed, &recovery, line) == KO)
            return KO;
        room = NONE;
    }
    free(line);
    return OK;
}
