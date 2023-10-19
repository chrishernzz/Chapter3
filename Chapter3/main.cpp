//name: Christian Hernandez
//date: 9/20/2023
//subscription: CMPR131

#include<iostream>
#include"input (1).h"
#include"TicTacToe.h"
#include"TowersOfHanoi.h"
#include"NQueens.h"
using namespace std;

//PROTOTYPES 
int menuOption();
void challenge1();
void challenge2();
void challenge3();

int main()
{
	do {
		switch (menuOption()) {
		case 0: exit(1); break;
		case 1: challenge1(); break;
		case 2: challenge2(); break;
		case 3: challenge3(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);

	return EXIT_SUCCESS;
}

//precondition: making a menu option
//postcondition: it will return an int (the choice of the menu)
int menuOption()
{
	system("cls");
	cout << "\n\tCMPR131 Chapter 3 - Games Applications using Container by Christian Hernandez(9/20/2023)";
	cout << "\n\t" << string(90, char(205));
	cout << "\n\t\t1> Tic-Tac-Toe";
	cout << "\n\t\t2> Tower of Hanoi";
	cout << "\n\t\t3> n-Queens";
	cout << "\n\t" << string(90, char(205));
	cout << "\n\t\t0> Exit";
	cout << "\n\t" << string(90, char(205));
	//calling the input.h and we are inputting numbers from 0 through 3
	return inputInteger("\n\t\tOption: ", 0, 3);
}

//precondition: going to call the TicTacToe Class
//postcondition: going to then call the menu that has all the information
void challenge1(){
	TicTacToe menu;
	menu.menuChallenge();
}
//precondition: going to call the TowerOfHanoi Class
//postcondition: going to then call the menu that has all the information
void challenge2(){
	TowersOfHanoi menu;
	menu.menuChallenge();
}
//precondition: going to call the NQueens Class
//postcondition: going to then call the menu that has all the information
void challenge3(){
	//the constructor needs to be 0 since we have a int queensNumberSize as the argu (parameter)
	NQueens menu;
	menu.menuChallenge();
}