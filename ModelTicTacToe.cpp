/*
 * Implementation file for class Player and ModelTicTacToe
 */
#include "ModelTicTacToe.h"
#include <iostream>

void Player::initializePlayer(std::string playerName, char playerMark) {
    name = playerName;
    mark = playerMark;
}
std::string Player::getName() {
    return name;
}

char Player::getMark() {
    return mark;
}

void Player::updateDidWin(){
        winner = true;
    }
bool Player::didWin(){
        return winner or false;
    }

/* Fills 3x3 grid with chars '1' through '9'. Players will enter '1' through '9' to indicate the position they
 * wish to fill with their mark.
 */
ModelTicTacToe::ModelTicTacToe() {
    fillTable();
}

void ModelTicTacToe::fillTable(){
    char pos = '1';
    for(auto it = grid.begin(); it != grid.end(); ++it){
        for(auto vecIt = it->begin(); vecIt != it->end(); ++vecIt){
            *vecIt = pos;
            ++pos;
        }
    }
}

void ModelTicTacToe::setNames(std::string nameOne, std::string nameTwo) {
    playerX.initializePlayer(nameOne, 'X');
    playerO.initializePlayer(nameTwo, 'O');
}


const std::vector<std::vector<char>>* ModelTicTacToe::returnGrid(){
    return &grid;
}

Status ModelTicTacToe::getStatus(){
    return gameStatus;
}

std::string ModelTicTacToe::playerTurn() {
    return xTurn ? playerX.getName() : playerO.getName();
}
/*
* Determines if current move caused a win, draw, or is just a valid move. Will change the status
* of the game accordingly.
*/
void ModelTicTacToe::checkIfWon(int row, int col) {
    char mark = grid[row][col];
    if(mark == grid[row][0] and mark == grid[row][1] and mark == grid[row][2]){
        gameStatus = Status::winner;
    }
    else if(mark == grid[0][col] and mark == grid[1][col] and mark == grid[2][col]){
        gameStatus = Status::winner;
    }
    else if(row == col and mark == grid[0][0] and  mark == grid[1][1] and mark == grid[2][2]){
            gameStatus = Status::winner;
    }
    else if(row + col == 2 and mark == grid[0][2] and mark == grid[1][1] and mark == grid[2][0]){
            gameStatus = Status::winner;
    }
    else if(numberOfMoves == maxMoves){
        gameStatus = Status::draw;
    }
    else{
        gameStatus = Status::validInput;
    }
}
/*
* Determines if the current move is invalid, if not invalid then the grid will be updated
* with the current player's mark, number of total moves is updated, and checks if current move caused
* the current player to win.
 */
bool ModelTicTacToe::updateGrid(int row, int col) {
    if(grid[row][col] == 'X' or grid[row][col] == 'O'){
        gameStatus = Status::spaceTaken;
        return false;
    }
    ++numberOfMoves;
    if(xTurn){
        grid[row][col] = playerX.getMark();
        xTurn = false;
    }
    else {
        grid[row][col] = playerO.getMark();
        xTurn = true;
    }
    if(numberOfMoves >= minimumMovesToWin){
        checkIfWon(row,col);
        if(gameStatus == Status::winner){
            xTurn ? playerO.updateDidWin() : playerX.updateDidWin();
        }
    }
    else{
        gameStatus = Status::validInput;
    }
    return true;
}
/*
* Determines the position the current player's mark will be placed based on the players selection. If the
* position selected by the player is invalid then game status will be changed to 'outOfBoundsInput' and
* false returned indicating the player must make another selection
 */
bool ModelTicTacToe::getMove(std::string move){
    if(move.size() > 1 or move.empty()){
        gameStatus = Status::outOfBoundsInput;
        return false;
    }
    switch (move[0]) {
        case '1': {
            return updateGrid(0, 0);
        }
        case '2': {
            return updateGrid(0, 1);
        }
        case '3': {
            return updateGrid(0, 2);
        }
        case '4': {
            return updateGrid(1, 0);
        }
        case '5': {
            return updateGrid(1, 1);
        }
        case '6': {
            return updateGrid(1, 2);
        }
        case '7': {
            return updateGrid(2, 0);
        }
        case '8': {
            return updateGrid(2, 1);
        }
        case '9': {
            return updateGrid(2, 2);
        }
        default: {
            gameStatus = Status::outOfBoundsInput;
        }
    }

    return false;
}

/*
* Returns the name of the player who won, if draw then an empty string will be returned
*/
std::string ModelTicTacToe::returnResult() {
    if(gameStatus == Status::draw){
        return "";
    }
    else{
    return playerX.didWin() ? playerX.getName() : playerO.getName();
    }
}

/*
 * Resets xTurn, numberOfMoves, and grid to their original vlaues
 */
void ModelTicTacToe::resetGame() {
    xTurn = true;
    numberOfMoves = 0;
    gameStatus = Status::validInput;
    fillTable();
}