#include <stdio.h>

char board[3][3];  // 3x3 board

// Function to initialize the board
void initializeBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = num++;
        }
    }
}

// Function to display the board
void printBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("\n---|---|---\n");
    }
    printf("\n\n");
}

// Function to check if a player has won
int checkWin() {
    // Rows and Columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]))
            return 1;
        if ((board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            return 1;
    }
    // Diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]))
        return 1;
    if ((board[0][2] == board[1][1] && board[1][1] == board[2][0]))
        return 1;

    return 0;
}

// Function to check if the board is full
int isFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
        }
    }
    return 1;
}

// Main game logic
int main() {
    int player = 1, choice, row, col;
    char mark;

    initializeBoard();

    do {
        printBoard();
        player = (player % 2) ? 1 : 2;
        mark = (player == 1) ? 'X' : 'O';

        printf("Player %d, enter a number (1-9): ", player);
        scanf("%d", &choice);

        // Map choice to row and column
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check if the cell is empty
        if (choice >= 1 && choice <= 9 && board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = mark;
        } else {
            printf("Invalid move! Try again.\n");
            player--;  // repeat the same player's turn
        }

        if (checkWin()) {
            printBoard();
            printf("==> Player %d wins!\n", player);
            return 0;
        }

        player++;
    } while (!isFull());

    printBoard();
    printf("==> It's a draw!\n");

    return 0;
}
