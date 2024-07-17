#include <stdio.h>
#include <stdlib.h> 

/*Estrutura para agrupar as informações de uma casa*/
typedef struct auxCasa{
    float lateral;  // lateral da casa
    float cquarto; //comprimento do quarto
} casa;

typedef struct auxPisc{
    float raio;
}piscina;

typedef struct auxCaba{
    casa cas;
    piscina pis; 
}cabana;

typedef struct auxP{
    int cpf;
    struct auxP* conjuge;
} Pessoa;

int main(){
    Pessoa p1;
    p1.cpf = 12345;

    Pessoa* p2 = (Pessoa*)  malloc(sizeof(Pessoa));
    p2->cpf = 56789;

    Pessoa p3;
    p3.cpf = 44444;

    p1.conjuge = p2;
    p2->conjuge = &p1;
    p3.conjuge = NULL;

    struct auxCasa c1;
    casa c2;
    c1.lateral = 11;
    c2.lateral = 15;
    c1.cquarto = 7;

    piscina p1;
    p1.raio = 3.5;

    cabana cab1;
    cab1.cas = c1;
    cab1.pis = p1;
    cab1.cas.lateral = 12;

    printf("A lateral da casa da cabana1 vale: %.2f\n", cab1.cas.lateral);
    printf("o raio da piscina da cabana1 vale: %.2f\n", cab1.pis.raio);

    printf("A lateral da casa1 vale: %.2f\n", c1.lateral);
    printf("A lateral da casa2 vale: %.2f\n", c2.lateral);
    return 0;
}