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

int parse(amazed_t *amazed)
{
    char *line = NULL;
    size_t len = 0;
    int ret = 0;

    while ((getline(&line, &len, stdin)) != ERR) {
        check_commentary(&line);
        if (check_blankline(line) == OK)
            continue;
    }
    free(line);
    return OK;
}
