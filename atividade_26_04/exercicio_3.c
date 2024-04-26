#include <stdio.h>

short int contarParesRepetidos(short int num, short int digito) {
  // Variáveis para armazenar a contagem de pares e o número original
  short int cont = 0, numOriginal = num;

  // Verifica se o número original é válido (positivo e maior que zero)
  if (num <= 0) {
    return -1; // Erro: número inválido
  }

  // Extrai os dois dígitos menos significativos do número original
  short int digito1 = num % 100;
  short int digito2 = digito1 / 10;

  // Conta os pares repetidos do dígito especificado
  while (digito1 == digito2 * 10 + digito) {
    cont++;

    // Remove os dígitos contados do número original
    num /= 100;

    // Se o número original chegar a zero, termina o loop
    if (num == 0) {
      break;
    }

    // Extrai os próximos dois dígitos do número original
    digito1 = num % 100;
    digito2 = digito1 / 10;
  }

  return cont;
}

int main() {
  short int num, digito;

  printf("Digite um numero: ");
  scanf("%hd", &num);

  printf("Digite um digito: ");
  scanf("%hd", &digito);

  short int repeticoes = contarParesRepetidos(num, digito);

  if (repeticoes == -1) {
    printf("Numero invalido!\n");
  } else {
    printf("O numero %hd possui %hd pares repetidos do digito %hd.\n", num, repeticoes, digito);
  }

  return 0;
}