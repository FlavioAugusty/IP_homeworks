#include <stdio.h>

int main() {
    int N;
    float num;
    float soma = 0;
    float maior, menor, media;

    // Solicita ao usuário o número de entradas
    printf("Digite a quantidade de números (N): ");
    scanf("%d", &N);

    // Verifica se N é um número positivo
    if (N <= 0) {
        printf("A quantidade de números deve ser maior que zero.\n");
        return 1;
    }

    // Lê os números e calcula a soma, maior e menor
    for (int i = 0; i < N; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%f", &num);

        soma += num;

        if (i == 0) {
            maior = menor = num;
        } else {
            if (num > maior) {
                maior = num;
            }
            if (num < menor) {
                menor = num;
            }
        }
    }

    // Calcula a média
    media = soma / N;

    // Exibe os resultados
    printf("Maior número: %.2f\n", maior);
    printf("Menor número: %.2f\n", menor);
    printf("Média dos números: %.2f\n", media);

    return 0;
}

/*
Explicação do Código:
Entrada do usuário:

O programa solicita ao usuário que insira o valor de 
𝑁
N, que representa a quantidade de números a serem digitados.
Verifica se 
𝑁
N é positivo. Se não for, o programa exibe uma mensagem de erro e termina.
Leitura e cálculo de valores:

O programa lê 
𝑁
N números reais em um loop.
Atualiza a soma dos números.
Determina o maior e o menor número à medida que lê os valores.
Cálculo da média:

Após o loop, calcula a média dos números digitados.
Exibição dos resultados:

Exibe o maior número, o menor número e a média dos números digitados.*/