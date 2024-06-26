/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** display
*/

#include "my.h"

static int display_nb_robot(amazed_t *amazed, recovery_t *recovery)
{
    if (amazed->nb_robot == 0)
        return KO;
    my_putstr("#number_of_robots\n");
    my_put_nbr(amazed->nb_robot);
    my_putchar('\n');
    my_putstr("#rooms\n");
    *recovery = ROOM;
    return OK;
}

static int display_room(amazed_t *amazed)
{
    room_t *tmp = amazed->room;

    if (amazed->room == NULL)
        return KO;
    for (; tmp->next != NULL; tmp = tmp->next);
    if (tmp->status == START) {
        my_putstr(START_STR);
        my_putchar('\n');
    }
    if (tmp->status == END) {
        my_putstr(END_STR);
        my_putchar('\n');
    }
    my_putstr(tmp->name);
    my_putchar(' ');
    my_put_nbr(tmp->x);
    my_putchar(' ');
    my_put_nbr(tmp->y);
    my_putchar('\n');
    return OK;
}

static int display_tunnel(amazed_t *amazed)
{
    tunnels_t *tmp = amazed->tunnels;

    if (amazed->tunnels == NULL)
        return KO;
    for (; tmp->next != NULL; tmp = tmp->next);
    if (amazed->tunnels->display == true)
        my_putstr("#tunnels\n");
    my_putstr(tmp->room1);
    my_putchar('-');
    my_putstr(tmp->room2);
    my_putchar('\n');
    amazed->tunnels->display = false;
    return OK;
}

int display(amazed_t *amazed, recovery_t *rec)
{
    if (!amazed)
        return KO;
    if (*rec == TUNNEL && display_tunnel(amazed) == KO)
        return KO;
    if (*rec == ROOM && display_room(amazed) == KO)
        return KO;
    if (*rec == ROBOT && display_nb_robot(amazed, rec) == KO)
        return KO;
    return OK;
}
