#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<chrono>
#include<random>
using namespace std;

//input (1) header files inputs validation
char inputChar(string prompt, char yes, char no);
int inputInteger(string prompt, int startRange, int endRange);


//precondition: going to create 2D vector for the board
//postcondition: going to then have defualt constructor, print the board, check winner, and check draw
class TicTacToe{
private:
	//this will create a 2D vector array of the board
	vector<vector<char>> board;
public:
	//defualt constructor
	TicTacToe();

	//member function to print the tic tac toe moves
	void printTicTacToeMoves(const vector<vector<char>>& board);

	//member function to check the winner
	bool checkWinnerBoard(const vector<vector<char>>& board, char player);

	//member function to check fo the draw
	bool checkForDraw(const vector<vector<char>>& board);

	//member function to get the challenge menu
	void menuChallenge();
};

