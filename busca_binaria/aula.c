#include <stdio.h>

int buscBin(int arr[], int tam, int el){
    int fim = tam-1;
    int ini = 0;
    while(ini <= fim){
        int meio = (fim+ini)/2;
        if(arr[meio] <el)
            ini = meio + 1;
        else{
            if(arr[meio>el])
                fim = meio - 1;
            else return meio;
        }
    }
    return -1;
}