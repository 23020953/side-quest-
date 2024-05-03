#include <iostream>
#include <vector>

enum class Player { None, X, O };

class TicTacToe {
private:
    std::vector<std::vector<Player>> board;
    Player currentPlayer;

public:
    TicTacToe() : board(3, std::vector<Player>(3, Player::None)), currentPlayer(Player::X) {}

    void printBoard() {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                char symbol = '-';
                if (cell == Player::X) symbol = 'X';
                else if (cell == Player::O) symbol = 'O';
                std::cout << symbol << " ";
            }
            std::cout << std::endl;
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != Player::None) {
            std::cout << "Invalid move. Try again." << std::endl;
            return false;
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != Player::None && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if (board[0][i] != Player::None && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }
        // Check diagonals
        if (board[0][0] != Player::None && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] != Player::None && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
        return false;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
    }
};

int main() {
    TicTacToe game;
    int row, col;
    bool gameOver = false;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
    while (!gameOver) {
        std::cout << "Current board:" << std::endl;
        game.printBoard();
        std::cout << "Player " << ((game.currentPlayer == Player::X) ? "X" : "O") << ", enter row and column (0-2): ";
        std::cin >> row >> col;
        if (game.makeMove(row, col)) {
            if (game.checkWin()) {
                std::cout << "Player " << ((game.currentPlayer == Player::X) ? "X" : "O") << " wins!" << std::endl;
                gameOver = true;
            } else {
                game.switchPlayer();
            }
        }
    }

    return 0;
}
