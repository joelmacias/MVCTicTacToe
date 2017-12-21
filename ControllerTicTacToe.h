/*
 * Header file for class ControllerTicTacToe
 */
#ifndef TICTACTOEMVC_CONTROLLERTICTACTOE_H
#define TICTACTOEMVC_CONTROLLERTICTACTOE_H

#include "ModelTicTacToe.h"
#include <string>

/*
 * Interprets user input from the view and sends it to the model.
 * Interprets model response to data given sending appropriate response to view
 */
class ControllerTicTacToe {
public:
    ControllerTicTacToe() = default;
    ~ControllerTicTacToe() = default;
    const std::vector<std::vector<char>>* returnGrid();
    /*
     * Passes player names to the model, starting the game.
     */
    void startGame(std::string playerXName, std::string playerOName);
    /*
     * Returns true if the game has ended in a draw or a win.
     */
    bool gameOver();
    /*
     * Returns the name of the player whose turn it is.
     */
    std::string getTurn();
    /*
     * Returns true if the move entered by the player was valid
     */
    bool isMoveValid(std::string move);
    /*
     * Returns true if the move entered by the player was out of bounds
     */
    bool outOfBounds();
    /*
     * Returns true of the move entered by the user was already chosen by either user
     */
    bool spaceTaken();
    /*
     * Returns the name of the player who won, or empty string if the game ended in a draw.
     */
    std::string gameResult();
    void resetGame();
private:
    /*
     * All the data, and logic of the tic tac toe game
     */
    ModelTicTacToe data;

};


#endif //TICTACTOEMVC_CONTROLLERTICTACTOE_H
