/*
** EPITECH PROJECT, 2020
** B-PSU-400-BAR-4-1-malloc-alvaro.garcia-bamala
** File description:
** Free
*/

#include "shared.h"

void free(void *ptr)
{
    header_t *header;
    void *program_brk;

    if (ptr == NULL)
        return;
    pthread_mutex_lock(&malloc_lock);
    header = ((header_t *)ptr - 1);
    program_brk = sbrk(0);
    if ((char *)ptr + header->s.size == program_brk) {
        release_memory(header);
        pthread_mutex_unlock(&malloc_lock);
        return;
    }
    header->s.is_available = TRUE;
    pthread_mutex_unlock(&malloc_lock);
}

void release_memory(header_t *header)
{
    header_t *tmp;

    if (head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        tmp = head;
        while (tmp) {
            if (tmp->s.next == tail) {
                tmp->s.next = NULL;
                tail = tmp;
            }
            tmp = tmp->s.next;
        }
    }
    sbrk(0 - sizeof(header_t) - header->s.size);
}