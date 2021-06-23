/*
** EPITECH PROJECT, 2020
** B-PSU-400-BAR-4-1-malloc-alvaro.garcia-bamala
** File description:
** Malloc
*/

#include "shared.h"

pthread_mutex_t malloc_lock;
header_t *head;
header_t *tail;

void *malloc(size_t size)
{
    header_t *header;

    if (size == 0)
        return (NULL);
    pthread_mutex_lock(&malloc_lock);
    header = get_free_block(size);
    if (header != NULL) {
        header->s.is_available = FALSE;
        pthread_mutex_unlock(&malloc_lock);
        return ((void *) (header + 1));
    }
    header = extend_heap(header, size);
    if (header == NULL)
        return (NULL);
    return ((void *) (header + 1));
}

header_t *extend_heap(header_t *header, size_t size)
{
    size_t total_size;
    void *block;

    total_size = sizeof(header_t) + size;
    block = sbrk(total_size);
    if (block == (void *) -1) {
        pthread_mutex_unlock(&malloc_lock);
        return (NULL);
    }
    header = block;
    init_header(header, size);
    update_head_and_tail(header);
    pthread_mutex_unlock(&malloc_lock);
    return (header);
}

header_t *get_free_block(size_t size)
{
    header_t *curr;

    curr = head;
    while (curr) {
        if (curr->s.is_available == TRUE && curr->s.size >= size)
            return (curr);
        curr = curr->s.next;
    }
    return (NULL);
}

void init_header(header_t *header, size_t size)
{
    header->s.size = size;
    header->s.is_available = 0;
    header->s.next = NULL;
}

void update_head_and_tail(header_t *header)
{
    if (head == NULL)
        head = header;
    if (tail != NULL)
        tail->s.next = header;
    tail = header;
}
