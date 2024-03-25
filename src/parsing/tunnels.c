/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** tunnels
*/

#include "my.h"

static int check_tunnel(char *line)
{
    char *tmp = my_strdup(line);

    tmp = my_strtok(tmp, "-");
    for (int i = 0; i == 0 || tmp[i] != '\0'; i += 1) {
        if (!tmp || alpha_num(tmp[i]) == KO) {
            my_put_errstr("Your tunnels name must be an alphanumeric !\n");
            return KO;
        }
    }
    tmp = my_strtok(NULL, " \t\n");
    for (int i = 0; i == 0 || tmp[i] != '\0'; i += 1) {
        if (!tmp || alpha_num(tmp[i]) == KO) {
            my_put_errstr("Your tunnels name must be an alphanumeric !\n");
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
    if (check_tunnel(line) == KO)
        return KO;
    add_tunnel(&amazed->tunnels, line);
    return OK;
}
