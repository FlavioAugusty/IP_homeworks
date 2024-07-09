#include <stdio.h>

// Função que converte Celsius para Fahrenheit
double celsiusParaFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

int main() {
    double celsius, fahrenheit;

    // Solicita ao usuário para entrar com a temperatura em Celsius
    printf("Digite a temperatura em graus Celsius: ");
    scanf("%lf", &celsius);

    // Converte a temperatura para Fahrenheit
    fahrenheit = celsiusParaFahrenheit(celsius);

    // Exibe a temperatura convertida
    printf("A temperatura em graus Fahrenheit é: %.2f\n", fahrenheit);

    return 0;
}

/*
Explicação do código:
Função celsiusParaFahrenheit:

Recebe um valor em graus Celsius.
Converte esse valor para Fahrenheit usando a fórmula 
𝑇𝐹=(𝑇𝐶×9/5)+32
Retorna o valor convertido.
Função main:

Solicita ao usuário que insira uma temperatura em graus Celsius.
Lê o valor digitado.
Chama a função celsiusParaFahrenheit para converter o valor para Fahrenheit.
Exibe o resultado.*/