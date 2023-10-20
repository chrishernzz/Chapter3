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


//precondition: going to create an vector for the pegs (a,b,and c)
//postcondition: going to print the board, then the menu
class TowersOfHanoi{
private:
	//using vector STL for my all 3 pegs of the disc
	vector<int> pegA, pegB, pegC;
public:
	//member function to print the Pegs
	void printPegs(const vector<int>& pegA, const vector<int>& pegB, const vector<int>& pegC);

	//member function to get the challenge menu
	void menuChallenge();

};

