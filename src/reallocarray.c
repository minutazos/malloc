/*
** EPITECH PROJECT, 2020
** B-PSU-400-BAR-4-1-malloc-alvaro.garcia-bamala
** File description:
** Reallocarray
*/

#include "shared.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t new_size;
    void *ret;

    new_size = nmemb * size;
    if (new_size / size != nmemb)
        return (NULL);
    ret = realloc(ptr, test);
    return (ret);
}
