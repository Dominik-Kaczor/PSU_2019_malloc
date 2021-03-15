/*
** EPITECH PROJECT, 2020
** reallocarray
** File description:
** reallocarray
*/

#include "../include/my_lib.h"

void *reallocarray(void *ptr , size_t nmemb , size_t size)
{
    return (realloc(ptr, nmemb + size));
}
