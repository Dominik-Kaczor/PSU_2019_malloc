/*
** EPITECH PROJECT, 2020
** realloc
** File description:
** realloc
*/

#include "../include/my_lib.h"

void *realloc(void *ptr, size_t size)
{
    void *new_ptr;

    if (ptr == NULL)
        return (malloc(size));
    if (size == 0)
        return (ptr);
    new_ptr = malloc(size);
    memcpy(new_ptr, ptr, size);
    free(ptr);
    return new_ptr;
}
