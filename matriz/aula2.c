#include <stdio.h>
#include <stdlib.h>

#define ALVENARIA 0
#define VINIL 1
#define FIBRA 2
#define PLASTICO 3

int valorPiscina(int j, int i){
    int vp[4][4] = {
        {75000, 150000, 225000, 300000},
        {55000, 110000, 165000, 220000},
        {37500, 75000, 112500, 150000},
        {25000, 50000, 75000, 100000}
    };

    return vp[j][i];
}

double calculaMedia(double* arranjo, int tam){
    int i;
    double resp = 0;
    for (i=0;i<tam;i++) resp += arranjo[i];
    return resp/tam;
}

/*Carrega os valores das piscinas na matriz de 
    área X Material
*/
void carregaVal(double** m){
    int i, j;
    for (i = 0; i < 4; i++){
        for (j = 50; j <= 200; j += 50){
            int index = (j / 50) - 1; // Mapear 50, 100, 150, 200 para 0, 1, 2, 3
            m[i][index] = valorPiscina(i, index);
        }
    }
}
/*
    Retorna matriz com os preços finais.
    parâmetros:
        val - matriz de valores
        desc - mastriz de descontos
*/
double** calculaFinal(double** val, double desc[][4]){

    int i, j;

    double** saida = (double**) malloc(sizeof(double*)*4);
    for (i=0;i<4;i++) saida[i] = (double**) malloc(sizeof(double*)*4);
    for (i=0;i<4;i++){
        for (j=0;j<4;j++){
            saida[i][j] = val[i][j]*(1-desc[i][j]);
        }
    }
}
int main(){
    int i, j;
    double** valores = (double**) malloc(sizeof(double*)*4);
    for (i=0;i<4;i++) {
        valores[i] = (double*) malloc(sizeof(double)*4);
    }
    
    double descontos[][4] = {
        {0,0,0.2,0.2},
        {0.05, 0.05, 0.1, 0.15},
        {0.02, 0.04, 0.08,0.16},
        {0,0,0,0.05}
    };
    
    double** pFinal;

    carregaVal(valores);

    for (int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            printf("%9.2f\t", valores[i][j]);
        }
        printf("\n");
    }

    printf("Piscina de plastico de 150m2: %.2f\n", valores[PLASTICO][2]);
    printf("Media: %.2f\n", calculaMedia(valores[PLASTICO],4));

    pFinal = calculaFinal(valores, descontos);

    // Libera a memória alocada
    for (i = 0; i < 4; i++) {
        free(valores[i]);
    }
    free(valores);

    return 0;
} 