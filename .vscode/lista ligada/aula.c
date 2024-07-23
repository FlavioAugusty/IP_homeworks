#include <stdio.h>
#include <stdlib.h>

#define true 1 
#define false 0

typedef int bool;

typedef int bool;

typedef struct {
    int id;
    float media;
} Registro;

Registro novo(int id, float media){
    Registro res;
    res.id = id;
    res.media = media;
    return res;
}

typedef struct aux{
    Registro reg;
    struct aux* prox;
} No;

typedef struct {
    No* inicio;
    int elementos;
} Lista;

void inicializa(Lista* l){
    l -> inicio = NULL;
    l -> elementos = 0;
}

void insere(Lista* l, Registro reg) {
    No* novo = (No*) malloc(sizeof(No));
    novo -> reg = reg;
    novo -> prox = l -> inicio;
    l -> inicio = novo;
    l -> elementos++;
}

bool Insere(Lista* l, Registro reg, int pos){
    if (pos<0 || pos>l->elementos) return false;
    No* novo = (No*) malloc(sizeof(No));
    novo->reg = reg;
    int i;
    No* p;
    if (pos == 0){
        novo->prox = p->prox;
        p->prox = novo;
    }
    l->elementos++;
    return true;
}


int main(){
    Lista l1;
    inicializa(&l1);

    insere(&l1, novo(4, 8.5));
    insere(&l1, novo(7, 6.5));
    insere(&l1, novo(9, 7.5));

    No* n = l1.inicio;
    while (n != NULL){
        printf("%i\n", n->reg.id);
        n = n->prox;
    }

    return 0;
}