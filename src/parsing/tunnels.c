/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** tunnels
*/

#include "my.h"

static int number_of_rooms(room_t *room)
{
    int len = 0;

    for (room_t *tmp = room; tmp; tmp = tmp->next)
        len++;
    return len;
}

static int malloc_matrix(matrix_t **matrix, int len)
{
    (*matrix) = malloc(sizeof(matrix_t));
    (*matrix)->rooms_nbr = len;
    (*matrix)->matrix = malloc(sizeof(int *) * len);
    (*matrix)->names = malloc(sizeof(char *) * (len + 1));
    (*matrix)->bfs = NULL;
    (*matrix)->names[len] = NULL;
    (*matrix)->start_room = -1;
    (*matrix)->end_room = -1;
    for (int i = 0; i < (*matrix)->rooms_nbr; i++) {
        (*matrix)->matrix[i] = malloc(sizeof(int) *
                                            (*matrix)->rooms_nbr);
        for (int j = 0; j < (*matrix)->rooms_nbr; j++)
            (*matrix)->matrix[i][j] = 0;
    }
    if (!(*matrix) || !(*matrix)->names || !(*matrix)->matrix)
        return -KO;
    return len;
}

static int get_rooms(matrix_t **matrix, room_t *room)
{
    int len = 0;

    if (!room)
        return KO;
    len = malloc_matrix(matrix, number_of_rooms(room));
    if (len == -KO)
        return KO;
    for (int i = 0; i < len; room = room->next) {
        (*matrix)->names[i] = my_strdup(room->name);
        if (room->status == START)
            (*matrix)->start_room = i;
        if (room->status == END)
            (*matrix)->end_room = i;
        i++;
    }
    if ((*matrix)->start_room < 0 || (*matrix)->end_room < 0)
        return my_put_errstr("Error : no START or no END room found\n");
    return OK;
}

static int is_a_room(char **names, char *room)
{
    for (int i = 0; names[i]; i++)
        if (my_strcmp(names[i], room) == OK)
            return OK;
    return KO;
}

static int is_good_room(char **names, char *room)
{
    for (int i = 0; i == 0 || room[i] != '\0'; i += 1) {
        if (!room || alpha_num(room[i]) == KO)
            return KO;
    }
    if (is_a_room(names, room) == KO)
        return KO;
    return OK;
}

static int check_tunnel(char **names, char *line)
{
    char *tmp = my_strdup(line);

    for (int i = 0; i < 2; i++) {
    tmp = my_strtok(tmp, "-");
    if (is_good_room(names, tmp) == KO) {
        my_put_errstr("Your tunnels name must be an actual room name !\n");
        return KO;
    }
    }
    return my_strtok(NULL, " \t\n") ? KO : OK;
}

static void add_tunnel(tunnels_t **tunnels, char *line)
{
    if ((*tunnels) == NULL) {
        (*tunnels) = malloc(sizeof(tunnels_t));
        (*tunnels)->room1 = my_strdup(my_strtok(line, "- \t\n"));
        (*tunnels)->room2 = my_strdup(my_strtok(NULL, "- \t\n"));
        (*tunnels)->display = true;
        (*tunnels)->next = NULL;
        return;
    }
    return add_tunnel(&(*tunnels)->next, line);
}

int put_tunnel(amazed_t *amazed, char *line)
{
    if (!amazed)
        return KO;
    if (!amazed->room)
        return my_put_errstr("Error : No room\n");
    if (!amazed->matrix)
        if (get_rooms(&amazed->matrix, amazed->room) == KO)
            return KO;
    if (check_tunnel(amazed->matrix->names, line) == KO)
        return KO;
    add_tunnel(&amazed->tunnels, line);
    return OK;
}
