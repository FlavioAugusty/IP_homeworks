#include <stdio.h>
#include <string.h>

void decimalParaBinario(int n, char* binario) {
    int index = 0;
    if (n == 0) {
        binario[index++] = '0';
        binario[index] = '\0';
        return;
    }

    while (n > 0) {
        binario[index++] = (n % 2) + '0';
        n /= 2;
    }

    binario[index] = '\0';

    // Inverter a string binária
    for (int i = 0; i < index / 2; ++i) {
        char temp = binario[i];
        binario[i] = binario[index - 1 - i];
        binario[index - 1 - i] = temp;
    }
}

int main() {
    int n;
    char binario[33]; // Para armazenar até 32 bits + terminador nulo

    // Solicita ao usuário um número inteiro
    printf("Digite um número inteiro maior ou igual a 0: ");
    scanf("%d", &n);

    // Verifica se o número é válido
    if (n < 0) {
        printf("Número inválido. Por favor, insira um número maior ou igual a 0.\n");
        return 1;
    }

    // Converte o número para binário
    decimalParaBinario(n, binario);

    // Exibe o resultado
    printf("O número %d em binário é: %s\n", n, binario);

    return 0;
}

/*
Explicação do Código:
Função decimalParaBinario:

Converte um número decimal n para sua representação binária.
Armazena o resultado na string binario.
Se n for 0, armazena "0" na string binario.
Usa um loop para calcular os restos da divisão de n por 2 e armazena cada resto na string.
A string binario é construída ao contrário, então a função a inverte no final.
Função main:

Solicita ao usuário que insira um número inteiro.
Verifica se o número é válido (maior ou igual a 0).
Chama a função decimalParaBinario para converter o número.
Exibe o resultado em binário.
*/