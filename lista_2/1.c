#include <stdio.h>

int main() {
    int num, count = 0;
    int sum = 0;
    float average;
    int max, min;

    printf("Digite números inteiros (um número negativo encerra a entrada):\n");

    while (1) {
        scanf("%d", &num);

        if (num < 0) {
            break;
        }

        if (count == 0) {
            max = min = num;
        } else {
            if (num > max) max = num;
            if (num < min) min = num;
        }

        sum += num;
        count++;
    }

    if (count == 0) {
        printf("Nenhum número válido foi digitado.\n");
    } else {
        average = (float)sum / count;
        printf("Maior número: %d\n", max);
        printf("Menor número: %d\n", min);
        printf("Soma dos números: %d\n", sum);
        printf("Média dos números: %.2f\n", average);
    }

    return 0;
}


/*Explicação do código:

Continua lendo números até que um número negativo seja digitado.
Calcula e exibe o maior número, o menor número, a soma e a média dos números digitados (se houverem entradas válidas).
*/