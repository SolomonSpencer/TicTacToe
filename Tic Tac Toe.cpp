#include <iostream>

using namespace std;

void displayBoard(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << board[i][j] << " | ";
    }
    cout << endl << "---------" << endl;
  }
}

bool checkWinner(char board[3][3], char symbol) {
  for (int i = 0; i < 3; i++) {
    if ((board[i][0] == symbol && board[i][1] == symbol &&
         board[i][2] == symbol) ||
        (board[0][i] == symbol && board[1][i] == symbol &&
         board[2][i] == symbol)) {
      return true;
    }
  }

  if ((board[0][0] == symbol && board[1][1] == symbol &&
       board[2][2] == symbol) ||
      (board[0][2] == symbol && board[1][1] == symbol &&
       board[2][0] == symbol)) {
    return true;
  }

  return false;
}

bool checkTie(char board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == '*') {
        return false;
      }
    }
  }
  return true;
}

int main() {
  char board[3][3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = '*';
    }
  }

  int row, col;
  char player1 = 'X';
  char player2 = 'O';
  char currentPlayer = player1;

  while (true) {
    displayBoard(board);

    cout << "Player " << (currentPlayer == player1 ? "1" : "2")
         << ", enter the row number (0, 1, or 2): ";
    cin >> row;
    cout << "Player " << (currentPlayer == player1 ? "1" : "2")
         << ", enter the column number (0, 1, or 2): ";
    cin >> col;

    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '*') {
      cout << "Invalid move. Try again." << endl;
      continue;
    }

    board[row][col] = currentPlayer;

    if (checkWinner(board, currentPlayer)) {
      displayBoard(board);
      cout << "Player " << (currentPlayer == player1 ? "1" : "2") << " wins!"
           << endl;
      break;
    }

    if (checkTie(board)) {
      displayBoard(board);
      cout << "It's a tie!" << endl;
      break;
    }

    currentPlayer = (currentPlayer == player1) ? player2 : player1;
  }

  return 0;
}