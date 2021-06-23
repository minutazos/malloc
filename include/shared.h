/*
** EPITECH PROJECT, 2020
** B-PSU-400-BAR-4-1-malloc-alvaro.garcia-bamala
** File description:
** *alloc header
*/

#ifndef MALLOC_SHARED_H
#define MALLOC_SHARED_H

#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

union header {
    struct {
        size_t size;
        unsigned is_available;
        union header *next;
    } s;
    char _align[32];
};
typedef union header header_t;

extern pthread_mutex_t malloc_lock;
extern header_t *head;
extern header_t *tail;

void *malloc(size_t size);
header_t *get_free_block(size_t size);
header_t *extend_heap(header_t *header, size_t size);
void init_header(header_t *header, size_t size);
void update_head_and_tail(header_t *header);

void free(void *ptr);
void release_memory(header_t *header);

void *calloc(size_t nmemb, size_t size);

void *realloc(void *ptr, size_t size);

void *reallocarray(void *ptr, size_t nmemb, size_t size);
#endif //MALLOC_SHARED_H
