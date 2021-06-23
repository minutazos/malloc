/*
** EPITECH PROJECT, 2020
** B-PSU-400-BAR-4-1-malloc-alvaro.garcia-bamala
** File description:
** Realloc
*/

#include "shared.h"

void *realloc(void *ptr, size_t size)
{
    void *ret;
    header_t *header;

    header = (header_t *)ptr - 1;
    if (ptr == NULL)
        return (malloc(size));
    else if (size == 0) {
        free(ptr);
        return (NULL);
    }
    if (header->s.size >= size)
        return (ptr);
    ret = malloc(size);
    if (ret != NULL) {
        memcpy(ret, ptr, header->s.size);
        free(ptr);
    }
    return (ret);
}