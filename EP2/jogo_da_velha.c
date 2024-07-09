/*Flavio Augusto Faustino de Carvalho NUSP: 15452444



Explicação do código:
Inicialização do tabuleiro: O tabuleiro é representado por uma matriz 3x3 de caracteres, onde cada posição pode ser ' ' (vazia), 'A' (jogador A) ou 'B' (jogador B).

Funções auxiliares:

initializeBoard: Inicializa o tabuleiro com espaços vazios.
printBoard: Imprime o tabuleiro no console.
checkWin: Verifica se há um vencedor. Retorna 1 se houver um vencedor, caso contrário, retorna 0.
checkDraw: Verifica se o jogo terminou em empate. Retorna 1 se todas as posições estiverem preenchidas e não houver um vencedor, caso contrário, retorna 0.
makeMove: Permite que um jogador faça uma jogada, garantindo que a jogada é válida (dentro dos limites e em uma posição vazia).
Lógica do jogo: O jogo alterna entre os dois jogadores até que haja um vencedor ou todas as posições estejam preenchidas (empate). A cada jogada, o tabuleiro é impresso, e o status do jogo é verificado.*/


#include <stdio.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
int checkDraw(char board[SIZE][SIZE]);
void makeMove(char board[SIZE][SIZE], int player);

int main() {
    char board[SIZE][SIZE];
    int player = 0; // 0 para jogador A, 1 para jogador B
    int gameStatus = 0; // 0 para continuar, 1 para vitória, 2 para empate

    initializeBoard(board);

    while (gameStatus == 0) {
        printBoard(board);
        makeMove(board, player);
        gameStatus = checkWin(board);

        if (gameStatus == 0 && checkDraw(board)) {
            gameStatus = 2;
        }

        player = !player; // Alterna entre os jogadores
    }

    printBoard(board);

    if (gameStatus == 1) {
        printf("Jogador %c venceu!\n", player ? 'A' : 'B');
    } else if (gameStatus == 2) {
        printf("O jogo terminou em empate!\n");
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("  0 1 2\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("  -+-+-\n");
        }
    }
}

int checkWin(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }

    return 0;
}

int checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void makeMove(char board[SIZE][SIZE], int player) {
    int row, col;
    char mark = player ? 'B' : 'A';

    while (1) {
        printf("Jogador %c, insira sua jogada (linha e coluna): ", mark);
        if (scanf("%d %d", &row, &col) != 2) {
            printf("Entrada inválida! Por favor, insira dois números inteiros.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = mark;
            break;
        } else {
            printf("Jogada inválida! Tente novamente.\n");
        }
    }
}
/*Verificação de entrada inválida:

scanf("%d %d", &row, &col) verifica se dois inteiros foram inseridos.
Se a entrada não for válida (scanf não retorna 2), uma mensagem de erro é exibida e o buffer de entrada é limpo com while (getchar() != '\n');.

Limpeza do buffer de entrada:

Após uma entrada inválida, o buffer de entrada é limpo para evitar loops infinitos ou comportamento inesperado.*/