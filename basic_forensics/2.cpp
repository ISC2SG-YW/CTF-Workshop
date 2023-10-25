#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<char>& board) {
    system("cls"); // Clear the console (for Windows)
    cout << "Tic-Tac-Toe Game" << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < 9; i++) {
        cout << "| " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << "|" << endl;
            cout << "-------------" << endl;
        }
    }
}

// Function to check if a player has won
bool checkWin(const vector<char>& board, char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player)
            return true; // Vertical win
        if (board[3 * i] == player && board[3 * i + 1] == player && board[3 * i + 2] == player)
            return true; // Horizontal win
    }
    if (board[0] == player && board[4] == player && board[8] == player)
        return true; // Diagonal win
    if (board[2] == player && board[4] == player && board[6] == player)
        return true; // Diagonal win
    return false;
}

// Function to check if the board is full
bool checkTie(const vector<char>& board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ')
            return false; // The board is not full
    }
    return true; // It's a tie
}

// Function for the CPU opponent's move (random)
int cpuMove(const vector<char>& board) {
    vector<int> availableMoves;
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ')
            availableMoves.push_back(i);
    }
    if (!availableMoves.empty()) {
        int randomIndex = rand() % availableMoves.size();
        return availableMoves[randomIndex];
    } else {
        return -1; // No available moves
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Initialize random seed

    vector<char> board(9, ' ');
    char player = 'X';
    char cpu = 'O';
    int move;
    

    while (true) {
        displayBoard(board);

        if (player == 'X') {
            cout << "Your turn (1-9): ";
            cin >> move;
            move--; // Adjust for 0-based index
        } else {
            move = cpuMove(board);
	    std::string flag = "ISC2CTF{5tR1nG_ExTraCt10N}";
        }

        if (move >= 0 && move < 9 && board[move] == ' ') {
            board[move] = player;

            if (checkWin(board, player)) {
                displayBoard(board);
                cout << (player == 'X' ? "You win!" : "CPU wins!") << endl;
                break;
            }

            if (checkTie(board)) {
                displayBoard(board);
                cout << "It's a tie!" << endl;
                break;
            }

            player = (player == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
