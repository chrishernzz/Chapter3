#include "TowersOfHanoi.h"

//precondition: function is going to have 3 vector as parameters (argu)
//postcondition: function is going to update the pegs in order of how they are moving
void TowersOfHanoi::printPegs(const vector<int>& pegA, const vector<int>& pegB, const vector<int>& pegC){
	//get the greatest size between pegA, pegB, and pegC to check how many discs can it print out
	int maxRings = max(pegA.size(), max(pegB.size(), pegC.size()));
	cout << "\n\n\tTower of Hanoi\n\n";
	//reverse the numbers, starting from greatest in the bottom, smaller on the top (displaying wise)
	for (int i = maxRings; i >= 0; i--) {
		//print peg A
		cout << "\t";
		//check if the maxRings is less than the size in pegA
		if (i < pegA.size()) {
			int ringSize = pegA[i];
			//converting it to a string
			string ringString = to_string(ringSize);
			for (int j = 0; j < ringString.size(); j++) {
				cout << ringString[j] << "";
			}
		}
		else {
			cout << string(1, char(186)) << "";
		}
		//print peg B
		cout << "\t";
		//check if the maxRings is less than the size in pegB
		if (i < pegB.size()) {
			int ringSize = pegB[i];
			//converting it to a string
			string ringString = to_string(ringSize);
			for (int j = 0; j < ringString.size(); j++) {
				cout << ringString[j] << "";
			}
		}
		else {
			cout << string(1, char(186)) << "";
		}
		//print peg C
		cout << "\t";
		//check if the maxRings is less than the size in pegC
		if (i < pegC.size()) {
			int ringSize = pegC[i];
			//converting it to a string
			string ringString = to_string(ringSize);
			for (int j = 0; j < ringString.size(); j++) {
				cout << ringString[j] << "";
			}
		}
		else {
			cout << "" << string(1, char(186)) << "";
		}
		cout << endl;
	}
	cout << "\t" << string(1, char(186)) << "\t" << string(1, char(186)) << "\t" << string(1, char(186)) << "\n";
	cout << "     " << string(7, char(205)) << " " << string(7, char(205)) << " " << string(7, char(205));
	cout << "\n\tA\tB\tC\n\n";
}
//precondition: going to create a game that is called Tower of Hanoi using vector stl
//postcondition: going to have 3 pegs in vector, then going to use push_back() and pop_back(),call the printPegs() function to show the table
void TowersOfHanoi::menuChallenge(){
	system("cls");
	char playAgain;
	int ringsNumber;
	int moves, discsTotalNumber = 64;
	//using vector STL for my all 3 pegs of the disc
	//vector<int> pegA, pegB, pegC;
	char choicePeg1, choicePeg2;
	//going to use map STL to keep track of each moves and how fast they go, and total moves, and the game counts as well
	map<int, int> fastTime, slowTime, gameCount, movesEachGameFast, movesEachGameSlow;
	clock_t startTime, endTime;
	//turning the fastestTime to int max which is (2147483647)
	for (int i = 1; i <= discsTotalNumber; ++i) {
		fastTime[i] = INT_MAX;
		movesEachGameFast[i] = INT_MAX;
	}
	do {
		system("cls");
		cout << "\n\tThe Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game.\n"
			"\tIt consists of three pegs and a number of rings of different sizes, which can slide onto\n"
			"\tany peg.The game starts with the rings in a neat stack in ascending order of size on one\n"
			"\tpeg, the smallest at the top, thus making a conical shape.\n"
			"\n\tThe objective of the game is to move the entire stack from the starting peg - A to ending peg - B,\n"
			"\tobeying the following simple rules:\n"
			"\n\t\t1. Only one disk can be moved at a time.\n"
			"\t\t2. Each move consists of taking the upper disk from one of the stacks and\n"
			"\t\t   placing it on top of another stack or on an empty peg.\n"
			"\t\t3. No larger disk may be placed on top of a smaller disk.\n";
		//clear the elements so it does not keep adding them 
		pegA.clear();
		pegB.clear();
		pegC.clear();
		moves = 0;

		ringsNumber = inputInteger("\n\tEnter the number of rings (1..64) to begin: ", 1, 64);
		//getting the time start, start here
		startTime = clock();
		//get the pegs to go in A but will print the greatest number in the bottom and smallest in the top, start with ring number then decrement
		for (int i = ringsNumber; i >= 1; i--) {
			//push the elements to pegA, from descending: Ex ringsNumber=4; 4 3 2 1
			pegA.push_back(i);
		}
		printPegs(pegA, pegB, pegC);
		//checking if the move was valid or not
		bool moved = false;
		do {
			choicePeg1 = inputChar("\n\tSelect the top disk from the start peg (A, B, C, or Q-quit): ", (static_cast<string>("ABCQ")));
			choicePeg2 = inputChar("\tSelect the end peg (A, B, C, or Q-quit) to move the selected disk: ", (static_cast<string>("ABCQ")));
			switch (toupper(choicePeg1)) {
			case 'A': {
				//check if pegA is empty
				if (pegA.empty()) {
					cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-A.\n";
					cout << "\t\tPlease choose again.";
					printPegs(pegA, pegB, pegC);
					break;
				}
				if (toupper(choicePeg2) == 'B') {
					//if pegB has no disc OR pegA is less than pegB run this
					if (pegB.empty() || pegA.back() < pegB.back()) {
						//get pegA from the back(last element) and push it to pegB
						pegB.push_back(pegA.back());
						//now pop it from pegA since we dont want it there no more (in pegA)
						pegA.pop_back();
						cout << "\n\tTop disk from peg-A has moved to peg-B.";
						//print the Tower of Hanoi
						printPegs(pegA, pegB, pegC);
						//flag it to true to show that the move was valid (do it for the other cases)
						moved = true;
					}
					else {
						cout << "\n\tERROR: Cannot make the move. Top disk(" << pegA.back() << ") of peg-A, is larger than top disk(" << pegB.back() << ") of peg-B.\n";
						cout << "\t\tPlease choose again.\n";
						printPegs(pegA, pegB, pegC);
					}
				}
				else if (toupper(choicePeg2) == 'C') {
					if (pegC.empty() || pegA.back() < pegC.back()) {
						//get pegA from the back(last element) now push to pegC
						pegC.push_back(pegA.back());
						pegA.pop_back();
						cout << "\n\tTop disk from peg-A has moved to peg-C.";
						//print the Tower of Hanoi
						printPegs(pegA, pegB, pegC);
						moved = true;
					}
					else {
						cout << "\n\tERROR: Cannot make the move. Top disk(" << pegA.back() << ") of peg-A, is larger than top disk(" << pegC.back() << ") of peg-C.\n";
						cout << "\t\tPlease choose again.\n";
						printPegs(pegA, pegB, pegC);
					}
				}
				else if (toupper(choicePeg2) == 'Q') {
					return;
				}
			}
					break;
			case 'B': {
				//check if pegB is empty
				if (pegB.empty()) {
					cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-B.\n";
					cout << "\t\tPlease choose again.";
					printPegs(pegA, pegB, pegC);
					break;
				}
				if (toupper(choicePeg2) == 'A') {
					//if pegA has no disc OR pegB is less than pegA run this
					if (pegA.empty() || pegB.back() < pegA.back()) {
						//get pegB from the back(last element) now push to pegA
						pegA.push_back(pegB.back());
						//now pop it from pegB since we dont want it there no more (in pegB)
						pegB.pop_back();
						cout << "\n\tTop disk from peg-B has moved to peg-A.";
						printPegs(pegA, pegB, pegC);
						moved = true;
					}
					else {
						cout << "\n\tERROR: Cannot make the move. Top disk(" << pegB.back() << ") of peg-B, is larger than top disk(" << pegA.back() << ") of peg-A.\n";
						cout << "\t\tPlease choose again.\n";
						printPegs(pegA, pegB, pegC);
					}
				}
				else if (toupper(choicePeg2) == 'C') {
					if (pegC.empty() || pegB.back() < pegC.back()) {
						//get pegB from the back(last element) now push to pegC
						pegC.push_back(pegB.back());
						pegB.pop_back();
						cout << "\n\tTop disk from peg-B has moved to peg-C.";
						printPegs(pegA, pegB, pegC);
						moved = true;
					}
					else {
						cout << "\n\tERROR: Cannot make the move. Top disk(" << pegB.back() << ") of peg-B, is larger than top disk(" << pegC.back() << ") of peg-C.\n";
						cout << "\t\tPlease choose again.\n";
						printPegs(pegA, pegB, pegC);
					}
				}
				else if (toupper(choicePeg2) == 'Q') {
					return;
				}
			}
					break;
			case 'C': {
				//check if pegC is empty
				if (pegC.empty()) {
					cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-C.\n";
					cout << "\t\tPlease choose again.";
					printPegs(pegA, pegB, pegC);
					break;
				}
				if (toupper(choicePeg2) == 'A') {
					if (pegA.empty() || pegC.back() < pegA.back()) {
						//get pegC from the back(last element) now push to pegA
						pegA.push_back(pegC.back());
						//now pop it from pegC since we dont want it there no more (in pegC)
						pegC.pop_back();
						cout << "\n\tTop disk from peg-C has moved to peg-A.";
						printPegs(pegA, pegB, pegC);
						moved = true;
					}
					else {
						cout << "\n\tERROR: Cannot make the move. Top disk(" << pegC.back() << ") of peg-C, is larger than top disk(" << pegA.back() << ") of peg-A.\n";
						cout << "\t\tPlease choose again.\n";
						printPegs(pegA, pegB, pegC);
					}
				}
				else if (toupper(choicePeg2) == 'B') {
					if (pegB.empty() || pegC.back() < pegB.back()) {
						//get pegC from the back(last element) now push to pegB
						pegB.push_back(pegC.back());
						pegC.pop_back();
						cout << "\n\tTop disk from peg-C has moved to peg-B.";
						printPegs(pegA, pegB, pegC);
						moved = true;
					}
					else {
						cout << "\n\tERROR: Cannot make the move. Top disk(" << pegC.back() << ") of peg-C, is larger than top disk(" << pegB.back() << ") of peg-B.\n";
						cout << "\t\tPlease choose again.\n";
						printPegs(pegA, pegB, pegC);
					}
				}
				else if (toupper(choicePeg2) == 'Q') {
					return;
				}
			}
					break;
			case 'Q': {
				if (toupper(choicePeg1) == 'Q' || toupper(choicePeg2) == 'Q') {
					return;
				}
			}
			}
			//if the moved was valid then increment, keep track how many moves we do
			if (moved != false) {
				moves++;
			}
			//flag it back to false, to then check again if the move was valid
			moved = false;
		} while (pegC.size() < ringsNumber);
		//getting the end start, use clock() function after pegC has all the discs
		endTime = clock();
		//calculating the time, subtract the end time to the start time
		int gameTimeInSeconds = (endTime - startTime) / CLOCKS_PER_SEC;
		//set the ringsNumber(key) = to the min of the value (ringsNumber-> fastTime)
		fastTime[ringsNumber] = min(fastTime[ringsNumber], gameTimeInSeconds);
		//getting the max, meaning the time that is the longest
		slowTime[ringsNumber] = max(slowTime[ringsNumber], gameTimeInSeconds);
		//increment how many games have been played with the discs numbers (ringnumbers)
		gameCount[ringsNumber]++;

		//set the key(ringNumbers) to the value which is the moves now, we getting each move for each game we play
		movesEachGameFast[ringsNumber] = min(movesEachGameFast[ringsNumber], moves);
		movesEachGameSlow[ringsNumber] = max(movesEachGameSlow[ringsNumber], moves);

		cout << "\n\tCongratulation! You have solved the game in " << moves << " moves.\n";
		playAgain = inputChar("\n\tPlay again? (Y-yes or N-no): ", 'y', 'n');
	} while (toupper(playAgain) == 'Y');
	double averageSeconds;
	cout << "\n\tGame statistics:\n\n";
	for (auto& i : gameCount) {
		//get the key and the second is the value
		int discsOverallUsed = i.first;
		int games = i.second;
		//if 1 then there are only 1 game being played
		if (games == 1) {
			//getting the average seconds, have to add fast time + slow time then divide by games played
			averageSeconds = static_cast<double>(fastTime[discsOverallUsed] + slowTime[discsOverallUsed]) / 2.0;
			cout << "\t" << games << " game using " << discsOverallUsed << " disks was played.\n";
		}
		else {
			//getting the average seconds, have to add fast time + slow time then divide by games played
			averageSeconds = static_cast<double>(fastTime[discsOverallUsed] + slowTime[discsOverallUsed]) / games;
			cout << "\t" << games << " games using " << discsOverallUsed << " disks was played.\n";
		}
		cout << "\t\tThe fastest time was " << fastTime[discsOverallUsed] << " seconds in " << movesEachGameFast[discsOverallUsed] << " moves.\n";
		cout << "\t\tThe slowest time was " << slowTime[discsOverallUsed] << " seconds in " << movesEachGameSlow[discsOverallUsed] << " moves.\n";
		cout << "\t\tThe average time was " << averageSeconds << " second(s)\n";
	}
}
