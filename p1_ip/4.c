#include <stdio.h>

int main() {
    int A[10], B[10], C[10], D[10];

    // Lê os valores para o vetor A
    printf("Digite 10 valores para o vetor A:\n");
    for (int i = 0; i < 10; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    // Lê os valores para o vetor B
    printf("Digite 10 valores para o vetor B:\n");
    for (int i = 0; i < 10; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    // Calcula os valores para os vetores C e D
    for (int i = 0; i < 10; i++) {
        if (A[i] <= B[i]) {
            C[i] = A[i];
            D[i] = B[i];
        } else {
            C[i] = B[i];
            D[i] = A[i];
        }
    }

    // Imprime o vetor C (menores valores)
    printf("Vetor C (menores valores):\n");
    for (int i = 0; i < 10; i++) {
        printf("C[%d]: %d\n", i, C[i]);
    }

    // Imprime o vetor D (maiores valores)
    printf("Vetor D (maiores valores):\n");
    for (int i = 0; i < 10; i++) {
        printf("D[%d]: %d\n", i, D[i]);
    }

    return 0;
}

/*
Explicação do Código:
Declaração dos vetores:

São declarados quatro vetores de inteiros: A, B, C e D, cada um com 10 elementos.
Leitura dos valores para os vetores A e B:

O programa solicita ao usuário que insira 10 valores para o vetor A.
Em seguida, solicita 10 valores para o vetor B.
Cálculo dos vetores C e D:

Para cada índice de 0 a 9, o programa compara os valores correspondentes de A e B.
Se A[i] é menor ou igual a B[i], C[i] recebe A[i] e D[i] recebe B[i].
Caso contrário, C[i] recebe B[i] e D[i] recebe A[i].
Impressão dos vetores C e D:

O programa imprime os valores do vetor C, que contém os menores valores para cada índice.
Em seguida, imprime os valores do vetor D, que contém os maiores valores para cada índice.*/