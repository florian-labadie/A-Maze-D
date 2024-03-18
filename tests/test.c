/*
** EPITECH PROJECT, 2023
** test
** File description:
** printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout() ;
    cr_redirect_stderr() ;
}

Test (lib, my_putchar_check, . init = redirect_all_std)
{
    my_putchar('A');
    cr_assert_stdout_eq_str("A");
}

Test (lib, my_putstr_check, . init = redirect_all_std)
{
    my_putstr("Hello");
    cr_assert_stdout_eq_str("Hello");
}
