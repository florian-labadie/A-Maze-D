/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-robotfactory-florian.labadie
** File description:
** parsing
*/

#include "my.h"

static int check_blankline(char *line)
{
    for (int i = 0; line[i] != '\0'; i += 1) {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return ERR;
    }
    return OK;
}

static int put_robot(amazed_t *amazed, char *line)
{
    if (!amazed)
        amazed = malloc(sizeof(amazed_t));
    amazed->nb_robot = my_getnbr(line);
    if (amazed->nb_robot == 0 && line[0] != '0')
        return KO;
    return OK;
}

static int get_status(room_status_t *room, char *line)
{
    char *tmp = my_strdup(line);

    if (!tmp)
        return 84;
    if (my_strcmp(my_strtok(tmp, " \t\n"), START_STR) == 0) {
        *room = START;
        return OK;
    }
    if (my_strcmp(my_strtok(tmp, " \t\n"), END_STR) == 0) {
        *room = END;
        return OK;
    }
    return KO;
}

static void change_recovery(char *line, recovery_t *recovery)
{
    if (*recovery != ROOM)
        return;
    for (int i = 0; line[i] != '\0'; i += 1) {
        if (line[i] == '-') {
            *recovery = TUNNEL;
            return;
        }
    }
}

static int put_datas(amazed_t *amazed, char *line, recovery_t *recovery,
    room_status_t *room)
{
    if (*recovery == TUNNEL && put_tunnel(amazed, line) == KO)
        return KO;
    if (*recovery == ROOM && put_room(amazed, room, line) == KO)
        return KO;
    if (*recovery == ROBOT && put_robot(amazed, line) == KO)
        return KO;
    return OK;
}

int parse(amazed_t *amazed)
{
    char *line = NULL;
    size_t len = 0;
    recovery_t recovery = ROBOT;
    room_status_t room = NONE;

    while ((getline(&line, &len, stdin)) != ERR) {
        check_commentary(&line);
        if (check_blankline(line) == OK || get_status(&room, line) == OK)
            continue;
        change_recovery(line, &recovery);
        if (put_datas(amazed, line, &recovery, &room) == KO)
            return KO;
        if (display(amazed, &recovery) == KO)
            return KO;
    }
    free(line);
    return OK;
}
