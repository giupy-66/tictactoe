#include <stdio.h>
char tableMatrix[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char player[2] = {'O', 'X'};
//int alreadyUsed[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
//= {{'O', 'O', 'O'}, {'O', 'O', 'O'}, {'O', 'O', 'O'}};

void printTable(void) {
    printf("\n   *   *   ");
    printf("\n %c * %c * %c ", tableMatrix[0][0], tableMatrix[0][1], tableMatrix[0][2]);
    printf("\n   *   *   ");
    printf("\n***********");
    printf("\n   *   *   ");
    printf("\n %c * %c * %c ", tableMatrix[1][0], tableMatrix[1][1], tableMatrix[1][2]);
    printf("\n   *   *   ");
    printf("\n***********");
    printf("\n   *   *   ");
    printf("\n %c * %c * %c ", tableMatrix[2][0], tableMatrix[2][1], tableMatrix[2][2]);
    printf("\n   *   *   ");
}

void userInput(int num) {
    int coordinate = 1, playerSwap = 0;
    printf("\n\nTurno di %c", player[num]);
    printf("\nInserisci il numero in cui vuoi lasciare il segno: ");
    scanf("%d", &coordinate);

    playerSwap = num % 2;
    switch(coordinate) {
        case 1: tableMatrix[0][0] = player[playerSwap]; break;
        case 2: tableMatrix[0][1] = player[playerSwap]; break;
        case 3: tableMatrix[0][2] = player[playerSwap]; break;
        case 4: tableMatrix[1][0] = player[playerSwap]; break;
        case 5: tableMatrix[1][1] = player[playerSwap]; break;
        case 6: tableMatrix[1][2] = player[playerSwap]; break;
        case 7: tableMatrix[2][0] = player[playerSwap]; break;
        case 8: tableMatrix[2][1] = player[playerSwap]; break;
        case 9: tableMatrix[2][2] = player[playerSwap]; break;
    }
}

int findWinner(void) {
    int winnerUser = 3;
    if(tableMatrix[0][0] == 'O' && tableMatrix[0][1] == 'O' && tableMatrix[0][2] == 'O') {winnerUser = 0;}
    if(tableMatrix[1][0] == 'O' && tableMatrix[1][1] == 'O' && tableMatrix[1][2] == 'O') {winnerUser = 0;}
    if(tableMatrix[2][0] == 'O' && tableMatrix[2][1] == 'O' && tableMatrix[2][2] == 'O') {winnerUser = 0;}
    if(tableMatrix[0][0] == 'O' && tableMatrix[1][0] == 'O' && tableMatrix[2][0] == 'O') {winnerUser = 0;}
    if(tableMatrix[0][1] == 'O' && tableMatrix[1][1] == 'O' && tableMatrix[2][1] == 'O') {winnerUser = 0;}
    if(tableMatrix[0][2] == 'O' && tableMatrix[1][2] == 'O' && tableMatrix[2][2] == 'O') {winnerUser = 0;}
    if(tableMatrix[0][0] == 'O' && tableMatrix[1][1] == 'O' && tableMatrix[2][2] == 'O') {winnerUser = 0;}
    if(tableMatrix[0][2] == 'O' && tableMatrix[1][1] == 'O' && tableMatrix[2][0] == 'O') {winnerUser = 0;}

    if(tableMatrix[0][0] == 'X' && tableMatrix[0][1] == 'X' && tableMatrix[0][2] == 'X') {winnerUser = 1;}
    if(tableMatrix[1][0] == 'X' && tableMatrix[1][1] == 'X' && tableMatrix[1][2] == 'X') {winnerUser = 1;}
    if(tableMatrix[2][0] == 'X' && tableMatrix[2][1] == 'X' && tableMatrix[2][2] == 'X') {winnerUser = 1;}
    if(tableMatrix[0][0] == 'X' && tableMatrix[1][0] == 'X' && tableMatrix[2][0] == 'X') {winnerUser = 1;}
    if(tableMatrix[0][1] == 'X' && tableMatrix[1][1] == 'X' && tableMatrix[2][1] == 'X') {winnerUser = 1;}
    if(tableMatrix[0][2] == 'X' && tableMatrix[1][2] == 'X' && tableMatrix[2][2] == 'X') {winnerUser = 1;}
    if(tableMatrix[0][0] == 'X' && tableMatrix[1][1] == 'X' && tableMatrix[2][2] == 'X') {winnerUser = 1;}
    if(tableMatrix[0][2] == 'X' && tableMatrix[1][1] == 'X' && tableMatrix[2][0] == 'X') {winnerUser = 1;}

    return winnerUser;
}

int main(void) {
    int winner = 3;
    int user = 0;
    for(int i = 0; i < 9; i++) {
        printTable();
        userInput(i);
        winner = findWinner();
        system("clear");
        if(winner == 0) {printTable(); printf("\n\nO ha vinto!\n\n"); break;}
        if(winner == 1) {printTable(); printf("\n\nX ha vinto!\n\n"); break;}
    }
}
