#include <iostream>

// Encapsulate game-related elements in a class
class TicTacToeGame {
public:
    TicTacToeGame();
    void play();

private:
    char gameBoard[3][3];
    char currentPlayer;
    bool isDraw;
    bool selected[9];

    void initializeGame();
    void displayBoard();
    void makeMove(int);
    void switchPlayer();
    bool checkVictory();
    bool checkDraw();
    void showReferenceBoard();
};

// Constructor to initialize the game
TicTacToeGame::TicTacToeGame() {
    initializeGame();
}

// Main game loop
void TicTacToeGame::play() {
    showReferenceBoard();

    while (!checkVictory() && !isDraw) {
        displayBoard();

        // GET PLAYER MOVE
        int move;
        std::cout << "Player " << currentPlayer << " enter move(1 to 9): ";
        std::cin >> move;

        // check if number has already been chosen
        while (selected[move - 1]) {
            std::cout << "That number has already been chosen. Please choose a different number: ";
            std::cin >> move;
        }

        // mark number as chosen and place player's mark on board
        selected[move - 1] = true;
        makeMove(move);

        // CHECK GAME STATE
        isDraw = checkDraw();
        switchPlayer();
    }

    // DISPLAY FINAL BOARD AND RESULT
    displayBoard();
    if (checkVictory()) {
        std::cout << "Congrats Player " << currentPlayer << ", you won!\n";
    } else {
        std::cout << "The game was a draw\n";
    }
}

// Print reference board
void TicTacToeGame::showReferenceBoard() {
    std::cout << "Reference Board:" << std::endl;
    std::cout << "1 | 2 | 3" << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << "4 | 5 | 6" << std::endl;
    std::cout << "---------" << std::endl;
    std::cout << "7 | 8 | 9" << std::endl;
    std::cout << "\n";
    std::cout << "Now let's start the game!\n";
}

// Initialize the game
void TicTacToeGame::initializeGame() {
    // Clear the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            gameBoard[i][j] = ' ';
        }
    }

    currentPlayer = 'X';
    isDraw = false;

    // Clear selected array
    for (int i = 0; i < 9; i++) {
        selected[i] = false;
    }
}

// Print the current board state
void TicTacToeGame::displayBoard() {
    // Print the current board state
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << gameBoard[i][j];
            if (j != 2) std::cout << " | ";
        }
        if (i != 2) std::cout << "\n----------\n";
        else std::cout << "\n";
    }
}

// Switch player turns
void TicTacToeGame::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Check if there is a winner
bool TicTacToeGame::checkVictory() {
    // Check rows
    for (int i = 0; i < 3; i++)
        if (gameBoard[i][0] == currentPlayer && gameBoard[i][1] == currentPlayer && gameBoard[i][2] == currentPlayer)
            return true;

    // Check columns
    for (int j = 0; j < 3; j++)
        if (gameBoard[0][j] == currentPlayer && gameBoard[1][j] == currentPlayer && gameBoard[2][j] == currentPlayer)
            return true;

    // Check diagonals
    if (gameBoard[0][0] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[2][2] == currentPlayer)
        return true;
    if (gameBoard[0][2] == currentPlayer && gameBoard[1][1] == currentPlayer && gameBoard[2][0] == currentPlayer)
        return true;

    return false;
}

// Verify if the game has ended in a draw
bool TicTacToeGame::checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // If any cell is empty, no draw yet
            if (gameBoard[i][j] == ' ')
                return false;
        }
    }

    return true;
}

// Make a move on the board
void TicTacToeGame::makeMove(int move) {
    int row, col;

    if (move == 1) { row = 0; col = 0; }
    else if (move == 2) { row = 0; col = 1; }
    else if (move == 3) { row = 0; col = 2; }
    else if (move == 4) { row = 1; col = 0; }
    else if (move == 5) { row = 1; col = 1; }
    else if (move == 6) { row = 1; col = 2; }
    else if (move == 7) { row = 2; col = 0; }
    else if (move == 8) { row = 2; col = 1; }
    else if (move == 9) { row = 2; col = 2; }
    else {
        std::cout << "Invalid move!\n";
        return;
    }

    gameBoard[row][col] = currentPlayer;
}

int main() {
    // Create an instance of the TicTacToeGame class and start the game
    TicTacToeGame game;
    game.play();

    return 0;
}
