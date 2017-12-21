/*
 * Header file for class player, and class ModelTicTacToe
 */
#ifndef TICTACTOEMVC_MODELTICTACTOE_H
#define TICTACTOEMVC_MODELTICTACTOE_H

#include<vector>
#include<string>

/*
 * Represents the current status of the tic tac toe game
 * The game status can be 'outOfBoundsInput' if input received was not within bounds,
 * 'spaceTaken' if the selected square was previously selected
 * 'draw' if the game ended in a draw
 * 'winner' if their was a winner
 */
enum class Status {
    outOfBoundsInput,
    spaceTaken,
    validInput,
    draw,
    winner
};

/*
* Represents a single player playing tic tac toe.
* Stores the player's name, their mark either 'O' or 'X', and if the player has won
*/

class Player {
public:
    Player() = default;
    ~Player() = default;
    /*
     * Sets players names.
     */
    void initializePlayer(std::string playerName, char playerMark);
    /*
     * Returns players name.
     */
    std::string getName();
    /*
     * Returns players mark.
     */
    char getMark();
    /*
     * Sets the players 'winner' flag to true.
     */
    void updateDidWin();
    /*
     * Returns true if the player has won.
     */
    bool didWin();
private:
    /*
     * Name of the player.
     */
    std::string name;
    /*
     * Player's mark, either 'X' or 'O'.
     */
    char mark;
    /*
     * Players winner flag.
     */
    bool winner = false;

};

/*
 *  Represents a game of tic tac toe with a 3x3 2D vector
 *  Defines data, logic, and computations necessary for a tic tac toe game
 */
class ModelTicTacToe {
public:
    ModelTicTacToe();
    ~ModelTicTacToe() = default;
    /*
     * Returns most up to date const grid
     */
    const std::vector<std::vector<char>>* returnGrid();
    /*
     * Sets the names, and marks of both players
     */
    void setNames(std::string nameOne, std::string nameTwo);
    /*
     * Returns the current status of the game. Look above at enum Status class for description of
     * what the statuses may be
     */
    Status getStatus();
    /*
     * Returns the name of the player whose turn it is
     */
    std::string playerTurn();
    /*
     * Returns false if the move is invalid, otherwise updates the grid with the move, and the game status.
     */
    bool getMove(std::string move);
    /*
     * Returns the player's name who won, or empty string if the game was a draw
     */
    std::string returnResult();
    /*
     * Resets the current game setting all members to their original values
     */
    void resetGame();

    void fillTable();


private:
    void checkIfWon(int row, int col);
    bool updateGrid(int row, int col);
    /*
     * Representation of tic tac toe game
     */
    std::vector<std::vector<char>>grid{3,std::vector<char>(3)};
    Player playerX;
    Player playerO;
    Status gameStatus = Status::validInput;
    /*
     * When it is PlayerX's turn xTurn will be true
     */
    bool xTurn = true;
    unsigned short numberOfMoves = 0;
    /*
     * Minimum number of moves required for a player to win
     */
    const unsigned short minimumMovesToWin = 5;
    /*
     * Maximum number of moves until game is a draw.
     */
    const unsigned short maxMoves = 9;
};


#endif //TICTACTOEMVC_MODELTICTACTOE_H
