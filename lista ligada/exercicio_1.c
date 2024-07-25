#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

typedef struct {
    int id;
} Registro;

Registro novoRegistro(int id){
    Registro res;
    res.id = id;
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
    l->inicio = NULL;
    l->elementos = 0;
}

void insere(Lista* l, Registro reg){
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->reg = reg;
    novoNo->prox = l->inicio;
    l->inicio = novoNo;
    l->elementos++;
}

Lista* filtraPares(Lista* l1){
    Lista* l2 = (Lista*) malloc(sizeof(Lista));
    inicializa(l2);
    No* atual = l1->inicio;
    while (atual != NULL) {
        int p = atual->reg.id;
        if ((p % 2) == 0) {
            insere(l2, novoRegistro(p));
        }
        atual = atual->prox;
    }
    return l2;
}

// Função para imprimir a lista (opcional, mas útil para testes)
void imprimeLista(Lista* l) {
    No* atual = l->inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->reg.id);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função para liberar memória da lista
void liberaLista(Lista* l) {
    No* atual = l->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    l->inicio = NULL;
    l->elementos = 0;
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

bool exclui(Lista* l, int pos) {
    if (pos<0 || pos>l->elementos-1) return false;
    int i;
    No* p;
    No* apagar;
    if (pos == 0){
        apagar = l->inicio;
        l->inicio = apagar->prox;
    }else {
        p = l->inicio;
        for (i= 0; i<pos-1;i++) p = p->prox;
        apagar = p->prox;
        p->prox = apagar->prox;
    }
    free(apagar);
    l->elementos--;
    return true;
}

int main() {
    Lista l1;
    inicializa(&l1);

    // Adiciona alguns elementos à lista l1
    insere(&l1, novoRegistro(1));
    insere(&l1, novoRegistro(2));
    insere(&l1, novoRegistro(3));
    insere(&l1, novoRegistro(4));

    printf("Lista l1: ");
    imprimeLista(&l1);

    Lista* l2 = filtraPares(&l1);

    printf("Lista l2 com elementos pares: ");
    imprimeLista(l2);

    // Libera memória das listas
    liberaLista(&l1);
    liberaLista(l2);
    free(l2); // Libera a estrutura da lista l2

    return 0;
}
