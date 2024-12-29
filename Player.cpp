#include "Player.h"
#include <cstring>


Player::Player()
{
	User_Name = NULL;
	Password = NULL;
	Type = NULL;
	Score = 0;
	Victory_League = 0;
	Score_Bronze_VS_computer = 0;
	Score_Silver_VS_computer = 0;
	Score_Gold_VS_computer = 0;
}

Player::Player(char* user_name, char* password, char* type)
{
	User_Name = new char(strlen(user_name) + 1);
	if (!User_Name)
	{
		cout << "Memory Error" << endl;
	}
	strcpy(User_Name, user_name);
	Password = new char(strlen(password) + 1);
	if (!Password)
	{
		cout << "Memory Error" << endl;
	}
	strcpy(Password, password);
	Type = new char(strlen(type) + 1);
	if (!Type)
	{
		cout << "Memory Error" << endl;
	}
	strcpy(Type, type);
	Score = 0;
	Victory_League = 0;
	Score_Bronze_VS_computer = 0;
	Score_Silver_VS_computer = 0;
	Score_Gold_VS_computer = 0;
}

char* Player::Get_User_Name()
{
	return User_Name;
}

char* Player::Get_Password()
{
	return Password;
}

char* Player::Get_Type()
{
	return Type;
}

long Player::Get_Score()
{
	return Score;
}

int Player::Get_Victory_League()
{
	return Victory_League;
}

int Player::Get_Score_Bronze_VS_computer()
{
	return Score_Bronze_VS_computer;
}

int Player::Get_Score_Silver_VS_computer()
{
	return Score_Silver_VS_computer;
}

int Player::Get_Score_Gold_VS_computer()
{
	return Score_Gold_VS_computer;
}
