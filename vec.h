#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct{
    void * data;
    int unit_size;
    int capacity;
    int size;
} Vector;


#define vet_create(type)                   vet_create_(sizeof(type))
#define vet_add(vet, value, type)          do{type vet_add = value; vet_add_(vet, &vet_add);}while(0)
#define vet_get(vet, ind, type)            (*((type*) (vet_get_(vet, ind))))
#define vet_rm(vet, ind)                   vet_rm_(vet, ind)
#define vet_show(vet, format, type)        __vet_show(vet, format, type)
#define vet_show_fn(vet, printf_fn, type)  __vet_show_fn(vet, printf_fn, type)
#define vet_destroy(vet)                   vet_destroy_(vet)


Vector* vet_create_(int unit_size){
    Vector * vet = (Vector*) malloc(sizeof(Vector));
    vet->capacity = 10;
    vet->data = malloc(vet->capacity * unit_size);
    vet->size = 0;
    vet->unit_size = unit_size;
    return vet;
}

void vet_add_(Vector* vet, void * value){
    if(vet->size == vet->capacity){
        vet->data = realloc(vet->data, 2 * vet->capacity);
        vet->capacity *= 2;
    }
    memcpy(vet->data + vet->size * vet->unit_size, value, vet->unit_size);
    vet->size += 1;
}

void * vet_get_(Vector * vet, int ind){
    return vet->data + vet->unit_size * ind;
}

void vet_rm_(Vector * vet, int ind){
    for(int i = ind; i < vet->size - 1; i++)
        memcpy(vet_get_(vet, i), vet_get_(vet, i + 1), vet->unit_size);
    vet->size -= 1;
}

void vet_destroy_(Vector * vet){
    free (vet->data);
    free (vet);
}

#define __vet_show(vet, format, type)\
do{\
    printf("[");\
    if(vet->size > 0)\
        printf(format, vet_get(vet, 0, type));\
    for(int i = 1; i < vet->size; i++){\
        printf(", ");\
        printf(format, vet_get(vet, i, type));\
    }\
    printf("]\n");\
}while(0)\

#define __vet_show_fn(vet, print_fn, type)\
do{\
    printf("[");\
    if(vet->size > 0)\
        print_fn(vet_get_(vet, 0));\
    for(int i = 1; i < vet->size; i++){\
        printf(", ");\
        print_fn(vet_get_(vet, i));\
    }\
    printf("]\n");\
}while(0)\


