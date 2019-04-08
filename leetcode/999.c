//
// Created by 吴俊贤<mailto:wu812730157@gmail.com> on 19-3-24.
//

#include <stdlib.h>

int numRookCaptures(char **board, int boardRowSize, int boardColSize) {
    int Rx = 0;
    int Ry = 0;
    int found = 0;
    for (int i = 0; i < boardRowSize && !found; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (board[i][j] == 'R') {
                Rx = i;
                Ry = j;
                found = 1;
                break;
            }
        }
    }

    int result = 0;

    // go up
    int i;
    for (i = Ry - 1; i >= 0 && board[Rx][i] == '.'; i--);
    if (board[Rx][i] == 'p')
        result++;

    // go down
    for (i = Ry + 1; i < boardRowSize && board[Rx][i] == '.'; i++);
    if (board[Rx][i] == 'p')
        result++;

    // go left
    for (i = Rx - 1; i >= 0 && board[i][Ry] == '.'; i--);
    if (board[i][Ry] == 'p')
        result++;

    // go right
    for (i = Rx + 1; i < boardColSize && board[i][Ry] == '.'; i++);
    if (board[i][Ry] == 'p')
        result++;

    return result;
}

int main() {
    char board[] = {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', 'p', '.', '.', '.', '.', '.', '.', '.', 'R',
                    '.', '.', '.', 'p', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
                    '.', '.', '.', 'p', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
                    '.', '.', '.', '.'};

    char *bp[8];
    for (int i = 0; i < 8; i++) {
        bp[i] = board + i * 8;
    }


    numRookCaptures(bp, 8, 8);

}

