cmake_minimum_required(VERSION 3.9)
project(TicTacToeMVC)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTacToeMVC main.cpp ModelTicTacToe.cpp ModelTicTacToe.h ControllerTicTacToe.cpp ControllerTicTacToe.h ViewTicTacToe.cpp ViewTicTacToe.h)