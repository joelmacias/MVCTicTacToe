#Tic-Tac-Toe
Command line Tic-Tac-Toe(TTT) game. Implemented in an MVC pattern with C++ 

#Requirments
* C++11 or higher

#Classes
* ModelTicTacToe(MTT)
* Player
* ControllerTicTacToe(CTT)
* ViewTicTacToe(VTT)

* ModelTicTacToe, and Player
	* Logic, and data required to play a game of TTT. Represent game board, players, validate input, determine winner, etc. 

* ControllerTicTacToe
   * Communicates user input from VTT object to MTT object. Responds to VTT object with MTT's response

* ViewTicTacToe
	* Responsible for prompting, and accepting user input. Hands user input to CTT, accepts CTT response, and prompts user with appropriate message. Displays game board, and winner. 
