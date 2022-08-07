#include <iostream>
#include <vector>
using namespace std;

class Board
{
public:
	static int emptySpaces;
	static vector<vector<char>> boardSpaces;
	
public: 
	Board()
	{
		cout << "   |   |   \n";
		cout << "___|___|___\n";
		cout << "   |   |   \n";
		cout << "___|___|___\n";
		cout << "   |   |   \n";
		cout << "___|___|___\n";
	}
	
	void drawBoard()
	{
		cout << "\n\n.................................................\n\n";
		cout << "   |   |   \n" ;
		cout << " " << boardSpaces[0][0] << " | " << boardSpaces[0][1] << " | " << boardSpaces[0][2] << endl;
		cout << "___|___|___\n";
		cout << "   |   |   \n";
		cout << " " << boardSpaces[1][0] << " | " << boardSpaces[1][1] << " | " << boardSpaces[1][2] << endl;
		cout << "___|___|___\n";
		cout << "   |   |   \n";
		cout << " " << boardSpaces[2][0] << " | " << boardSpaces[2][1] << " | "  << boardSpaces[2][2] << endl;
		cout << "   |   |   \n\n";
	}
};

int Board::emptySpaces = 9;

vector<vector<char>> Board::boardSpaces = 
	{
		{'0', '1', '2'},
		{'3', '4', '5'},
		{'6', '7', '8'}
	};

class Player
{
public:
	int userId;
	string name;
	char token;
	
public:
	
	Player(int userId)
	{
		this->userId = userId;
		InitializePlayer(userId);
		cout << "Welcome " << name << endl;;
	}

	void InitializePlayer(int userId){
		string userNo = userId == 1 ? "first" : "second" ;
		cout << "Enter the name of the " << userNo << " player: ";
		getline(cin, name);
		token = userId == 1 ? 'x' : 'y'; 
	}
	
	void play(){
		int number;
		
		m:
		cout << "Enter a number, " << name << " : ";
		cin >> number;
		
		int row = number / 3;
		int col = number % 3;
		
		if(Board::boardSpaces[row][col] == 'x' || Board::boardSpaces[row][col] == 'y' || number > 9)
		{
			cout << "Choose another space" << endl;
			goto m;
		}
		
		Board::boardSpaces[row][col] = token;
		Board::emptySpaces -= 1;
	}
	
	bool isWinner()
	{
		for (int i = 0; i < 3; i++)
		{
			if(
				((Board::boardSpaces[i][0] == token) && (Board::boardSpaces[i][1] == token) && (Board::boardSpaces[i][2] == token))
				||
				((Board::boardSpaces[0][i] == token) && (Board::boardSpaces[1][i] == token) && (Board::boardSpaces[2][i] == token))
				||
				((Board::boardSpaces[0][0] == token) && (Board::boardSpaces[1][1] == token) && (Board::boardSpaces[2][2] == token))
				||
				((Board::boardSpaces[0][2] == token) && (Board::boardSpaces[1][1] == token) && (Board::boardSpaces[2][0] == token))
			)  return true;
		}
		return false;
	}

};

void playTicTacToe(Player player1, Player player2)
{	
	startGame:
	
	Board board;
	board.drawBoard();
	
	while(Board::emptySpaces)
	{
		player1.play();
		board.drawBoard();
		if(player1.isWinner()) {
			cout <<  player1.name << " is the winner!" << endl ;
			goto endGame;
		}
		
		if(Board::emptySpaces)
		{
			player2.play();
			board.drawBoard();
			if(player2.isWinner()) {
			cout <<  player2.name << " is the winner!" << endl ;
			goto endGame;
		}
		}
		else{
			cout << "No Winner!" << endl;
		}
	}
	
	endGame:
	cout << "Would you like to play again; Type 'y' to continue and 'n' to stop: ";
	char choice;
	cin >> choice;
	if (choice == 'y')
	{
		goto startGame;
	} 
	else
	{
		cout << "Thank you for playing"; 
	}
}


void TicTacToe()
{
	
	Player player1 = Player(1);
	Player player2 = Player(2);
	
	playTicTacToe(player1, player2);
}