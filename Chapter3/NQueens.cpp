#include "NQueens.h"

//precondition: going to call my defaults constructor
//postcondition: going to set the board and initialize them, creating a 2D vector containing size (firt argu), then the second argu same size but now each value has '-'
NQueens::NQueens():size(0), queensBoard(size,vector<char>(size,'-')){}

//precondition: going to create the board for the queens (chessboard)
//postcondition: going to then check the row, creating a vector,then loop through the 2D vector that will have how many rows and columns we want 
void NQueens::displayChessboard(const vector<vector<char>>& chessboard, int queenNumberSize){
	cout << "\n\t" << queenNumberSize << "-Queens";
	//going to get me the chessboard size and give me the box
	cout << "\n\t" << string(chessboard.size() * 2 + 1, char(205)) << endl;
	//have to loop through the chessboard (so the queensBoard)
	for (const vector<char>& row : chessboard) {
		cout << "\t" << char(186);
		//print out the '-'
		for (char i : row) {
			cout << i << char(186);
		}
		cout << endl;
		cout << "\t" << string(chessboard.size() * 2 + 1, char(205)) << endl;
	}
}
//precondition: going to check if there is a winner, passing in a 2D vector, and the size of the queens number, then the letter char that will determine if its equal if not then winner
//postcondition: going to check if there is a winner or not, making nested for loops and if statements
bool NQueens::checkNQueensWinner(const vector<vector<char>>& chessboard, int queenNumberSize, char queenLetter){
	int queensPlaced = 0;
	//nested for-loop to check for the row and column indexs
	for (int row = 0; row < queenNumberSize; ++row) {
		for (int column = 0; column < queenNumberSize; ++column) {
			//if the index is equal to 'Q' then true
			//EX: row 1, column 1; it will be at index[0][0] and if that has 'Q' then true
			if (chessboard[row][column] == queenLetter) {
				queensPlaced++;
				//this loop will not check if this queen threatens any other queen
				for (int i = 0; i < queenNumberSize; ++i) {
					//if the index[0] does not equal the row[0] && queensBoard[0][0] has 'Q', then false
					if (i != row && chessboard[i][column] == queenLetter) {
						return false;
					}
					if (i != column && chessboard[row][i] == queenLetter) {
						return false;
					}
					//this will now check the diagonals
					if (i != 0) {
						if (row - i >= 0 && column - i >= 0 && chessboard[row - i][column - i] == queenLetter) {
							return false;
						}
						if (row - i >= 0 && column + i < queenNumberSize && chessboard[row - i][column + i] == queenLetter) {
							return false;
						}
					}
				}
			}
		}
	}
	return queensPlaced == queenNumberSize;
}
//precondition: going to create a game called N-Queens using 2D vector
//postcondition: going to thene call my displayChessBoard() function and my checkNQueensWinner() function, going to create a menu inside to ask for 2 options
void NQueens::menuChallenge(){
	system("cls");
	//int queenNumberSize = 0;
	int rowChoice, columnChoice, checkExistRow, checkExistColumn;
	int moves;
	char queenLetter = 'Q';
	char option, playAgain = 'N';
	//going to use map STL to keep track of each moves and how fast they go, and total moves, and the game counts as well
	map<int, int> fastTime, slowTime, gameCount, movesEachGameFast, movesEachGameSlow;
	clock_t startTime, endTime;

	do {
	begginning:
		system("cls");
		cout << "\n\tThe n - queens puzzle is the problem of placing n chess queens on a n" << string(1, char(186)) << "n chessboard\n"
			"\tso that no two queens threaten each other; thus, a solution requires that no two\n"
			"\tqueens share the same row, column, or diagonal.Solutions exist for all natural\n"
			"\tnumbers n with the exception of n = 2 and n = 3.\n";
		size = inputInteger("\n\tEnter the board dimension nxn: ", true);
		//turning the fastestTime to int max which is (2147483647)
		for (int i = 1; i <= size; ++i) {
			fastTime[i] = INT_MAX;
			movesEachGameFast[i] = INT_MAX;
		}
		//creating a 2D vector containing size (firt argu), then the second argu same size but now each value has '-'
		vector<vector<char>> queensBoard(size, vector<char>(size, '-'));
		
		displayChessboard(queensBoard, size);
		//checking if the move was valid or not
		bool moved = false;
		//getting the time start, start here
		startTime = clock();
		moves = 0;
		do {
			cout << "\n\tGame Options";
			cout << "\n\t" << string(45, char(205));
			cout << "\n\tA> Place a queen";
			cout << "\n\tB> Remove an existing queen";
			cout << "\n\t" << string(45, char(205));
			cout << "\n\t0> Exit";
			cout << "\n\t" << string(45, char(205));
			option = inputChar("\n\tOption: ", (static_cast<string>("AB0")));

			switch (toupper(option)) {
			case 'A': {
				rowChoice = inputInteger("\n\tPosition a queen in the row (1.." + to_string(size) + "): ", 1, size);
				columnChoice = inputInteger("\tPosition a queen int he column (1.." + to_string(size) + "): ", 1, size);
				bool conflictCheck = false;
				//if queensBoard does not have 'Q' in that index EX: row 1, column 2 = index[0][1], run this statement
				if (queensBoard[rowChoice - 1][columnChoice - 1] != queenLetter) {
					//going to look through the size of the queens number
					for (int i = 0; i < size; ++i) {
						//if EX: row = 1, column = 1; 2 queens, index row and column is at [0][0], now if again, row = 1, column = 2;
						//check if there is a 'Q', so call queensBoard[1-1][0] == 'Q' where [0][0] there is a 'Q', thats conflict
						//OR is checking queensBoard[i], that is our row (our index), then [2-1] will be [1] index == 'Q', so check row and column, conflict then flag to true
						if (queensBoard[rowChoice - 1][i] == queenLetter || queensBoard[i][columnChoice - 1] == queenLetter) {
							//flag it to be true so you can send a message that there is a conflict 
							conflictCheck = true;
						}
						//checking for all the diagonal conflicts
						//if EX: row = 2, column = 1
						//row(2) - 1 - 0 [1]  && column(1) - 1 - 0 [0]          &&  then go back to the queensBoard[2-1-i(index)][1-1-i(index) == 'Q' (they both have to be true)
						//   check for the indexs first                             now go to the board and check there
						if ((rowChoice - 1 - i >= 0 && columnChoice - 1 - i >= 0 && queensBoard[rowChoice - 1 - i][columnChoice - 1 - i] == queenLetter) ||
							(rowChoice - 1 - i >= 0 && columnChoice - 1 + i < size && queensBoard[rowChoice - 1 - i][columnChoice - 1 + i] == queenLetter) ||
							(rowChoice - 1 + i < size && columnChoice - 1 - i >= 0 && queensBoard[rowChoice - 1 + i][columnChoice - 1 - i] == queenLetter) ||
							(rowChoice - 1 + i < size && columnChoice - 1 + i < size && queensBoard[rowChoice - 1 + i][columnChoice - 1 + i] == queenLetter)) {
							//flag to true, meaning there is a conflict
							conflictCheck = true;
						}
					}
					//if there is no conflict then place the 'Q' in that index
					if (!conflictCheck) {
						queensBoard[rowChoice - 1][columnChoice - 1] = queenLetter;
						//now call the display board, display board will look for the index EX: queenBoard[0][1] then display Q
						displayChessboard(queensBoard, size);
						//flag the moved to true, meaing the move was valid
						moved = true;
					}
					else {
						cout << "\tERROR: Conflict with queens in the same row or column or diagonal. Try again." << endl;
					}
				}
				//else there is a 'Q' in there
				else {
					cout << "\tError: a queen has already placed in the position (row and column). Try again.\n";
				}
			}
					break;
			case 'B': {
				checkExistRow = inputInteger("\n\tEnter an existing queen from the row (1.." + to_string(size) + "): ", 1, size);
				checkExistColumn = inputInteger("\tEnter an existing queen from the column (1.." + to_string(size) + "): ", 1, size);
				//if queensBoard has that index EX: [0][1] and there is an Q, remove it 
				if (queensBoard[checkExistRow - 1][checkExistColumn - 1] == queenLetter) {
					queensBoard[checkExistRow - 1][checkExistColumn - 1] = '-';
					displayChessboard(queensBoard, size);
				}
				//else no existing, error 
				else {
					cout << "\tERROR: No such queen existed.\n";
				}
			}
					break;
			case '0': {
			start:
				playAgain = inputChar("\n\tPlay again? (Y-yes or N-no): ", 'y', 'n');
				if (toupper(playAgain) == 'Y') {
					//this is to clear the data that is left in the game, if play again, there will be no data no more
					queensBoard = vector<vector<char>>(size, vector<char>(size, '-'));
					goto begginning;
				}
				//if there were a winner
				if (checkNQueensWinner(queensBoard, size, queenLetter)) {
					double averageSeconds;
					cout << "\n\tGame statistics:\n\n";
					for (auto& i : gameCount) {
						//get the key and the second is the value
						int queensOverallUsed = i.first;
						int games = i.second;
						//if 1 then there are only 1 game being played
						if (games == 1) {
							//getting the average seconds, have to add fast time + slow time then divide by games played
							averageSeconds = static_cast<double>(fastTime[queensOverallUsed] + slowTime[queensOverallUsed]) / 2.0;
							cout << "\t" << games << " game using " << queensOverallUsed << " queen was played.\n";
						}
						else {
							//getting the average seconds, have to add fast time + slow time then divide by games played
							averageSeconds = static_cast<double>(fastTime[queensOverallUsed] + slowTime[queensOverallUsed]) / games;
							cout << "\t" << games << " games using " << queensOverallUsed << " queen was played.\n";
						}
						cout << "\t\tThe fastest time was " << fastTime[queensOverallUsed] << " seconds in " << movesEachGameFast[queensOverallUsed] << " moves.\n";
						cout << "\t\tThe slowest time was " << slowTime[queensOverallUsed] << " seconds in " << movesEachGameSlow[queensOverallUsed] << " moves.\n";
						cout << "\t\tThe average time was " << averageSeconds << " second(s)\n";
					}
				}
				else {
					cout << "\n\tNo game statistic collected.\n";
				}
				return;
			}
			}
			//if the moved was valid then increment, keep track how many moves we do
			if (moved != false) {
				moves++;
			}
			//flag it back to false, to then check again if the move was valid
			moved = false;
			//if there is a winner, then true, passing in the queensBoard and size
			if (checkNQueensWinner(queensBoard, size, queenLetter)) {
				cout << "\n\tCongratulation! You have solved " << size << "-Queens in " << moves << " moves.\n";
				displayChessboard(queensBoard, size);
				//getting the end start, use clock() function after pegC has all the discs
				endTime = clock();
				//calculating the time, subtract the end time to the start time
				int gameTimeInSeconds = (endTime - startTime) / CLOCKS_PER_SEC;
				//set the size(key) = to the min of the value (size-> fastTime)
				fastTime[size] = min(fastTime[size], gameTimeInSeconds);
				//getting the max, meaning the time that is the longest
				slowTime[size] = max(slowTime[size], gameTimeInSeconds);
				//increment how many games have been played with the queens numbers (size)
				gameCount[size]++;

				//set the key(size) to the value which is the moves now, we getting each move for each game we play
				movesEachGameFast[size] = min(movesEachGameFast[size], moves);
				movesEachGameSlow[size] = max(movesEachGameSlow[size], moves);
				goto start;
			}

		} while (toupper(playAgain) != '0');

	} while (toupper(playAgain) == 'Y');
}


