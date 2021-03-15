/*
** EPITECH PROJECT, 2020
** calloc
** File description:
** calloc
*/

#include "../include/my_lib.h"

void *calloc(size_t nmemb , size_t size)
{
    void *ptr;

    if (size == 0 || nmemb == 0)
        return NULL;
    ptr = malloc(size * nmemb);
    ptr = memset(ptr, 0, (size * nmemb));
    return ptr;
}
