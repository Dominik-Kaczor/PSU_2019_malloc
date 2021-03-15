/*
** EPITECH PROJECT, 2020
** malloc
** File description:
** malloc
*/

#include "../include/my_lib.h"

void alignment(malloc_t **tmp, size_t size, int init)
{
    int page = getpagesize();
    int start = 1;

    if (init == 0)
        (*tmp) = sbrk(0);
    while ((page * 2) * start  <= size + sizeof(struct malloc_s)) {
        start += 1;
    }
    (*tmp) = sbrk((page * 2) * start);
    (*tmp)->free = false;
    (*tmp)->next = NULL;
    if (init == 0)
        (*tmp)->size = (page * 2) * start - sizeof(struct malloc_s);
    else
        (*tmp)->size += (page * 2) * start - sizeof(struct malloc_s);
}

malloc_t *init_struct(malloc_t **first, malloc_t **last, size_t size)
{
    malloc_t *tmp;

    tmp = (void*)(*first) + size + sizeof(malloc_t);
    tmp->size = (*first)->size - size - sizeof(malloc_t);
    (*first)->size = size;
    tmp->free = false;
    tmp->next = (*first)->next;
    (*first)->next = tmp;
    (*last) = tmp;
    return ((void *)*first + sizeof(malloc_t));
}

malloc_t *append_struct(malloc_t **last, size_t size)
{
    malloc_t *tmp;

    if ((*last) && size + sizeof(malloc_t) > (*last)->size)
        alignment(last, size, 1);
    tmp = (*last);
    (*last) = tmp->next;
    (*last) = (void*)tmp + size + sizeof(malloc_t);
    tmp->free = false;
    (*last)->size = tmp->size - size - sizeof(malloc_t);
    tmp->size = size;
    (*last)->next = tmp->next;
    tmp->next = (*last);
    return ((void *)tmp + sizeof(malloc_t));
}

malloc_t *get_free_struct(malloc_t *first, size_t size)
{
    malloc_t *tmp = first;
    malloc_t *push = NULL;

    while (tmp->next) {
        if (tmp->free == true && tmp->size >= size) {
            if (!push)
                push = tmp;
            if (push->size > tmp->size)
                push = tmp;
        }
        tmp = tmp->next;
    }
    if (push) {
        push->free = false;
        return push; 
    }
    return NULL;
}

void *malloc(size_t size)
{
    static malloc_t *first = NULL;
    static malloc_t *last = NULL;
    malloc_t *free = NULL;
    static int init = 0;
    size_t good_size = power_of_two(size);

    if (size <= 0)
        return NULL;
    if (init == 0) {
        alignment(&first, good_size, init);
        init = 1;
        return (init_struct(&first, &last, good_size));
    }
    free = get_free_struct(first, good_size);
    if (free != NULL)
        return ((void *)free + sizeof(malloc_t));
    return (append_struct(&last, good_size));
}