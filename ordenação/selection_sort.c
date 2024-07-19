int posMenorEl(int v[], int tam, int inicio){
    int i, posMenor;
    posMenor = -1;
    if ((inicio>=0) && (inicio<tam)){
        posMenor = inicio;
        for (i=inicio+1; i<tam; i++)
            if (v[i] < v[posMenor]) posMenor = i;
    }
    return (posMenor);
}

void selecao(int v[], int tam) {
    int i, posMenor, aux;
    for (i=0; i<tam-1; i++){
        int posMenor = posMenorEl(v, tam, i);
        aux = v[i];
        v[i] = v[posMenor];
        v[posMenor] = aux;
    }
}