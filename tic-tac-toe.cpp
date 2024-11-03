#include <iostream>
#include <string>
using namespace std;

void print(char arr[5][9]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

void check(char arr[5][9], bool& b) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((arr[2 * i][0] == arr[2 * i][4] && arr[2 * i][4] == arr[2 * i][8]) && arr[2 * i][0] != ' ') { 
            b = true;
            return;
        }
        if ((arr[0][4 * i] == arr[2][4 * i] && arr[2][4 * i] == arr[4][4 * i]) && arr[0][4 * i] != ' ') {
            b = true;
            return;
        }
    }

    // Check diagonals
    if ((arr[0][0] == arr[2][4] && arr[2][4] == arr[4][8] && arr[0][0] != ' ') ||
        (arr[0][8] == arr[2][4] && arr[2][4] == arr[4][0] && arr[0][8] != ' ')) {
        b = true;
    } else {
        b = false;
    }
}

void loopx(char arr[5][9], int m) {
    switch (m) {
        case 1: arr[0][0] = 'x'; break;
        case 2: arr[0][4] = 'x'; break;
        case 3: arr[0][8] = 'x'; break;
        case 4: arr[2][0] = 'x'; break;
        case 5: arr[2][4] = 'x'; break;
        case 6: arr[2][8] = 'x'; break;
        case 7: arr[4][0] = 'x'; break;
        case 8: arr[4][4] = 'x'; break;
        case 9: arr[4][8] = 'x'; break;
    }
}

void loop0(char arr[5][9], int M) {
    switch (M) {
        case 1: arr[0][0] = '0'; break;
        case 2: arr[0][4] = '0'; break;
        case 3: arr[0][8] = '0'; break;
        case 4: arr[2][0] = '0'; break;
        case 5: arr[2][4] = '0'; break;
        case 6: arr[2][8] = '0'; break;
        case 7: arr[4][0] = '0'; break;
        case 8: arr[4][4] = '0'; break;
        case 9: arr[4][8] = '0'; break;
    }
}

bool isValidMove(int move, int moves[], int moveCount) {
    for (int i = 0; i < moveCount; i++) {
        if (moves[i] == move) {
            return false;
        }
    }
    return true;
}

int main() {
    char arr[5][9] = {
        {'1', ' ', '|', ' ', '2', ' ', '|', ' ', '3'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'4', ' ', '|', ' ', '5', ' ', '|', ' ', '6'},
        {'-', '-', '-', '-', '-', '-', '-', '-', '-'},
        {'7', ' ', '|', ' ', '8', ' ', '|', ' ', '9'}
    };

    print(arr);
    cout << "Welcome to this tic-tac-toe game\n";

    // Naming of players
    string p1, p2;
    cout << "Player 1 name: ";
    cin >> p1;
    cout << p1 << ", your sign is 'x'\n";
    cout << "Player 2 name: ";
    cin >> p2;
    cout << p2 << ", your sign is '0'. Let's start the game\n";

    int moves[9]; // To store all the used positions
    int moveCount = 0; // To track number of moves
    bool b = false; // To track if anyone has won

    while (moveCount < 9 && !b) {
        int m, M;

        // X's turn
        cout << p1 << "'s turn. Choose your option (1-9): ";
        cin >> m;
        if (m >= 1 && m <= 9 && isValidMove(m, moves, moveCount)) {
            moves[moveCount++] = m;
            loopx(arr, m);
            print(arr);
            check(arr, b);
            if (b) {
                cout << p1 << " wins!\n";
                break;
            }
        } else {
            cout << "Invalid move. Please choose a valid option.\n";
            continue;
        }

        // If all moves are made without a winner, it's a draw
        if (moveCount == 9) {
            cout << "It's a draw!\n";
            break;
        }

        // O's turn
        cout << p2 << "'s turn. Choose your option (1-9): ";
        cin >> M;
        if (M >= 1 && M <= 9 && isValidMove(M, moves, moveCount)) {
            moves[moveCount++] = M;
            loop0(arr, M);
            print(arr);
            check(arr, b);
            if (b) {
                cout << p2 << " wins!\n";
                break;
            }
        } else {
            cout << "Invalid move. Please choose a valid option.\n";
            continue;
        }
    }

    cout << "Game over\nThis game was created by PRIYANSHU VERMA\n";
    return 0;
}