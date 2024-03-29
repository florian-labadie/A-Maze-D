/*
** EPITECH PROJECT, 2024
** B-CPE-200-BDX-2-1-amazed-baptiste.blambert
** File description:
** robot_parcour
*/

#include "my.h"

static int get_robot_pos(int *robot_pos, int robot, int len)
{
    int pos = 0;

    if (robot_pos[len - 1] >= robot)
        return len;
    for (int i = 0; i < len; i++) {
        if (robot_pos[i] == robot) {
            pos = i;
            break;
        }
    }
    return pos;
}

static void print_step(char **names, int robot, int pos, matrix_t *matrix)
{
    my_putchar('P');
    my_put_nbr(robot);
    my_putchar('-');
    my_putstr(names[matrix->paths->path[pos + 1]]);
    my_putchar(' ');
}

static void move_robot(matrix_t *matrix, int **robot_pos, int robot,
    int len)
{
    int pos = get_robot_pos(*robot_pos, robot, len);

    if (pos + 1 == len)
        return;
    if ((*robot_pos)[pos + 1] == - 1 || pos + 1 == len - 1) {
        (*robot_pos)[pos + 1] = robot;
        (*robot_pos)[pos] = - 1;
        print_step(matrix->names, robot, pos, matrix);
    }
}

static void move_all_robot(matrix_t *matrix, int robot_nbr, int **robot_pos,
    int len)
{
    for (int robot = 1; robot <= robot_nbr; robot++) {
        if ((*robot_pos)[len - 1] >= robot)
            continue;
        move_robot(matrix, robot_pos, robot, len);
    }
}

int robot_parcour(matrix_t *matrix, int robot_nbr)
{
    int len = matrix->paths->path_len;
    int *robot_pos = malloc(sizeof(int) * len);

    for (int i = 0; i < matrix->paths->path_len; i++)
        robot_pos[i] = - 1;
    while (robot_pos[len - 1] != robot_nbr) {
        move_all_robot(matrix, robot_nbr, &robot_pos, len);
        my_putchar('\n');
    }
    return OK;
}
