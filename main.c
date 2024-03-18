/*
** EPITECH PROJECT, 2023
** Projet-Graphic
** File description:
** main
*/

#include "my.h"

int main(int argc, char const *const *argv)
{
    if (error_handling(argc, argv) == KO)
        return KO;
    if (launch_amazed())
        return KO;
    return OK;
}
