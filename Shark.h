#pragma once
#include "Player.h"

class Shark : public Player
{
public:
	Shark(char* User_Name, char* Password, char* Type) :Player(User_Name, Password, Type)
	{

	};
};