#include <stdio.h>

short int ehPalindromo(short int num) {
  // Se o número for menor que 0, não é palíndromo
  if (num < 0) {
    return 0;
  }

  // Variáveis para armazenar o número original e o número revertido
  short int numOriginal = num, numRevertido = 0;

  // Inverte o número
  while (numOriginal > 0) {
    short int digito = numOriginal % 10;
    numRevertido = numRevertido * 10 + digito;
    numOriginal /= 10;
  }

  // Compara o número original com o número revertido
  if (num == numRevertido) {
    return 1; // É palíndromo
  } else {
    return 0; // Não é palíndromo
  }
}

int main() {
  short int num;

  printf("Digite um numero: ");
  scanf("%hd", &num);

  if (ehPalindromo(num)) {
    printf("%hd eh um palindromo!\n", num);
  } else {
    printf("%hd nao eh um palindromo.\n", num);
  }

  return 0;
}