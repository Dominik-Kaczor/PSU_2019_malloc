/*
** EPITECH PROJECT, 2020
** Unit test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_lib.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(first, check_malloc)
{
    char *dom = malloc(sizeof(char) * 3);

    dom[0] = 'd';
    dom[1] = 'o';
    dom[2] = 'm';
    cr_assert_str_eq(dom, "dom");
}
/*
Test(two, power_two)
{
    int dest = power_of_two(7);

    cr_assert_eq(dest, 8);
}
*/
