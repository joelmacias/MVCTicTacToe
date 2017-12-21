/*
 * Implementation file for class ViewTicTacToe
 */
#include "ViewTicTacToe.h"
#include <iostream>
#include <algorithm>
#include <functional>

/*
 * Starts a game of tic tac toe. Will start new games until users decide to stop playing
 */
ViewTicTacToe::ViewTicTacToe() {
    while(playGame());
}
/*
 * Prompts users for input, accepts input, sends input to controller to determine next action to be taken
 */
bool ViewTicTacToe::playGame() {
    std::string playerOneName, playerTwoName;
    std::cout<< "Enter the name for player 1. Their mark will be 'X': ";
    getline(std::cin,playerOneName);
    std::cout<< "Enter the name for player 2. Their mark will be 'O': ";
    getline(std::cin,playerTwoName);
    controller.startGame(playerOneName, playerTwoName);

    /*
     * Prompt and accept input while the came is not over
     */
    while(!controller.gameOver()){
        std::string playerTurn = controller.getTurn();
        std::string move;
        /*
         * Prompt and accept the player's chosen move until the move is valid
         */
        do {
            if(controller.outOfBounds()){
                std::cout<<"Selected move out of bounds. Select a move within the bounds.\n";
            }
            if(controller.spaceTaken()){
                std::cout<<"Selected move already taken. Select a move that is not taken.\n";
            }
            printBoard();
            std::cout << playerTurn << "'s turn, enter your move: ";
            std::cin >> move;
        }while(!controller.isMoveValid(move));
    }

    std::string winner = controller.gameResult();

    if(winner.empty()){
        std::cout<<"\nGame has ended in a Draw\n";
    }
    else{
        std::cout<<"\n"<<winner<< " has won!\n";
    }
    printBoard();

    std::string playAgain;
    std::cout<<"Would you like to play again? Enter 'yes' to play again, 'no' to exit.\n";
    do{
        std::cin>>playAgain;
        transform( playAgain.begin(), playAgain.end(), playAgain.begin(), std::ptr_fun <int, int> (tolower));
        if(playAgain == "no"){
            return false;
        }
        else if(playAgain == "yes"){
            std::cout<<"Starting new game.\n";
            std::cin.get();
            controller.resetGame();
            return true;
        }
        else {
            std::cout << "Invalid input. To play again enter 'yes', to exit enter 'no'.\n";
        }
    }while(true);
}

/*
 * Print the current tic tac toe game
 */
void ViewTicTacToe::printBoard() {
    const std::vector<std::vector<char>>* grid = controller.returnGrid();

    std::cout<<"\n";
    for(auto itToVectors = grid->begin(); itToVectors != grid->end(); ++itToVectors){
        for(auto itVector = itToVectors->begin(); itVector != itToVectors->end(); itVector++){
            std::cout<< *itVector;
            if(itVector+1 != itToVectors->end()){
                std::cout<<"|";
            }
        }
        if(itToVectors+1 != grid->end()) {
            std::cout << "\n-----\n";
        }
    }
    std::cout<<"\n\n";
}
