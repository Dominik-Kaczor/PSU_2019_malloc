/*
** EPITECH PROJECT, 2020
** free
** File description:
** free
*/

#include "../include/my_lib.h"

int power_of_two(size_t size)
{
    int power = 2;

    while (size > power)
        power = power * 2;
    return power;
}

void free(void *ptr)
{
    malloc_t *test = (malloc_t *)(ptr - sizeof(malloc_t));

    if (ptr == NULL || test->free == true)
        return;
    test->free = true;
    return;
}
