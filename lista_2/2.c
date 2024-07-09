#include <stdio.h>

int main() {
    int num;

    // Solicita ao usuário um número inteiro positivo menor que 10.000
    printf("Digite um número inteiro positivo menor que 10.000: ");
    scanf("%d", &num);

    // Verifica se o número está dentro do intervalo permitido
    if (num < 0 || num >= 10000) {
        printf("Número inválido. Por favor, insira um número inteiro positivo menor que 10.000.\n");
        return 1;
    }

    // Calcula o valor das unidades, dezenas, centenas e milhares
    int unidade = num % 10;
    int dezena = (num / 10) % 10;
    int centena = (num / 100) % 10;
    int milhar = (num / 1000) % 10;

    // Exibe os resultados
    printf("Unidade: %d\n", unidade);
    printf("Dezena: %d\n", dezena);
    printf("Centena: %d\n", centena);
    printf("Milhar: %d\n", milhar);

    return 0;
}

/*Explicação do código:
Entrada do usuário: O programa solicita ao usuário que insira um número inteiro positivo menor que 10.000.
Verificação de intervalo: O programa verifica se o número inserido está dentro do intervalo permitido (0 <= num < 10000). Se o número for inválido, uma mensagem de erro é exibida e o programa termina.
Cálculo das unidades, dezenas, centenas e milhares:
unidade é calculada como num % 10.
dezena é calculada como (num / 10) % 10.
centena é calculada como (num / 100) % 10.
milhar é calculada como (num / 1000) % 10.
Exibição dos resultados: Os valores das unidades, dezenas, centenas e milhares são exibidos.
*/