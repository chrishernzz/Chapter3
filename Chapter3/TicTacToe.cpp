#include "TicTacToe.h"

//precondition: going to call my defaults constructor
//postcondition: going to set the board  and initialize them
TicTacToe::TicTacToe(): board(9, vector<char>(9, ' ')) {}

//precondition: going to pass in a 2D vector board
//postcondition: going to then create a board that takes in the rows and column
void TicTacToe::printTicTacToeMoves(const vector<vector<char>>& board){
	cout << "\n\t\t   Tic-Tac-Toe\n\t\t";
	cout << string(1, char(199)) << string(4, char(205)) << string(1, char(186)) << string(4, char(205)) << string(1, char(186)) << string(4, char(205)) << string(1, char(186)) << "\n";
	cout << "\t\t" << string(1, char(186)) << " " << board[1][1] << "  " << string(1, char(186)) << "  " << board[1][2] << " " << string(1, char(186)) << "  " << board[1][3] << " " << string(1, char(186)) << "\n";
	cout << "\t\t" << string(1, char(199)) << string(4, char(205)) << string(1, char(186)) << string(4, char(205)) << string(1, char(186)) << string(4, char(205)) << string(1, char(186)) << "\n";
	cout << "\t\t" << string(1, char(186)) << " " << board[2][1] << "  " << string(1, char(186)) << "  " << board[2][2] << " " << string(1, char(186)) << "  " << board[2][3] << " " << string(1, char(186)) << "\n";
	cout << "\t\t" << string(1, char(199)) << string(4, char(205)) << string(1, char(186)) << string(4, char(205)) << string(1, char(186)) << string(4, char(205)) << string(1, char(186)) << "\n";
	cout << "\t\t" << string(1, char(186)) << " " << board[3][1] << "  " << string(1, char(186)) << "  " << board[3][2] << " " << string(1, char(186)) << "  " << board[3][3] << " " << string(1, char(186)) << "\n";
	cout << "\t\t" << string(1, char(199)) << string(4, char(205)) << string(1, char(186)) << string(4, char(205)) << string(1, char(186)) << string(4, char(205)) << string(1, char(186)) << "\n";
}

//precondition: going to pass in a 2D vector board and the player which is the (userInput and computerChoice)
//postcondition: going to then check each box going from row to row, column to column, and diagonal, return true or false 
bool TicTacToe::checkWinnerBoard(const vector<vector<char>>& board, char player){
	int boardsize = 3;
	//check rows, columns, and diagonals for a win
	for (int i = 1; i <= boardsize; ++i) {
		//if statement checking if the first,second, and thirid row is complete , if yes run this
		if (board[i][1] == player && board[i][2] == player && board[i][3] == player) {
			return true;
		}
		//if statement checking if the whole first,second, and third column is complete, if yes run this
		else if (board[1][i] == player && board[2][i] == player && board[3][i] == player) {
			return true;
		}
	}
	//if statement checking if the diagonal is whole complete (top left, middle, bottom right)
	if (board[1][1] == player && board[2][2] == player && board[3][3] == player) {
		return true;
	}
	//this if statement is the opposite, going from top right to middle to bottom left
	if (board[1][3] == player && board[2][2] == player && board[3][1] == player) {
		return true;
	}
	return false;
}

//precondition: going to pass in a 2D vector that just checks if the board is full or not
//postcondition: going to then return true if full, false if its not, looping through each index for i and j
bool TicTacToe::checkForDraw(const vector<vector<char>>& board){
	int boardsize = 3;
	//check for the draw from 1..3, nested for loop to get the indexs where i is [1] and j is [1],EX: [1][1], etc.
	for (int i = 1; i <= boardsize; ++i) {
		for (int j = 1; j <= boardsize; ++j) {
			//this will now check the board[1][1] and if ther is no 'X' or 'O' then it will be false, no draw yet
			if (board[i][j] != 'X' && board[i][j] != 'O') {
				// If there is an empty spot, the game is not a draw
				return false;
			}
		}
	}
	//return true it's a draw
	return true;
}

//precondition: going to call my board function and my check winner board, they both passed in 2D vector in char way
//postcondition: going to then play against the computer who is the AI, going to get the fastest, slowest, and average times
void TicTacToe::menuChallenge(){
	system("cls");
	//create a 2D vector containing 9 as the size, each having vector<char> 9 (9 boxes) value that contain ' ' (empty space)
	//vector<vector<char>>board(9, vector<char>(9, ' '));
	char computerChoice = 'O', inputXPlayer = 'X', currentPlayer;
	char playAgain;
	int rowChoice, columnChoice;
	int moves, totalRowsColumns = 3;
	bool winner = false, draw = false;
	//going to use map STL to keep track of fast and slow time, game count (how many are played), key is char and our value is int (EX: 'X' -> [1][1])
	map<char, int> fastTime, slowTime, gameCount, movesEachGameFast, movesEachGameSlow;
	clock_t startTime, endTime;
	//turning the fastestTime and movesEachGameFast to start at 0 (equal to 0)
	for (int i = 1; i <= totalRowsColumns; ++i) {
		fastTime[i] = 0;
		movesEachGameFast[i] = 0;
	}
	do {
		system("cls");
		cout << "\n\tTic - tac - toe(also known as Noughts and crosses or Xs and Os) is a game for two\n"
			"\tplayers, X and O, who take turns marking the spaces in a 3" << string(1, char(186)) << "3 grid.The player who\n"
			"\tsucceeds in placing three of their marks in a horizontal, vertical, or diagonal\n"
			"\trow wins the game.\n"
			"\tThis tic - tac - toe program plays against the computer.Human player, X, will always\n"
			"\tfirst.Time will be recorded for the fastest and the slowest game.Average time will\n"
			"\tthen be calculated and displayed.\n";

		cout << "\n\tGame Begins\n";
		printTicTacToeMoves(board);
		currentPlayer = 'X';
		//checking if the move was valid or not
		bool moved = false;
		moves = 0;
		//getting the time start, start here
		startTime = clock();
		do {
			if (currentPlayer == 'X') {
				cout << "\n\tHUMAN moves...\n";
				rowChoice = inputInteger("\n\t\tEnter the board's row # (1...3) or 0 to forfeit: ", 0, 3);
				//if user wishes to forfeit and chooses 0, then the game is done
				if (rowChoice == 0) {
					cout << "\n\tYou forfeited the game. Therefore, Dumb AI has won.\n";
					winner = true;
					break;
				}
				columnChoice = inputInteger("\t\tEnter the board's column # (1..3) or 0 to forfeit: ", 0, 3);
				//if they want to quit the game (forfeit)
				if (columnChoice == 0) {
					cout << "\n\tYou forfeited the game. Therefore, Dumb AI has won.\n";
					winner = true;
					break;
				}
				//checking if the row is greater than or equal to 1 && less than or equal to 3 (same for column), then check if board has empty spot if not then error saying illegal move
				if (rowChoice >= 1 && rowChoice <= 3 && columnChoice >= 1 && columnChoice <= 3 && board[rowChoice][columnChoice] == ' ') {
					//set the row and column equals to the char X, board now has the row and column. EX: user = 1,3, board[1][3], row and column
					//board starts at indexs[1][1] etc
					board[rowChoice][columnChoice] = inputXPlayer;
					//now go the board, it will look for board[1][3] our example
					printTicTacToeMoves(board);
					//flag the move to true, then increment the moves
					moved = true;
				}
				else {
					cout << "\n\tERROR: Illegal move. The square has already owned. Please re-specify.\n";
					//continue so it can stay with player X (user input) and it does not go to computerChoice
					continue;
				}
			}
			else if (currentPlayer == 'O') {
				cout << "\n\tDumb AI moves...\n";
				srand(time(0));
				do {
					//rand number between 1..3
					rowChoice = (rand() % 3) + 1;
					columnChoice = (rand() % 3) + 1;
					//loop while row and column does not have an empty space, if empty space stop then print to board
				} while (board[rowChoice][columnChoice] != ' ');
				//set the row and column equals to the char 'O'
				board[rowChoice][columnChoice] = computerChoice;
				printTicTacToeMoves(board);
			}
			//call my checkWinnerBoard() function to check for a win
			if (checkWinnerBoard(board, currentPlayer)) {
				//check if currentPlayer is at 'X' if yes, human wins
				if (currentPlayer == 'X') {
					cout << "\n\tHuman wins!\n";
				}
				else {
					cout << "\n\tDumb AI has won.\n";
				}
				//flag it to true so it can stop the do loop
				winner = true;
			}
			//eles if there is no winner, calling my checkForDraw() function then check if boxes are full, if yes then draw, if not keep doing its thing
			else if (checkForDraw(board)) {
				cout << "\n\tIt's a draw!\n";
				//if draw then flag it to true , then there is no statistic collected
				draw = true;
				//flag it to be true, no winner but we have to flag it so the loop can stop
				winner = true;
			}

			//if it still at 'X', change it to 'O', now it will be 'O' turns
			if (currentPlayer == 'X') {
				currentPlayer = 'O';
			}
			else {
				currentPlayer = 'X';
			}

			//if the moved was valid (its true now) then increment, keep track how many moves we do
			if (moved != false) {
				moves++;
			}
			//flag it back to false, to then check again if the move was valid
			moved = false;

		} while (!winner);
		//getting the end start, use clock() function after pegC has all the discs
		endTime = clock();
		//if its not a draw, calculate the statistics
		if (draw != true) {
			//calculating the time, subtract the end time to the start time
			int gameTimeInSeconds = (endTime - startTime) / CLOCKS_PER_SEC;
			//increment the times 'X' and 'O' play the game (holding each game)
			gameCount[currentPlayer]++;
			//if the currnetPlayer is 0 (forfeit) then get the fastTime and slowTime for that
			if (fastTime[currentPlayer] == 0) {
				fastTime[currentPlayer] = gameTimeInSeconds;
				slowTime[currentPlayer] = gameTimeInSeconds;
			}
			else {
				//set the currentPlayer(key) = to the min (value) and get the min from 'X' or 'O'
				fastTime[currentPlayer] = min(fastTime[currentPlayer], gameTimeInSeconds);
				slowTime[currentPlayer] = max(slowTime[currentPlayer], gameTimeInSeconds);
			}
			//if the currentPlayer is 0 for forfeit, then get the moves for the forfeit
			if (movesEachGameFast[currentPlayer] == 0) {
				movesEachGameFast[currentPlayer] = moves;
				movesEachGameSlow[currentPlayer] = moves;
			}
			else {
				//set the key(currentPlayer) to the value which is the moves now, we getting each move for each game we play
				movesEachGameFast[currentPlayer] = min(movesEachGameFast[currentPlayer], moves);
				movesEachGameSlow[currentPlayer] = max(movesEachGameSlow[currentPlayer], moves);
			}
		}
		playAgain = inputChar("\n\tPlay again? (Y-yes or N-no): ", 'y', 'n');
		//flag it back to false for both win or draw if not then it will stay at true and then the while loop will thinks its true
		winner = false;
		if (toupper(playAgain) == 'Y') {
			//flag it back to false so you can keep your data, and when you say no to playing again, the draw will be ignore
			draw = false;
		}
		//this is to clear the data that is left in the game, if play again, there will be no data no more
		board = vector<vector<char>>(9, vector<char>(9, ' '));
	} while (toupper(playAgain) == 'Y');

	//getting both statistics for 'X' and 'O'
	int totalGamesX = gameCount['X'];
	int totalGamesO = gameCount['O'];
	int totalGames = totalGamesX + totalGamesO;
	//going to get the fast time and slow time then divide by the games
	int totalFastTimeX = fastTime['X'] + slowTime['O'];
	double averageSeconds;
	//if its draw, then there are no data
	if (draw == true) {
		cout << "\n\tNo game statistics collected.\n";
	}
	else {
		cout << "\n\tGame statistics:\n\n";
		if (totalGames > 0) {
			//if game equal 1 then there are only 1 game, means you will divide by 2.0 now
			if (totalGames == 1) {
				//getting the average, call the totalFatTimeX and add it twice then divide by 2 since it was only a game
				averageSeconds = static_cast<double>(totalFastTimeX + totalFastTimeX) / 2.0;
				cout << "\t" << totalGames << " game of Tic-Tac-Toe were played.\n";
				//setting it to max since there are 1 game only, they are both going to be max with same moves as well
				cout << "\t\tThe fastest time was " << max(slowTime['X'], slowTime['O']) << " seconds in " << max(movesEachGameFast['X'], movesEachGameFast['O']) << " moves.\n";
				cout << "\t\tThe slowest time was " << max(slowTime['X'], slowTime['O']) << " seconds in " << max(movesEachGameSlow['X'], movesEachGameSlow['O']) << " moves.\n";
			}
			else {
				cout << "\t" << totalGames << " games of Tic-Tac-Toe were played.\n";
				cout << "\t\tThe fastest time was " << min(fastTime['X'], fastTime['O']) << " seconds in " << min(movesEachGameFast['X'], movesEachGameFast['O']) << " moves.\n";
				cout << "\t\tThe slowest time was " << max(slowTime['X'], slowTime['O']) << " seconds in " << max(movesEachGameSlow['X'], movesEachGameSlow['O']) << " moves.\n";
				//getting the average, add the min plus the max, then divide by how many games were played
				averageSeconds = static_cast<double>(min(fastTime['X'], fastTime['O']) + max(slowTime['X'], slowTime['O'])) / static_cast<double>(totalGames);
			}
			cout << "\t\tThe average time was " << averageSeconds << " second(s).\n";
		}
	}
}


