#include <stdio.h>

int main() {
  // Declaração de variáveis
  short int quantidade, numero, primo, contadorPrimos = 0;

  // Leitura da quantidade de números a serem inseridos
  printf("Digite a quantidade de numeros: ");
  scanf("%hd", &quantidade);

  // Loop para leitura e validação dos números
  for (short int i = 1; i <= quantidade; i++) {
    printf("Digite o numero %hd: ", i);
    scanf("%hd", &numero);

    // Validação se o número é positivo
    if (numero <= 0) {
      printf("Erro: O numero digitado deve ser positivo.\n");
      continue; // Ignora o número inválido e continua o loop
    }

    // Verificação se o número é primo
    primo = 1; // Assume que o número é primo inicialmente
    for (short int divisor = 2; divisor <= numero / 2; divisor++) {
      if (numero % divisor == 0) {
        primo = 0; // Se encontrar um divisor, o número não é primo
        break;
      }
    }

    // Contagem de números primos
    if (primo) {
      contadorPrimos++;
    }
  }

  // Impressão da quantidade de números primos encontrados
  printf("Total de números primos: %hd\n", contadorPrimos);

  return 0;
}
