/*
 * Header file for ViewTicTacToe class
 */
#ifndef TICTACTOEMVC_VIEWTICTACTOE_H
#define TICTACTOEMVC_VIEWTICTACTOE_H

#include "ControllerTicTacToe.h"


/*
 * Responsible for starting a tic tac toe game, printing the game board,
 * prompting, accepting, and handing user input to controller.
 */
class ViewTicTacToe {
public:
    /*
     * Starts a game of tic tac toe. Will start a new game until users decide to stop playing
     */
    ViewTicTacToe();
    ~ViewTicTacToe() = default;
    /*
     * Prints the current tic tac toe game
     */
    void printBoard();
private:
    /*
     * Responsible for sending user's input to model, and sending model's response to view.
     */
   ControllerTicTacToe controller;
    /*
     * Prompts user for input, accepts input, sends input to controller, takes appropriate action with controller's
     * response to input
     */
    bool playGame();

};


#endif //TICTACTOEMVC_VIEWTICTACTOE_H
