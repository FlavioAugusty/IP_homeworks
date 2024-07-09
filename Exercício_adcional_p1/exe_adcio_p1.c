#include <stdio.h>

int main() {
    int DD, MM, AAAA;

    printf("Digite o dia desejado (2 digitos): ");
    scanf("%d", &DD);

    printf("Digite o mes desejado (2 digitos): ");
    scanf("%d", &MM);

    printf("Digite o ano desejado (4 digitos): ");
    scanf("%d", &AAAA);

    if (DD == 29 && MM == 2 && (AAAA % 4 != 0 || (AAAA % 100 == 0 && AAAA % 400 != 0))) {
        printf("Essa data nao eh valida, o ano digitado nao eh bissexto\n");
    } else if (DD == 31 && (MM != 1 && MM != 3 && MM != 5 && MM != 7 && MM != 8 && MM != 10 && MM != 12)) {
        printf("Essa data nao existe, o mes %d nao tem 31 dias\n", MM);
    } else if (DD == 30 && MM == 2) {
        printf("O mes digitado só tem 28 dias, ou 29 em anos bissextos\n");
    } else if (DD > 31 || DD <= 0) {
        printf("Nenhum mes tem mais de 31 dias ou números negativos\n");
    } else if(MM > 12){
        printf("Nao existe o mes %d", &MM)
    } else {
        printf("A data %d/%d/%d eh valida\n", DD, MM, AAAA);
    }

    return 0;
}
