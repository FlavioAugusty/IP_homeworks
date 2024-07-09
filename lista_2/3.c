#include <stdio.h>

int main() {
    int N, num;
    int countDiv4 = 0;
    int countDiv7 = 0;
    int countDiv13 = 0;

    // Solicita ao usuário o número de entradas
    printf("Digite a quantidade de números (N): ");
    scanf("%d", &N);

    // Verifica se N é um número positivo
    if (N <= 0) {
        printf("A quantidade de números deve ser maior que zero.\n");
        return 1;
    }

    // Lê os números e verifica suas divisibilidades
    printf("Digite %d números:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);

        if (num % 4 == 0) {
            countDiv4++;
        }
        if (num % 7 == 0) {
            countDiv7++;
        }
        if (num % 13 == 0) {
            countDiv13++;
        }
    }

    // Exibe os resultados
    printf("Quantidade de números divisíveis por 4: %d\n", countDiv4);
    printf("Quantidade de números divisíveis por 7: %d\n", countDiv7);
    printf("Quantidade de números divisíveis por 13: %d\n", countDiv13);

    return 0;
}

/*
Explicação do código:
Entrada do usuário:

O programa solicita ao usuário que insira o valor de N, que representa a quantidade de números a serem digitados.
Verifica se N é positivo. Se não for, o programa exibe uma mensagem de erro e termina.
Leitura e verificação de números:

O programa lê N números em um loop.
Para cada número, verifica se é divisível por 4, 7 ou 13.
Incrementa contadores (countDiv4, countDiv7, countDiv13) para cada condição atendida.
Exibição dos resultados:

Após o loop, o programa exibe o número de entradas que são divisíveis por 4, 7 e 13.
*/