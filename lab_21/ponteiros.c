#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da lista ligada
struct Node {
    int info;
    struct Node* next;
};

// Função para criar um novo nó
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->info = data;
    temp->next = NULL;
    return temp;
}

// Função para converter a matriz em lista ligada
struct Node* matrixToList(int M[5][5]) {
    struct Node* head = NULL;
    struct Node* last = NULL;

    // Iterando sobre os elementos da matriz e adicionando à lista
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            struct Node* temp = newNode(M[i][j]);
            if (head == NULL) {
                head = temp;
                last = temp;
            } else {
                last->next = temp;
                last = temp;
            }
        }
    }

    return head;
}

// Função para imprimir a lista ligada
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%02d -> ", temp->info);
        temp = temp->next;
    }
    printf("<<NULL>>\n");
}

// Função principal
int main() {
    int M[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    struct Node* head = matrixToList(M);
    printf("Lista ligada criada a partir da matriz:\n");
    printList(head);

    return 0;
}
