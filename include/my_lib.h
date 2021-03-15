/*
** EPITECH PROJECT, 2020
** my_lib
** File description:
** include
*/

#ifndef LIB_MEMORY
#define LIB_MEMORY

#include <unistd.h>
#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

typedef struct malloc_s{
    struct malloc_s *next;
    size_t size;
    bool free;
} malloc_t;

int power_of_two(size_t size);
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

#endif // LIB_MEMORY //
