#include <stdio.h>

float calcularMedia(float notas[], int tamanho) {
    float soma = 0.0, maior, menor;
    int i;

    // Inicializa maior e menor com o primeiro elemento
    maior = menor = notas[0];

    // Calcula a soma das notas e encontra maior e menor nota
    for (i = 0; i < tamanho; i++) {
        soma += notas[i];
        if (notas[i] > maior) {
            maior = notas[i];
        }
        if (notas[i] < menor) {
            menor = notas[i];
        }
    }

    // Subtrai a maior e a menor nota da soma
    soma = soma - maior - menor;

    // Calcula a média das 4 notas restantes
    return soma / (tamanho - 2);
}

int main() {
    float notas[6];
    int i;

    // Solicita ao usuário as 6 notas
    printf("Digite as 6 notas dos juízes (entre 0 e 10):\n");
    for (i = 0; i < 6; i++) {
        do {
            printf("Nota %d: ", i + 1);
            scanf("%f", &notas[i]);
            if (notas[i] < 0 || notas[i] > 10) {
                printf("Nota inválida! Insira uma nota entre 0 e 10.\n");
            }
        } while (notas[i] < 0 || notas[i] > 10);
    }

    // Calcula a média após descartar a maior e a menor nota
    float media = calcularMedia(notas, 6);

    // Exibe a média
    printf("A média das notas (com a maior e a menor descartadas) é: %.2f\n", media);

    return 0;
}

/*
Explicação do Código:
Função calcularMedia:

Recebe um array de notas e seu tamanho.
Inicializa maior e menor com a primeira nota.
Calcula a soma de todas as notas e encontra a maior e a menor nota.
Subtrai a maior e a menor nota da soma total.
Calcula e retorna a média das quatro notas restantes.
Função main:

Solicita ao usuário que insira seis notas, verificando se estão entre 0 e 10.
Chama a função calcularMedia para calcular a média das notas com a maior e a menor descartadas.
Exibe a média calculada.*/