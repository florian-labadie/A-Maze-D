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

    tmp = my_strtok(line, "-");
    for (int i = 0; tmp[i] != '\0'; i += 1) {
        if (alpha_num(tmp[i]) == KO)
            return KO;
    }
    tmp = my_strtok(NULL, " \t\n");
    for (int i = 0; tmp[i] != '\0'; i += 1) {
        if (alpha_num(tmp[i]) == KO)
            return KO;
    }
    return my_strtok(NULL, " \t\n") ? KO : OK;
}

static void add_tunnel(tunnels_t **tunnels, char *line)
{
    return;
}

int put_tunnel(tunnels_t **tunnels, char *line)
{
    if (check_tunnel(line) == KO)
        return KO;
    add_tunnel(tunnels, line);
    return OK;
}
