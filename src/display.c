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
    my_putstr("#number_of_robots\n");;
    my_put_nbr(amazed->nb_robot);
    my_putchar('\n');
    my_putstr("#rooms\n");
    *recovery = ROOM;
    return OK;
}

static int display_room(amazed_t *amazed)
{
    if (amazed->room == NULL)
        return KO;
    for (; amazed->room != NULL && amazed->room->display == false;
        amazed->room = amazed->room->next);
    if (amazed->room->status == START) {
        my_putstr(START_STR);
        my_putchar('\n');
    }
    if (amazed->room->status == END) {
        my_putstr(END_STR);
        my_putchar('\n');
    }
    my_putstr(amazed->room->name);
    my_putchar(' ');
    my_put_nbr(amazed->room->x);
    my_putchar(' ');
    my_put_nbr(amazed->room->y);
    my_putchar('\n');
    amazed->room->display = false;
    return OK;
}

static int display_tunnel(amazed_t *amazed)
{
    if (amazed->tunnels == NULL)
        return KO;
    for (; amazed->tunnels != NULL && amazed->tunnels->display == false;
        amazed->tunnels = amazed->tunnels->next);
    if (amazed->tunnels->display == true)
        my_putstr("#tunnels\n");  
    my_putstr(amazed->tunnels->room1);
    my_putchar('-');
    my_putstr(amazed->tunnels->room2);
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
