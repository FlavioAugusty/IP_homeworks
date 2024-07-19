#include <stdio.h>

int main() {
    float comprimento;
    float largura;
    float area;
    printf("Programa para o calculo da area do retangulo. \n");

    while(1==1){
        printf("Digite o comprimento ou 0(zero) para sair: ");
        scanf("%f", &comprimento);
        if (comprimento==0) break;
        printf("Digite a largura ou 0 (zero) para sair: ");
        scanf("%f",&largura);
        if (largura==0) break;
        area = comprimento*largura;
        printf("Area: %.2f\n\n", area);
    }

    return 0;
}