/*
** EPITECH PROJECT, 2020
** B-PSU-400-BAR-4-1-malloc-alvaro.garcia-bamala
** File description:
** Calloc
*/

#include "shared.h"

void *calloc(size_t nmemb, size_t size)
{
    size_t check;
    void *ret;

    check = size * nmemb;
    if (nmemb == 0 || size == 0 || check / size != nmemb)
        return (NULL);
    ret = malloc(nmemb * size);
    if (ret == NULL)
        return (NULL);
    memset(ret, 0, nmemb * size);
    return (ret);
}