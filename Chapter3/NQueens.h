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
char inputChar(string prompt, string lookup);
char inputChar(string prompt, char yes, char no);
int inputInteger(string prompt, int startRange, int endRange);
int inputInteger(string prompt, bool posNeg);

//precondition: going to create 2D vector for the board
//postcondition: going to then have defualt constructor, print the board, and check winner
class NQueens{
private:
	int size;
	//this will create a 2D vector array of the board
	vector<vector<char>> queensBoard;
public:
	//defualt constructor
	NQueens();

	//member function that displays the board of the chess (nqueens board)
	void displayChessboard(const vector<vector<char>>& chessboard, int queenNumberSize);

	//member function that checks for the winner
	bool checkNQueensWinner(const vector<vector<char>>& chessboard, int queenNumberSize, char queenLetter);

	//member function to get the challenge menu
	void menuChallenge();
};

