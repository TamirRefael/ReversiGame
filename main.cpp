#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <ctime>
#include <vector>
#include <random>
#include "Dolphin.h"
#include "Dog.h"
#include "Cat.h"
#include "Shark.h"
#include "Barracuda.h"
#include "Ant.h"
#include "Wasp.h"
#include "Locust.h"
#define Max_Player 100
#define Max_Board 4
#define BOARD_SIZE_Computer 4
const char EMPTY_SPACE = ' ';
const char HUMAN_PLAYER = 'X';
const char COMPUTER_PLAYER = 'O';
using namespace std;

int CreateBoard(string, string);

int Print_Board(char Board[][Max_Board], int size, string Name1, string Name2);

int Game(char Board[][Max_Board], int size, string Name1, string Name2);

bool Check_Move(char Board[][Max_Board], int size, int Row, int Col, char play_Now, char Opponet);

bool Set_Move(char Board[][Max_Board], int Board_size, int Row, int Col, char play_Now, char opponent);

bool Check_Move_Possible(char Board[][Max_Board], char play_Now, char opponent, int board_size);

void playTournament();

void playComputer(string Name);

void playGameComputer(string Name, int difficultyLevel);

void CreateBoardComputer(char board[][BOARD_SIZE_Computer]);

vector<std::pair<int, int>> getValidMovesComputer(const char board[][BOARD_SIZE_Computer], char player);

bool isValidMoveComputer(const char board[][BOARD_SIZE_Computer], char player, int row, int col);

char oppositePlayerComputer(char player);

void makeMoveComputer(char board[][BOARD_SIZE_Computer], char player, int row, int col);

int countPiecesComputer(const char board[][BOARD_SIZE_Computer], char player);

int getComputerMove(const char board[][BOARD_SIZE_Computer], char player, int difficultyLevel);

int main()
{
	char User_Name[50];
	char Password[50];
	string My_Text;
	string Temp_Name;
	string Temp_Password;
	ofstream MyFileWrite1;
	MyFileWrite1.open("Mammal.txt", ios::out | ios::app);
	ofstream MyFileWrite2;
	MyFileWrite2.open("Fish.txt", ios::out | ios::app);
	ofstream MyFileWrite3;
	MyFileWrite3.open("Bug.txt", ios::out | ios::app);
	ofstream MyFileWrite4;
	MyFileWrite4.open("AllPlayerUser.txt", ios::out | ios::app);
	ofstream MyFileWrite5;
	MyFileWrite5.open("ScoreBoard.txt", ios::out | ios::app);
	ofstream MyFileWrite6;
	MyFileWrite6.open("League.txt", ios::out | ios::app);
	int Menu_Choise, Type_Choise;
	cout << "Menu" << endl << endl << "1 - Register" << endl << "2 - Play againts the computer" << endl << "3 - Play League" << endl << "4 - Print Top Player" << endl << "5 - Exit" << endl;
	cout << endl;
	cin >> Menu_Choise;
	while (Menu_Choise != 5)
	{
		switch (Menu_Choise)
		{
		case 1:
		{
			system("CLS");
			int Count_Name = 0;
			cout << "Enter User Name :" << endl;
			cin >> User_Name;
			string Line;
			ifstream MyFileRead4("AllPlayerUser.txt");
			while (getline(MyFileRead4, Line))
			{
				string Check_Name;
				istringstream line_stram(Line);
				line_stram >> Check_Name;
				if (User_Name == Check_Name)
				{
					cout << "The user exist already" << endl;
					Count_Name = 1;
					break;
				}
			}
			MyFileRead4.close();
			if (Count_Name == 1)
			{
				cout << "Menu" << endl << endl << "1 - Register" << endl << "2 - Play againts the computer" << endl << "3 - Play League" << endl << "4 - Print Top Player" << endl << "5 - Exit" << endl;
				cout << endl;
				cin >> Menu_Choise;
				break;
			}
			cout << "Enter Password :" << endl;
			cin >> Password;
			cout << endl << "Choose your animal :" << endl << "1 - Dolphin" << endl << "2 - Dog" << endl << "3 - Cat" << endl << "4 - Shark" << endl << "5 - Barracuda" << endl << "6 - Ant" << endl << "7 - Wasp" << endl << "8 - Locust" << endl << endl;
			cin >> Type_Choise;
			cout << endl;
			switch (Type_Choise)
			{
			case 1:
			{
				char temp[] = "Dolphin";
				Dolphin dolphin(User_Name, Password, temp);
				MyFileWrite1 << dolphin.Get_User_Name() << " " << dolphin.Get_Password() << endl;
				MyFileWrite4 << dolphin.Get_User_Name() << " " << dolphin.Get_Type() << endl;
				MyFileWrite5 << dolphin.Get_User_Name() << " " << dolphin.Get_Score() << " " << dolphin.Get_Victory_League() << " " << dolphin.Get_Score_Bronze_VS_computer() << " " << dolphin.Get_Score_Silver_VS_computer() << " " << dolphin.Get_Score_Gold_VS_computer() << endl;
				break;
			}
			case 2:
			{
				char temp[] = "Dog";
				Dog dog(User_Name, Password, temp);
				MyFileWrite1 << dog.Get_User_Name() << " " << dog.Get_Password() << endl;
				MyFileWrite4 << dog.Get_User_Name() << " " << dog.Get_Type() << endl;
				MyFileWrite5 << dog.Get_User_Name() << " " << dog.Get_Score() << " " << dog.Get_Victory_League() << " " << dog.Get_Score_Bronze_VS_computer() << " " << dog.Get_Score_Silver_VS_computer() << " " << dog.Get_Score_Gold_VS_computer() << endl;
				break;
			}
			case 3:
			{
				char temp[] = "Cat";
				Cat cat(User_Name, Password, temp);
				MyFileWrite1 << cat.Get_User_Name() << " " << cat.Get_Password() << endl;
				MyFileWrite4 << cat.Get_User_Name() << " " << cat.Get_Type() << endl;
				MyFileWrite5 << cat.Get_User_Name() << " " << cat.Get_Score() << " " << cat.Get_Victory_League() << " " << cat.Get_Score_Bronze_VS_computer() << " " << cat.Get_Score_Silver_VS_computer() << " " << cat.Get_Score_Gold_VS_computer() << endl;
				break;
			}
			case 4:
			{
				char temp[] = "Shark";
				Shark shark(User_Name, Password, temp);
				MyFileWrite2 << shark.Get_User_Name() << " " << shark.Get_Password() << endl;
				MyFileWrite4 << shark.Get_User_Name() << " " << shark.Get_Type() << endl;
				MyFileWrite5 << shark.Get_User_Name() << " " << shark.Get_Score() << " " << shark.Get_Victory_League() << " " << shark.Get_Score_Bronze_VS_computer() << " " << shark.Get_Score_Silver_VS_computer() << " " << shark.Get_Score_Gold_VS_computer() << endl;
				break;
			}
			case 5:
			{
				char temp[] = "Barracuda";
				Barracuda barracuda(User_Name, Password, temp);
				MyFileWrite2 << barracuda.Get_User_Name() << " " << barracuda.Get_Password() << endl;
				MyFileWrite4 << barracuda.Get_User_Name() << " " << barracuda.Get_Type() << endl;
				MyFileWrite5 << barracuda.Get_User_Name() << " " << barracuda.Get_Score() << " " << barracuda.Get_Victory_League() << " " << barracuda.Get_Score_Bronze_VS_computer() << " " << barracuda.Get_Score_Silver_VS_computer() << " " << barracuda.Get_Score_Gold_VS_computer() << endl;
				break;
			}
			case 6:
			{
				char temp[] = "Ant";
				Ant ant(User_Name, Password, temp);
				MyFileWrite3 << ant.Get_User_Name() << " " << ant.Get_Password() << endl;
				MyFileWrite4 << ant.Get_User_Name() << " " << ant.Get_Type() << endl;
				MyFileWrite5 << ant.Get_User_Name() << " " << ant.Get_Score() << " " << ant.Get_Victory_League() << " " << ant.Get_Score_Bronze_VS_computer() << " " << ant.Get_Score_Silver_VS_computer() << " " << ant.Get_Score_Gold_VS_computer() << endl;
				break;
			}
			case 7:
			{
				char temp[] = "Wasp";
				Wasp wasp(User_Name, Password, temp);
				MyFileWrite3 << wasp.Get_User_Name() << " " << wasp.Get_Password() << endl;
				MyFileWrite4 << wasp.Get_User_Name() << " " << wasp.Get_Type() << endl;
				MyFileWrite5 << wasp.Get_User_Name() << " " << wasp.Get_Score() << " " << wasp.Get_Victory_League() << " " << wasp.Get_Score_Bronze_VS_computer() << " " << wasp.Get_Score_Silver_VS_computer() << " " << wasp.Get_Score_Gold_VS_computer() << endl;
				break;
			}
			case 8:
			{
				char temp[] = "Locust";
				Locust locust(User_Name, Password, temp);
				MyFileWrite3 << locust.Get_User_Name() << "	" << locust.Get_Password() << endl;
				MyFileWrite4 << locust.Get_User_Name() << " " << locust.Get_Type() << endl;
				MyFileWrite5 << locust.Get_User_Name() << " " << locust.Get_Score() << " " << locust.Get_Victory_League() << " " << locust.Get_Score_Bronze_VS_computer() << " " << locust.Get_Score_Silver_VS_computer() << " " << locust.Get_Score_Gold_VS_computer() << endl;
				break;
			}
			}
			system("CLS");
			cout << "Menu" << endl << endl << "1 - Register" << endl << "2 - Play againts the computer" << endl << "3 - Play League" << endl << "4 - Print Top Player" << endl << "5 - Exit" << endl;
			cout << endl;
			cin >> Menu_Choise;
			break;
		}
		case 2:
		{
			system("CLS");
			int Count_User_Check = 0;
			cout << "Enter User Name :" << endl;
			cin >> Temp_Name;
			cout << "Enter Password :" << endl;
			cin >> Temp_Password;
			string Line;
			ifstream MyFileRead1("Mammal.txt");
			ifstream MyFileRead2("Fish.txt");
			ifstream MyFileRead3("Bug.txt");
			while (getline(MyFileRead1, Line))
			{
				string word1, word2;
				istringstream line_stram(Line);
				line_stram >> word1 >> word2;
				if (Temp_Name == word1)
				{
					if (Temp_Password == word2)
					{
						system("CLS");
						cout << "succsesful" << endl;
						playComputer(word1);
						Count_User_Check = 1;
						break;
					}
					else
					{
						for (int i = 0; i < 3; i++)
						{
							cout << "Enter Password again :" << endl;
							cin >> Temp_Password;
							if (Temp_Password == word2)
							{
								system("CLS");
								cout << "succsesful" << endl;
								playComputer(word1);
								Count_User_Check = 1;
								break;
							}
						}
						if (Count_User_Check == 1)
						{
							break;
						}
						cout << "Wrong Password Good Bye" << endl;
						Count_User_Check = 1;
						break;
					}
				}
			}
			if (Count_User_Check == 0)
			{
				while (getline(MyFileRead2, Line))
				{
					string word1, word2;
					istringstream line_stram(Line);
					line_stram >> word1 >> word2;
					if (Temp_Name == word1)
					{
						if (Temp_Password == word2)
						{
							system("CLS");
							cout << "succsesful" << endl;
							playComputer(word1);
							Count_User_Check = 1;
							break;
						}
						else
						{
							for (int i = 0; i < 3; i++)
							{
								cout << "Enter Password again :" << endl;
								cin >> Temp_Password;
								if (Temp_Password == word2)
								{
									system("CLS");
									cout << "succsesful" << endl;
									playComputer(word1);
									Count_User_Check = 1;
									break;
								}
							}
							if (Count_User_Check == 1)
							{
								break;
							}
							cout << "Wrong Password Good Bye" << endl;
							Count_User_Check = 1;
							break;
						}
					}
				}
				if (Count_User_Check == 0)
				{
					while (getline(MyFileRead3, Line))
					{
						string word1, word2;
						istringstream line_stram(Line);
						line_stram >> word1 >> word2;
						if (Temp_Name == word1)
						{
							if (Temp_Password == word2)
							{
								system("CLS");
								cout << "succsesful" << endl;
								playComputer(word1);
								Count_User_Check = 1;
								break;
							}
							else
							{
								for (int i = 0; i < 3; i++)
								{
									cout << "Enter Password again :" << endl;
									cin >> Temp_Password;
									if (Temp_Password == word2)
									{
										system("CLS");
										cout << "succsesful" << endl;
										playComputer(word1);
										Count_User_Check = 1;
										break;
									}
								}
								if (Count_User_Check == 1)
								{
									break;
								}
								system("CLS");
								cout << "Wrong Password Good Bye" << endl << endl;
								Count_User_Check = 1;
								break;
							}
						}
					}
				}
			}
			MyFileRead1.close();
			MyFileRead2.close();
			MyFileRead3.close();
			if (Count_User_Check == 0)
			{
				cout << "The user does not exist" << endl;
			}
			Count_User_Check = 0;
			cout << "Menu" << endl << endl << "1 - Register" << endl << "2 - Play againts the computer" << endl << "3 - Play League" << endl << "4 - Print Top Player" << endl << "5 - Exit" << endl;
			cout << endl;
			cin >> Menu_Choise;
			break;
		}
		case 3:
		{
			system("CLS");
			string temp_line;
			string temp_word;
			ifstream MyFileRead6("League.txt");
			getline(MyFileRead6, temp_line);
			istringstream line_stram(temp_line);
			line_stram >> temp_word;
			if (temp_word != "")
			{
				cout << "You have to finish an existing league before starting a new one" << endl;
				MyFileRead6.close();
				playTournament();
			}
			else
			{
				cout << "1 - General league" << endl << "2 - League by type" << endl << "3 - League by animal" << endl;
				cin >> Menu_Choise;
				switch (Menu_Choise)
				{
				case 1:
				{
					string Line;
					string word1;
					string Names_Player[Max_Player];
					ifstream MyFileRead4("AllPlayerUser.txt");
					int Sum_Player = 0;
					while (getline(MyFileRead4, Line) && Sum_Player < Max_Player)
					{
						istringstream line_stram(Line);
						line_stram >> word1;
						Names_Player[Sum_Player] = word1;
						Sum_Player++;
					}
					MyFileRead4.close();
					if (Sum_Player < 2)
					{
						cout << "There are not enough players to start a league" << endl;
						break;
					}
					srand(time(NULL));
					for (int i = 0; i < Sum_Player; i++)
					{
						int j = rand() % Sum_Player;
						swap(Names_Player[i], Names_Player[j]);
					}
					int Sum_Matches = Sum_Player / 2;
					for (int i = 0; i < Sum_Matches; i++)
					{
						MyFileWrite6 << Names_Player[i] << " " << Names_Player[Sum_Player - i - 1] << endl;
					}
					if (Sum_Player % 2 != 0)
					{
						MyFileWrite6 << Names_Player[Sum_Player / 2] << endl;
					}
					MyFileWrite5.close();
					MyFileWrite6.close();
					MyFileRead6.close();
					playTournament();
					break;
				}
				case 2:
				{
					int choise_type;
					cout << endl << "Choose a Type :" << endl << "1 - Mammal" << endl << "2 - Fish" << endl << "3 - Bug" << endl;
					cin >> choise_type;
					switch (choise_type)
					{
					case 1:
					{
						string Line;
						string word1;
						string Names_Player[Max_Player];
						ifstream MyFileRead4("Mammal.txt");
						int Sum_Player = 0;
						while (getline(MyFileRead4, Line) && Sum_Player < Max_Player)
						{
							istringstream line_stram(Line);
							line_stram >> word1;
							Names_Player[Sum_Player] = word1;
							Sum_Player++;
						}
						MyFileRead4.close();
						if (Sum_Player < 2)
						{
							cout << "There are not enough players to start a league" << endl;
							break;
						}
						srand(time(NULL));
						for (int i = 0; i < Sum_Player; i++)
						{
							int j = rand() % Sum_Player;
							swap(Names_Player[i], Names_Player[j]);
						}
						int Sum_Matches = Sum_Player / 2;
						for (int i = 0; i < Sum_Matches; i++)
						{
							MyFileWrite6 << Names_Player[i] << " " << Names_Player[Sum_Player - i - 1] << endl;
						}
						if (Sum_Player % 2 != 0)
						{
							MyFileWrite6 << Names_Player[Sum_Player / 2] << endl;
						}
						MyFileWrite5.close();
						MyFileWrite6.close();
						MyFileRead6.close();
						playTournament();
						break;
					}
					case 2:
					{
						string Line;
						string word1;
						string Names_Player[Max_Player];
						ifstream MyFileRead4("Fish.txt");
						int Sum_Player = 0;
						while (getline(MyFileRead4, Line) && Sum_Player < Max_Player)
						{
							istringstream line_stram(Line);
							line_stram >> word1;
							Names_Player[Sum_Player] = word1;
							Sum_Player++;
						}
						MyFileRead4.close();
						if (Sum_Player < 2)
						{
							cout << "There are not enough players to start a league" << endl;
							break;
						}
						srand(time(NULL));
						for (int i = 0; i < Sum_Player; i++)
						{
							int j = rand() % Sum_Player;
							swap(Names_Player[i], Names_Player[j]);
						}
						int Sum_Matches = Sum_Player / 2;
						for (int i = 0; i < Sum_Matches; i++)
						{
							MyFileWrite6 << Names_Player[i] << " " << Names_Player[Sum_Player - i - 1] << endl;
						}
						if (Sum_Player % 2 != 0)
						{
							MyFileWrite6 << Names_Player[Sum_Player / 2] << endl;
						}
						MyFileWrite5.close();
						MyFileWrite6.close();
						MyFileRead6.close();
						playTournament();
						break;
					}
					case 3:
					{
						string Line;
						string word1;
						string Names_Player[Max_Player];
						ifstream MyFileRead4("Bug.txt");
						int Sum_Player = 0;
						while (getline(MyFileRead4, Line) && Sum_Player < Max_Player)
						{
							istringstream line_stram(Line);
							line_stram >> word1;
							Names_Player[Sum_Player] = word1;
							Sum_Player++;
						}
						MyFileRead4.close();
						if (Sum_Player < 2)
						{
							cout << "There are not enough players to start a league" << endl;
							break;
						}
						srand(time(NULL));
						for (int i = 0; i < Sum_Player; i++)
						{
							int j = rand() % Sum_Player;
							swap(Names_Player[i], Names_Player[j]);
						}
						int Sum_Matches = Sum_Player / 2;
						for (int i = 0; i < Sum_Matches; i++)
						{
							MyFileWrite6 << Names_Player[i] << " " << Names_Player[Sum_Player - i - 1] << endl;
						}
						if (Sum_Player % 2 != 0)
						{
							MyFileWrite6 << Names_Player[Sum_Player / 2] << endl;
						}
						MyFileWrite5.close();
						MyFileWrite6.close();
						MyFileRead6.close();
						playTournament();
						break;
					}
					}
					break;
				}
				case 3:
				{
					cout << "Write the animal you are interested in : Dolphin - Dog - Shark - Barracuda - Ant  - Wasp - Locust" << endl;
					string animal_choose;
					cin >> animal_choose;
					string Line;
					string word1, word2;
					string Names_Player[Max_Player];
					ifstream MyFileRead4("AllPlayerUser.txt");
					int Sum_Player = 0;
					while (getline(MyFileRead4, Line) && Sum_Player < Max_Player)
					{
						istringstream line_stram(Line);
						line_stram >> word1 >> word2;
						if (animal_choose == word2)
						{
							Names_Player[Sum_Player] = word1;
							Sum_Player++;
						}
					}
					MyFileRead4.close();
					if (Sum_Player < 2)
					{
						cout << "There are not enough players to start a league" << endl;
						break;
					}
					srand(time(NULL));
					for (int i = 0; i < Sum_Player; i++)
					{
						int j = rand() % Sum_Player;
						swap(Names_Player[i], Names_Player[j]);
					}
					int Sum_Matches = Sum_Player / 2;
					for (int i = 0; i < Sum_Matches; i++)
					{
						MyFileWrite6 << Names_Player[i] << " " << Names_Player[Sum_Player - i - 1] << endl;
					}
					if (Sum_Player % 2 != 0)
					{
						MyFileWrite6 << Names_Player[Sum_Player / 2] << endl;
					}
					MyFileWrite5.close();
					MyFileWrite6.close();
					MyFileRead6.close();
					playTournament();
					break;
				}
				}
			}
			cout << "Enter your option " << endl << "1 - Register " << endl << "2 - Play against the computer " << endl << "3 - Play league " << endl << "4 - Leaderboard " << endl << "5 - Exit" << endl;
			cin >> Menu_Choise;
			break;
		}
		case 4:
		{
			system("CLS");
			for (int i = 1; i <= 5; i++)
			{
				multimap<int, string, less<int>> Temp;
				ifstream MyFileRead5("ScoreBoard.txt");
				string line;
				while (getline(MyFileRead5, line))
				{
					string username;
					long score;
					int bronze, silver, gold, champ;
					istringstream iss(line);
					iss >> username >> score >> champ >> bronze >> silver >> gold;
					if (i == 1) { Temp.insert(make_pair(score, username)); }
					if (i == 2) { Temp.insert(make_pair(champ, username)); }
					if (i == 3) { Temp.insert(make_pair(bronze, username)); }
					if (i == 4) { Temp.insert(make_pair(silver, username)); }
					if (i == 5) { Temp.insert(make_pair(gold, username)); }
				}
				MyFileRead5.close();
				int rank = 1;
				if (i == 1) { cout << "Leader Board" << endl; }
				if (i == 2) { cout << "Champ Board" << endl; }
				if (i == 3) { cout << "Bronze Board" << endl; }
				if (i == 4) { cout << "Silver Board" << endl; }
				if (i == 5) { cout << "Gold Board" << endl; }
				for (auto it = Temp.rbegin(); it != Temp.rend(); ++it)
				{
					cout << rank++ << ". " << it->second << " - " << it->first << " points" << endl;
				}
				cout << endl;
			}
			cout << "Enter your option " << endl << "1 - Register " << endl << "2 - Play against the computer " << endl << "3 - Play league " << endl << "4 - Leaderboard " << endl << "5 - Exit" << endl;
			cin >> Menu_Choise;
			break;
		}
		break;
		}
	}
	if (Menu_Choise == 5)
	{
		cout << "Good Bye My Friend ... " << endl;
	}
	return 0;
}


int CreateBoard(string Name1, string Name2)
{
	for (int i = 0; i < 2000000000; i++)
	{
		// לולאה שמעכבת את זמן הפלט
	}
	int Board_size = 0;
	system("cls");
	cout << "Choose the board size you want to create :" << endl;
	cout << "*** NOTICE : The size must be even and greater than 3 ***" << endl;
	cin >> Board_size;
	while (Board_size < 4 && Board_size % 2 != 0 && Board_size < 21)
	{
		cout << "Incorrect board size Please select again" << endl;
		cin >> Board_size;
	}
	char Board[Max_Board][Max_Board];
	char A = 'X';
	char B = 'O';
	for (int i = 0; i < Board_size; i++)
	{
		for (int j = 0; j < Board_size; j++)
		{
			Board[i][j] = ' ';
		}
	}
	Board[Board_size / 2 - 1][Board_size / 2 - 1] = A;
	Board[Board_size / 2 - 1][Board_size / 2] = B;
	Board[Board_size / 2][Board_size / 2 - 1] = B;
	Board[Board_size / 2][Board_size / 2] = A;
	return Game(Board, Board_size, Name1, Name2);
}


int Print_Board(char Board[][Max_Board], int size, string Name1, string Name2)
{
	system("cls");
	for (int i = 0; i < size; i++)
	{
		cout << " ";
		for (int j = 0; j < size; j++)
		{
			cout << "+---";
		}
		cout << "+";
		cout << endl;
		cout << i;
		for (int j = 0; j < size; j++)
		{
			cout << "| " << Board[i][j] << " ";
		}
		cout << "|";
		cout << endl;
	}
	cout << " ";
	for (int j = 0; j < size; j++)
	{
		cout << "+---";
	}
	cout << "+";
	cout << endl;
	int temp = 0;
	cout << "   ";
	for (int j = 0; j < size; j++)
	{
		cout << temp << "   ";
		temp++;
	}
	cout << endl << endl;
	cout << "            " << Name1 << "  VS  " << Name2 << endl << endl;
	int Count_X = 0, Count_O = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Board[i][j] == 'X')
			{
				Count_X++;
			}
			if (Board[i][j] == 'O')
			{
				Count_O++;
			}
		}
	}
	cout << "            " << Count_X << "  -  " << Count_O << endl << endl;
	if (Count_X + Count_O == (size * size))
	{
		if (Count_X > Count_O)
		{
			return 1;
		}
		else if (Count_X < Count_O)
		{
			return 0;
		}
		else
		{
			return 2;
		}
	}
	else if (!Check_Move_Possible(Board, 'X', '0', size) && !Check_Move_Possible(Board, '0', 'X', size))
	{
		if (Count_X > Count_O)
		{
			return 1;
		}
		else if (Count_X < Count_O)
		{
			return 0;
		}
		else
		{
			return 2;
		}
	}
}


int Game(char Board[][Max_Board], int size, string Name1, string Name2)
{
	system("cls");
	char player1 = 'X';
	char player2 = 'O';
	char play_Now = player1;
	char opponent = player2;
	int Row, Col;
	cout << "***Welcome***" << endl;
	Print_Board(Board, size, Name1, Name2);
	while (true)
	{
		if (Check_Move_Possible(Board, play_Now, opponent, size) == 1)
		{
			// get player's move and make sure it's valid
			cout << "Now it's the player's turn : " << play_Now << endl;
			cout << "Enter your next Position : " << endl;
			cout << "Enter Row : " << endl;
			cin >> Row;
			cout << "Enter Col : " << endl;
			cin >> Col;
			while (!Check_Move(Board, size, Row, Col, play_Now, opponent))
			{
				cout << "Improper move, enter another move :" << endl;
				cout << "Enter Row : " << endl;
				cin >> Row;
				cout << "Enter Col : " << endl;
				cin >> Col;
			}
			// make the move, print the board and score, and switch players
			Set_Move(Board, size, Row, Col, play_Now, opponent);
			Print_Board(Board, size, Name1, Name2);
			cout << "Next player" << endl;
			char temp = opponent;
			opponent = play_Now;
			play_Now = temp;
		}
		else if (Check_Move_Possible(Board, play_Now, opponent, size) == 0 && Check_Move_Possible(Board, opponent, play_Now, size) == 0)
		{
			// both players have no valid moves left, so the game is finished
			break;
		}
		else
		{
			// the current player has no valid moves left, so switch players
			cout << "Player " << play_Now << " has no valid moves. Switching players." << endl;
			char temp = opponent;
			opponent = play_Now;
			play_Now = temp;
		}
	}
	int S = Print_Board(Board, size, Name1, Name2);
	switch (S)
	{
		case 0:
		{
			ifstream MyFileRead5("ScoreBoard.txt");
			ofstream outfile("Temp.txt", ios::app);
			string line;
			bool found = false;
			while (getline(MyFileRead5, line)) 
			{
				istringstream iss(line);
				string name;
				int score, Victory, bronzepoints, silverpoints, goldpoints;
				if (iss >> name >> score >> Victory >> bronzepoints >> silverpoints >> goldpoints)
				{
					if (name == Name2)
					{
						found = true;
						score++;
						// Overwrite the line in the file with the updated values
						outfile << name << " " << score << " " << bronzepoints << " " << silverpoints << " " << goldpoints << " " << Victory << endl;
					}
					else 
					{
						// Write the original line to the output file
						outfile << line << endl;
					}
				}
			}
			// Close the input and output files
			MyFileRead5.close();
			outfile.close();
			remove("ScoreBoard.txt");
			rename("Temp.txt", "ScoreBoard.txt");
			return 0;
		}
	case 1:
	{
		ifstream MyFileRead5("ScoreBoard.txt");
		ofstream outfile("Temp.txt", ios::app);
		string line;
		bool found = false;
		while (getline(MyFileRead5, line))
		{
			istringstream iss(line);
			string name;
			int score, Victory, bronzepoints, silverpoints, goldpoints;
			if (iss >> name >> score >> Victory >> bronzepoints >> silverpoints >> goldpoints)
			{
				if (name == Name1)
				{
					found = true;
					score++;
					// Overwrite the line in the file with the updated values
					outfile << name << " " << score << " " << bronzepoints << " " << silverpoints << " " << goldpoints << " " << Victory << endl;
				}
				else {
					// Write the original line to the output file
					outfile << line << endl;
				}
			}
		}
		// Close the input and output files
		MyFileRead5.close();
		outfile.close();
		remove("ScoreBoard.txt");
		rename("Temp.txt", "ScoreBoard.txt");
		return 1;
	}
	case 2:
	{
		return 2;
	}
	}
}


bool Set_Move(char Board[][Max_Board], int Board_size, int Row, int Col, char play_Now, char opponent)
{
	if (!Check_Move(Board, Board_size, Row, Col, play_Now, opponent))
	{
		return false;
	}
	Board[Row][Col] = play_Now;
	for (int dRow = -1; dRow <= 1; dRow++) 
	{
		for (int dCol = -1; dCol <= 1; dCol++)
		{
			if (dRow == 0 && dCol == 0)
			{
				continue;
			}
			int r = Row + dRow;
			int c = Col + dCol;
			bool foundOpponent = false;
			while (r >= 0 && r < Board_size && c >= 0 && c < Board_size)
			{
				if (Board[r][c] == ' ')
				{
					break;
				}
				if (Board[r][c] == opponent) 
				{
					foundOpponent = true;
				}
				else if (Board[r][c] == play_Now) 
				{
					if (foundOpponent) 
					{
						int flipRow = Row + dRow;
						int flipCol = Col + dCol;
						while (flipRow != r || flipCol != c) 
						{
							Board[flipRow][flipCol] = play_Now;
							flipRow += dRow;
							flipCol += dCol;
						}
					}
					break;
				}
				r += dRow;
				c += dCol;
			}
		}
	}
	return true;
}


bool Check_Move_Possible(char Board[][Max_Board], char play_Now, char opponent, int board_size)
{
	// Check if any empty position is a valid move
	for (int row = 0; row < board_size; row++) {
		for (int col = 0; col < board_size; col++) {
			if (Board[row][col] == ' ' && Check_Move(Board, board_size, row, col, play_Now, opponent)) {
				return true;
			}
		}
	}
	// Check if the opponent has a valid move that the current player must block
	for (int row = 0; row < board_size; row++) {
		for (int col = 0; col < board_size; col++) {
			if (Board[row][col] == opponent && Check_Move(Board, board_size, row, col, opponent, play_Now)) {
				// Check if the player can block the opponent's move
				for (int r = 0; r < board_size; r++) {
					for (int c = 0; c < board_size; c++) {
						if (Board[r][c] == ' ' && Check_Move(Board, board_size, r, c, play_Now, opponent)) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}


bool Check_Move(char Board[][Max_Board], int size, int row, int col, char play_Now, char Opponet)
{
	// Check if the move is within bounds
	if (row < 0 || row >= size || col < 0 || col >= size) {
		return false;
	}
	// Check if the position is already occupied
	if (Board[row][col] != ' ') {
		return false;
	}
	// Check if the move captures any pieces
	for (int dRow = -1; dRow <= 1; dRow++) {
		for (int dCol = -1; dCol <= 1; dCol++) {
			if (dRow == 0 && dCol == 0) {
				continue;
			}
			int r = row + dRow;
			int c = col + dCol;
			bool foundOpponent = false;
			while (r >= 0 && r < size && c >= 0 && c < size) {
				if (Board[r][c] == ' ') {
					break;
				}
				if (Board[r][c] == Opponet) {
					foundOpponent = true;
				}
				else if (Board[r][c] == play_Now)
				{
					if (foundOpponent) {
						return true;
					}
					break;
				}
				r += dRow;
				c += dCol;
			}
		}
	}
	return false;
}


void playTournament() 
{
	string line;
	ifstream MyFileRead6("League.txt");
	if (!MyFileRead6)
	{
		cout << "Error opening tournament file" << endl;
		return;
	}
	ofstream outfile1("tempLeague.txt");
	ofstream outfile2("tempScoreBoard.txt");
	// Loop through rounds until there is only one player left
	while (!MyFileRead6.eof())
	{
		vector<string> winners;
		int gameNum = 0;
		// Loop through games in this round
		while (getline(MyFileRead6, line))
		{
			int result = 0;
			// Get player names
			string name1, name2;
			stringstream ss(line);
			ss >> name1 >> name2;
			if ((name2 == ""))
			{
				// No name2, consider name1 as winner
				winners.push_back(name1);
				continue;
			}
			// Play game
			cout << name1 << " vs " << name2 << endl;
			result = CreateBoard(name1, name2);
			// Determine winner and add to list of winners
			if (result == 1)
			{
				winners.push_back(name1);
			}
			else if (result == 0)
			{
				winners.push_back(name2);
			}
			else
			{
				cout << "Game " << gameNum << " resulted in a draw. Replaying..." << endl;
				continue;
			}
			gameNum++;
			if (gameNum % 2 == 0 && gameNum >= 2)
			{
				// Write pair of winners to next round file
				outfile1 << winners[winners.size() - 2] << " " << winners[winners.size() - 1] << endl;
			}
			line = "";
		}
		if (winners.size() == 1)
		{
			// Tournament finished
			cout << "Tournament finished. Congratulations! Your the Winner : " << winners[0] << endl;
			// Update score file
			ifstream MyFileRead5("ScoreBoard.txt");
			ifstream scorefile("tempScoreBoard.txt");
			if (!scorefile)
			{
				cout << "Error opening score file" << endl;
				return;
			}
			string line;
			bool updated = false;
			while (getline(MyFileRead5, line))
			{
				string name;
				int score, champ, bronzepoints, silverpoints, goldpoints;
				istringstream iss(line);
				if (iss >> name >> score >> champ >> bronzepoints >> silverpoints >> goldpoints)
				{
					if (name == winners[0])
					{
						updated = true;
						champ++;
						outfile2 << name << " " << score << " " << champ << " " << bronzepoints << " " << silverpoints << " " << goldpoints << endl;
					}
					else {
						outfile2 << line << endl;
					}
				}
			}
			scorefile.close();
			outfile2.close();
			MyFileRead5.close();
			MyFileRead6.close();
			outfile1.close();
			unlink("League.txt");
			remove("tempLeague.txt");
			unlink("ScoreBoard.txt");
			rename("tempScoreBoard.txt", "ScoreBoard.txt");
			return;
		}

		// Write remaining winner to next round file if odd number of winners
		if (winners.size() % 2 == 0)
		{
			int temp = 0;
			string line3;
			ifstream outfileRead1("tempLeague.txt", ios::app);
			ofstream outfile1("tempLeague.txt", ios::app);
			while (getline(outfileRead1, line3))
			{
				string name1, name2;
				stringstream ss(line3);
				ss >> name1 >> name2;
				if (name1 == winners[winners.size() - 2] && name2 == winners[winners.size() - 1])
				{
					outfileRead1.close();
					temp++;
					break;
				}
				if ((name1 == winners[winners.size() - 1] && name2 == winners[winners.size() - 2]))
				{
					outfileRead1.close();
					temp++;
					break;
				}
			}
			if (temp == 0)
			{
				outfileRead1.close();
				outfile1 << winners[winners.size() - 2] << " " << winners[winners.size() - 1] << endl;
			}
		}

		// Prepare for next round
		MyFileRead6.close();
		outfile1.close();
		remove("League.txt");
		rename("tempLeague.txt", "League.txt");
		cout << "name change" << endl;
		MyFileRead6.open("League.txt");
		if (!MyFileRead6)
		{
			cout << "Error opening tournament file" << endl;
			return;
		}
	}
}


void playComputer(string Name)
{
	cout << "Welcome to Game Reversi VS computer!" << endl;
	int difficulty_Level;
	while (true) 
	{
		cout << "Choose difficulty level (1-3): ";
		cin >> difficulty_Level;
		if (difficulty_Level >= 1 && difficulty_Level <= 3) 
		{
			break;
		}
		cout << "Invalid difficulty level. Please try again." << std::endl;
	}
	playGameComputer(Name,difficulty_Level);
}


void playGameComputer(string Name, int difficultyLevel)
{
	char board[BOARD_SIZE_Computer][BOARD_SIZE_Computer];
	CreateBoardComputer(board);
	char currentPlayer = HUMAN_PLAYER;
	while (true)
	{
		std::vector<std::pair<int, int>> validMoves = getValidMovesComputer(board, currentPlayer);
		if (validMoves.empty())
		{
			break;
		}
		if (currentPlayer == HUMAN_PLAYER)
		{
			std::cout << "Your move. Valid moves: ";
			for (auto& validMove : validMoves)
			{
				std::cout << "(" << validMove.first << "," << validMove.second << ") ";
			}
			std::cout << std::endl;
			int row, col;
			while (true) {
				std::cout << "Enter row and column: ";
				std::cin >> row >> col;
				if (isValidMoveComputer(board, currentPlayer, row, col)) {
					break;
				}
				std::cout << "Invalid move. Please try again." << std::endl;
			}
			makeMoveComputer(board, currentPlayer, row, col);
		}
		else {
			std::cout << "Computer's move:" << std::endl;
			int computerMove = getComputerMove(board, currentPlayer, difficultyLevel);
			int row = computerMove / BOARD_SIZE_Computer;
			int col = computerMove % BOARD_SIZE_Computer;
			makeMoveComputer(board, currentPlayer, row, col);
			std::cout << "Row: " << row << " Col: " << col << std::endl;
		}
		std::cout << "Current board:" << std::endl;
		Print_Board(board, Max_Board, "X", "O");

		currentPlayer = oppositePlayerComputer(currentPlayer);
	}

	int humanScore = countPiecesComputer(board, HUMAN_PLAYER);
	int computerScore = countPiecesComputer(board, COMPUTER_PLAYER);

	if (humanScore > computerScore) {
		std::cout << "You win!" << std::endl;
	}
	else if (humanScore < computerScore) {
		std::cout << "Computer wins!" << std::endl;
	}
	else {
		std::cout << "Tie game!" << std::endl;
	}
}


void CreateBoardComputer(char board[][BOARD_SIZE_Computer])
{
	// Initialize the board with empty spaces
	for (int row = 0; row < BOARD_SIZE_Computer; row++)
	{
		for (int col = 0; col < BOARD_SIZE_Computer; col++)
		{
			board[row][col] = EMPTY_SPACE;
		}
	}
	int middle = BOARD_SIZE_Computer / 2;
	board[middle - 1][middle - 1] = board[middle][middle] = HUMAN_PLAYER;
	board[middle - 1][middle] = board[middle][middle - 1] = COMPUTER_PLAYER;
}


vector<std::pair<int, int>> getValidMovesComputer(const char board[][BOARD_SIZE_Computer], char player)
{
	std::vector<std::pair<int, int>> validMoves;
	for (int row = 0; row < BOARD_SIZE_Computer; row++) 
	{
		for (int col = 0; col < BOARD_SIZE_Computer; col++)
		{
			if (isValidMoveComputer(board, player, row, col))
			{
				validMoves.push_back(std::make_pair(row, col));
			}
		}
	}
	return validMoves;
}


bool isValidMoveComputer(const char board[][BOARD_SIZE_Computer], char player, int row, int col)
{
	// Check that the space is empty
	if (board[row][col] != EMPTY_SPACE) {
		return false;
	}

	// Check that the move flips at least one piece
	bool foundFlip = false;
	for (int dRow = -1; dRow <= 1; dRow++) 
	{
		for (int dCol = -1; dCol <= 1; dCol++) 
		{
			if (dRow == 0 && dCol == 0) 
			{
				continue;
			}

			int r = row + dRow, c = col + dCol;
			while (r >= 0 && r < BOARD_SIZE_Computer && c >= 0 && c < BOARD_SIZE_Computer && board[r][c] == oppositePlayerComputer(player)) 
			{
				r += dRow;
				c += dCol;
			}

			if (r >= 0 && r < BOARD_SIZE_Computer && c >= 0 && c < BOARD_SIZE_Computer && board[r][c] == player && (r != row + dRow || c != col + dCol)) {
				foundFlip = true;
			}
		}
	}

	return foundFlip;
}


char oppositePlayerComputer(char player) 
{
	return (player == HUMAN_PLAYER) ? COMPUTER_PLAYER : HUMAN_PLAYER;
}


void makeMoveComputer(char board[][BOARD_SIZE_Computer], char player, int row, int col)
{
	// Place the piece
	board[row][col] = player;

	// Flip any necessary pieces
	for (int dRow = -1; dRow <= 1; dRow++) 
	{
		for (int dCol = -1; dCol <= 1; dCol++) 
		{
			if (dRow == 0 && dCol == 0)
			{
				continue;
			}

			int r = row + dRow, c = col + dCol;
			while (r >= 0 && r < BOARD_SIZE_Computer && c >= 0 && c < BOARD_SIZE_Computer && board[r][c] == oppositePlayerComputer(player)) 
			{
				r += dRow;
				c += dCol;
			}

			if (r >= 0 && r < BOARD_SIZE_Computer && c >= 0 && c < BOARD_SIZE_Computer && board[r][c] == player && (r != row + dRow || c != col + dCol)) 
			{
				// We found a line of opponent pieces to flip
				r -= dRow;
				c -= dCol;
				while (r != row || c != col) 
				{
					board[r][c] = player;
					r -= dRow;
					c -= dCol;
				}
			}
		}
	}
}


int countPiecesComputer(const char board[][BOARD_SIZE_Computer], char player)
{
	int count = 0;
	for (int row = 0; row < BOARD_SIZE_Computer; row++) 
	{
		for (int col = 0; col < BOARD_SIZE_Computer; col++)
		{
			if (board[row][col] == player) 
			{
				count++;
			}
		}
	}
	return count;
}


int getComputerMove(const char board[][BOARD_SIZE_Computer], char player, int difficultyLevel)
{
	std::vector<std::pair<int, int>> validMoves = getValidMovesComputer(board, player);
	std::random_device rd;
	std::mt19937 rng(rd());
	if (validMoves.empty()) {
		return -1;
	}
	else if (validMoves.size() == 1) {
		return validMoves[0].first * BOARD_SIZE_Computer + validMoves[0].second;
	}
	int move = -1;
	int maxScore = -1;

	for (auto& validMove : validMoves) {
		char tempBoard[BOARD_SIZE_Computer][BOARD_SIZE_Computer];
		std::memcpy(tempBoard, board, BOARD_SIZE_Computer * BOARD_SIZE_Computer);

		makeMoveComputer(tempBoard, player, validMove.first, validMove.second);
		int score = countPiecesComputer(tempBoard, player);

		if (difficultyLevel > 1 && oppositePlayerComputer(player) != HUMAN_PLAYER) {
			int opponentMove = getComputerMove(tempBoard, oppositePlayerComputer(player), difficultyLevel - 1);
			if (opponentMove != -1) {
				char tempBoard2[BOARD_SIZE_Computer][BOARD_SIZE_Computer];
				std::memcpy(tempBoard2, tempBoard, BOARD_SIZE_Computer * BOARD_SIZE_Computer);

				int opponentRow = opponentMove / BOARD_SIZE_Computer;
				int opponentCol = opponentMove % BOARD_SIZE_Computer;
				makeMoveComputer(tempBoard2, oppositePlayerComputer(player), opponentRow, opponentCol);
				score -= countPiecesComputer(tempBoard2, oppositePlayerComputer(player));
			}
		}

		if (score > maxScore) {
			maxScore = score;
			move = validMove.first * BOARD_SIZE_Computer + validMove.second;
		}
	}

	return move;
}