#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 8

char board[SIZE][SIZE];

// Initialize chess board
void initBoard() {
    char init[8][9] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = init[i][j];
}

// Print chess board
void printBoard() {
    printf("\n   a b c d e f g h\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d  ", 8 - i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf(" %d", 8 - i);
        printf("\n");
    }
    printf("   a b c d e f g h\n\n");
}

// Convert chess notation to board indices
int notationToIndex(char file, char rank, int *row, int *col) {
    if (file < 'a' || file > 'h' || rank < '1' || rank > '8')
        return 0;
    *col = file - 'a';
    *row = 8 - (rank - '0');
    return 1;
}

// Simple move function (no rule validation yet)
int movePiece(char fromFile, char fromRank, char toFile, char toRank) {
    int r1, c1, r2, c2;

    if (!notationToIndex(fromFile, fromRank, &r1, &c1)) return 0;
    if (!notationToIndex(toFile, toRank, &r2, &c2)) return 0;

    char piece = board[r1][c1];
    if (piece == '.') return 0;  // No piece to move

    board[r2][c2] = piece;
    board[r1][c1] = '.';
    return 1;
}

// Main game loop
int main() {
    char fromFile, toFile;
    char fromRank, toRank;
    int turn = 0; // 0 = White, 1 = Black

    initBoard();
    printBoard();

    while (1) {
        printf("%s's move (e.g., e2 e4): ",
               (turn == 0) ? "White" : "Black");

        if (scanf(" %c%c %c%c", &fromFile, &fromRank, &toFile, &toRank) != 4) {
            printf("Invalid input. Use format like e2 e4.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        if (!movePiece(fromFile, fromRank, toFile, toRank)) {
            printf("Invalid move! Try again.\n");
            continue;
        }

        printBoard();
        turn = 1 - turn; // Switch turns
    }

    return 0;
}
