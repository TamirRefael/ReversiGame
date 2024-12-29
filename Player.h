#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
using namespace std;

class Player
{
	protected:
		char* User_Name;
		char* Password;
		char* Type;
		long Score;
		int Victory_League;
		int Score_Bronze_VS_computer;
		int Score_Silver_VS_computer;
		int Score_Gold_VS_computer;
	public:
		Player();
		Player(char* user_name, char* password, char* type);
		virtual char* Get_User_Name();
		virtual char* Get_Password();
		virtual char* Get_Type();
		virtual long Get_Score();
		virtual int Get_Victory_League();
		virtual int Get_Score_Bronze_VS_computer();
		virtual int Get_Score_Silver_VS_computer();
		virtual int Get_Score_Gold_VS_computer();
		Player& operator=(const Player& p);

};