/*
** EPITECH PROJECT, 2024
** root_for_mt_repo
** File description:
** error_handling
*/

#include "my.h"

int error_handling(int argc, char const *const *argv)
{
    if (argc != 2)
        return KO;
    if (!argv || !argv[1])
        return KO;
    return OK;
}
