#include <bits/stdc++.h>
using namespace std;

void printSolution(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int col : row) cout << (col ? "Q" : ".") << " ";
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < col; i++) if (board[row][i]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
    for (int i = row, j = col; i < board.size() && j >= 0; i++, j--) if (board[i][j]) return false;
    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col) {
    if (col == board.size()) return printSolution(board), true;
    for (int i = 0; i < board.size(); i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            solveNQueensUtil(board, col + 1);
            board[i][col] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solveNQueensUtil(board, 0);
    return 0;
}
