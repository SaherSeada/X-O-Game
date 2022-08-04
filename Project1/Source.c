#include <stdio.h>
#include <stdbool.h>

char square[9] = { '1' ,'2', '3' ,'4' , '5', '6', '7', '8', '9' };

void drawBoard() {
    
    printf("Player 1 (X)  -  Player 2 (O)\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[0], square[1], square[2]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[3], square[4], square[5]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[6], square[7], square[8]);

    printf("     |     |     \n\n");
}

bool checkWin() {
    for (int i = 0; i < 6; i += 3) {
        if (square[i] == square[i + 1] && square[i] == square[i + 2]) {
            return true;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (square[i] == square[i + 3] && square[i] == square[i + 6]) {
            return true;
        }
    }
    if ((square[0] == square[4] && square[0] == square[8]) || (square[2] == square[4] && square[2] == square[6])) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    int player = 1 , mark,  position, turn = 1;
    
    printf("\n\tTic Tac Toe\n\n");
    
    while (checkWin() == false) {
        if (turn % 2 == 0) {
            player = 2;
            mark = 'O';
        }
        else {
            player = 1;
            mark = 'X';
        }
        drawBoard();
        printf("\nPlayer %d, please enter a position \n", player);
        scanf_s("%d", &position);
        if (square[position - 1] == 'X' || square[position - 1] == 'O') {
            printf("\nPosition taken, please enter another one\n");
            continue;
        }
        square[position - 1] = mark;
        if (turn == 9) {
            break;
        }
        turn++;
    }
    drawBoard();
    if (checkWin()) {
        printf("\nPlayer %d won!\n\n", player);
    }
    else {
        printf("\nTie game, no one won!\n");
    }
}
