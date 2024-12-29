#pragma once
#include "Player.h"

class Cat : public Player
{
public:
	Cat(char* User_Name, char* Password, char* Type) :Player(User_Name, Password, Type)
	{

	};
};