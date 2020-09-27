#include <iostream>
#include <conio.h>

void printInput();
void printBoard();
int addMark();
int check();

char board[3][3] = { ' ',' ', ' ',
					 ' ',' ', ' ',
					 ' ',' ', ' ' };

int turn = 1;
char mark = 'O';
int input;


int main() {

	int won = 0;
	int validInput = 0;
	for (int i = 0; i < 9; i++) {
		system("cls");
		printBoard();
		if (turn) {
			std::cout << "Player 1's turn (symbol O)\n";
		}
		else {
			std::cout << "Player 2's turn(symbol X)\n";
		}
		printInput();
		std::cout << "Please select a tile: ";
		std::cin >> input;

		while (input < 0 || input>9) {
			std::cout << "Thats not a valid number, please selct a valid number (number form 1-9):  ";
			std::cin >> input;
		}

		if (turn) {
			mark = 'O';
		}
		else {
			mark = 'X';
		}

		validInput = addMark();
		if (!validInput) {
			i--;
			continue;
		}

		won = check();
		if (won) {
			system("cls");
			printBoard();
			if (turn)
				std::cout << "\n  Player 1 has won the Game! ";
			else std::cout << "\n  Player 2 has won the Game! ";
			//getch();
			break;
		}

		if (i == 8) {
			system("cls");
			printBoard();
			std::cout << "\n  It's a DRAW :-( ";
		}

		turn = !turn;



	} 
	

	return 0;
}

void printInput() {
	std::cout << "\n\n TIC TAC TOE! :-)\n\n";
	std::cout << " 1 | 2 | 3 \n";
	std::cout << "----------- \n";
	std::cout << " 4 | 5 | 6 \n";
	std::cout << "----------- \n";
	std::cout << " 7 | 8 | 9 \n";
}

void printBoard() {
	std::cout << " " << board[0][0]<< "| " << board[0][1] << " | " << board[0][2] << " \n";
	std::cout << "----------- \n";
	std::cout << " " << board[1][0] << "| " << board[1][1] << " | " << board[1][2] << " \n";
	std::cout << "----------- \n";
	std::cout << " " << board[2][0] << "| " << board[2][1] << " | " << board[2][2] << " \n";

}

int addMark() {
	for (int i = 0, k = 1; i < 3; i++) {
		for (int j = 0; j < 3; j++, k++) {
			if (k==input)
				if (board[i][j] == ' ') {
					board[i][j] = mark;
					return 1;

				}
				else {
					std::cout << "Invalid input";
					//getc();
					return 0;
				}
		}
	}
}
int check() {
	//checking rows
	if (board[0][0] == mark && board[0][1] == mark && board[0][2] == mark)
		return 1;
	if (board[1][0] == mark && board[1][1] == mark && board[1][2] == mark)
		return 1;
	if (board[2][0] == mark && board[2][1] == mark && board[2][2] == mark)
		return 1;
	//checking colums
	if (board[0][0] == mark && board[1][0] == mark && board[2][0] == mark)
		return 1;
	if (board[0][1] == mark && board[1][1] == mark && board[2][1] == mark)
		return 1;
	if (board[0][2] == mark && board[1][2] == mark && board[2][2] == mark)
		return 1;
	//checking diagonals
	if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
		return 1;
	if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
		return 1;
	

	return 0;

}
