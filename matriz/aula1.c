#include <stdio.h>
#include <stdlib.h>

int main(){
    char nomes[4][10] = {
        {'A','l','v','e','n','a','r','i','a','\0'},
        {'V','i','n','i','l','\0'},{'F','i','b','r','a','\0'},
        {'P','l','a','s','t','i','c','o','\0'}
    };

    char** nome2 = (char**) malloc(sizeof(char*)*4);
    nome2[0] = (char*) malloc(sizeof(char)*10);
    nome2[1] = (char*) malloc(sizeof(char)*6);
    nome2[2] = (char*) malloc(sizeof(char)*6);
    nome2[3] = (char*) malloc(sizeof(char)*9);

    int x, y;
    for (x=0; x<4; x++){
        y = -1;
        do {
            y++;
            nome2[x][y] = nomes[x][y];
        }while (nomes[x][y] != '\0');
    }
    for (x=0;x<4;x++) printf("%s\n", nome2[x]);
    return 0;
}