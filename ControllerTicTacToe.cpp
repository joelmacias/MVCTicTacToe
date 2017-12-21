/*
 * Implementation file for class ControllerTicTacToe
 */
#include "ControllerTicTacToe.h"

/*
 * Passes players names to the model
 */
void ControllerTicTacToe::startGame(std::string playerXName, std::string playerOName) {
    data.setNames(playerXName, playerOName);
}
/*
 * Returns tic tac toe grid to view for displaying
 */
const std::vector<std::vector<char>>* ControllerTicTacToe::returnGrid(){
    return data.returnGrid();
}

/*
 * Returns true if the game has ended in a draw or win.
 */
bool ControllerTicTacToe::gameOver() {
    Status temp = data.getStatus();
    if(temp == Status::draw or temp == Status::winner){
        return true;
    }
    return false;
}

/*
 * Return the name of the player who won, or empty string if game ended in a draw.
 */
std::string ControllerTicTacToe::gameResult() {
    return data.returnResult();
}

/*
 * Returns the name of the player whose turn it is.
 */
std::string ControllerTicTacToe::getTurn() {
    return data.playerTurn();
}

/*
 * Returns true if the move entered by the player was valid.
 */
bool ControllerTicTacToe::isMoveValid(std::string move){
    return data.getMove(move);
}

/*
 * Returns true if the player's move was out of bounds.
 */
bool ControllerTicTacToe::outOfBounds() {
    return data.getStatus() == Status::outOfBoundsInput ? true : false;
}

/*
 * Returns true if the player's move had been previously chosen by either player.
 */
bool ControllerTicTacToe::spaceTaken(){
    return data.getStatus() == Status::spaceTaken ? true : false;
}

void ControllerTicTacToe::resetGame() {
    data.resetGame();
}