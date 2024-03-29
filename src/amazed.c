/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** amazed
*/

#include "my.h"

static void init_amazed(amazed_t *amazed)
{
    amazed->nb_robot = 0;
    amazed->room = NULL;
    amazed->tunnels = NULL;
}

int launch_amazed(void)
{
    amazed_t amazed = {};

    init_amazed(&amazed);
    if (parse(&amazed) == KO)
        return free_amazed(&amazed, KO);
    if (init_matrix(&amazed) == KO)
        return free_amazed(&amazed, KO);
    my_bfs(amazed.matrix);
    robot_parcour(amazed.matrix, amazed.nb_robot);
    return free_amazed(&amazed, OK);
}
