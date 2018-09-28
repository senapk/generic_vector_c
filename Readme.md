# Biblioteca de vector generico em C

```c
#include <stdio.h>
#include "vec.h"

typedef struct{
    int x, y;
} v2d;

void print_v2d(void * value){
    v2d * p = (v2d*) value;
    printf("(%d:%d)", p->x, p->y);
}

int main(){
    {
        Vector * vet = vet_create(int);
        vet_add(vet, 5, int);
        vet_add(vet, 9, int);
        vet_add(vet, 8, int);
        vet_add(vet, 3, int);
        vet_show(vet, "%d", int); //mostra [5, 9, 8, 3]
    
        vet_rm(vet, 1);
        vet_show(vet, "%d", int); //[5, 8, 3]
        
        for(int i = 0; i < vet->size; i++)
            vet_get(vet, i, int) += 1; //incrementa todos de 1
    
        vet_show(vet, "%d", int);
        vet_destroy(vet);
    }

    {
        Vector * vet = vet_create(char*);
        vet_add(vet, "banana", char*);
        vet_add(vet, "xilito", char*);
        vet_add(vet, "minhoca", char*);
        vet_show(vet, "%s", char*); //mostra [banana, xilito, minhoca ]
        vet_destroy(vet);
    }

    {
        Vector * vet = vet_create(v2d);
        vet_add_(vet, &(v2d){4, 5}); //modo inline para structs
        v2d v = {7, 3};
        vet_add(vet, v, v2d);
        vet_add_(vet, &(v2d){9, 1});
        vet_add_(vet, &(v2d){8, 3});

        //imprimindo passando a funcao
        vet_show_fn(vet, print_v2d, int); //mostra [(4:5), (7:3), (9:1), (8:3)]
        
        vet_destroy(vet);
    }
    return 0;
}
```

