#include <stdio.h>

#define MAX 20

void contarOcorrencias(int vetor[], int tamanho, int x);

int main() {
    int vetor[MAX];
    int tamanho = MAX;
    int maior = 0, posMaior = 0, menor = 0, posMenor = 0, soma = 0;
    float media;
    int x;

    for (int i = 0; i < tamanho; i++) {
        int j = i+1;
        printf("Digite o valor para a Posicao %d: ", j);
        scanf("%d", &vetor[i]);
        soma += vetor[i];
        if(i == 0){
            maior = vetor[i];
            posMaior = j;
            menor = vetor[i];
            posMenor = j;
        }else if(maior < vetor[i]){
            maior = vetor[i];
            posMaior = j;
        }
        if(vetor[i] < menor){
            menor = vetor[i];
            posMenor = j;
        }
    }

    media = soma/20;

    printf("Maior elemento: %d (Posicao: %d)\n", maior, posMaior);
    printf("Menor elemento: %d (Posicao: %d)\n", menor, posMenor);
    printf("Soma dos elementos: %d\n", soma);
    printf("Media dos elementos: %.2f\n", media);

    // c. Contar ocorrências de x
    printf("Digite um valor para procurar no vetor: ");
    scanf("%d", &x);
    contarOcorrencias(vetor, tamanho, x);

    return 0;
}

void contarOcorrencias(int vetor[], int tamanho, int x) {
    int i, contagem = 0;
    printf("O valor %d aparece nas posicoes: ", x);
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] == x) {
            int j = i+1;
            printf("%d ", j);
            contagem++;
        }
    }
    if (contagem == 0) {
        printf("Nenhuma");
    }
    printf("\nTotal de ocorrencias: %d\n", contagem);
}
