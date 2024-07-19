#include <stdio.h>

typedef struct auxCasa {
    float lateral;
    float cquarto;
} casa;

casa iniciaCasa(float lateral, float cquarto){
    casa resp;
    resp.lateral = lateral;
    resp.cquarto = cquarto;
    return resp;
}

void areaCasa (casa pCasa) {
    float areaq;
    float areas;
    float areat;
    if (!(pCasa.lateral>=0 && pCasa.cquarto>=0)){
        printf("Erro: parametro < 0\n");
    }else{
        printf("Programa para calculo da area da casa\n");
        areas = pCasa.lateral*pCasa.lateral;
        printf("A area da sala eh %f\n", areas);
        areaq = pCasa.cquarto*(pCasa.lateral/2);
        printf("A area do quarto eh %f\n", areaq);
        printf("A area do banheiro eh %f\n", areaq);
        areat = areas + 2*areaq;
        printf("A area total eh %f\n", areat);
    }
}

void ampliaCasa2(casa* ca){
    (*ca).lateral++;
    ca->cquarto++;
    printf("Lateral na funçao: %.2f\n", ca->lateral);
}

int main(){
    casa c1 = iniciaCasa(11,15);
    printf("Lateral inicial: %.2f\n", c1.lateral);

    ampliaCasa2(&c1);
    printf("Lateral final: %.2f\n", c1.lateral);
    areaCasa(c1);
    return 0;
}