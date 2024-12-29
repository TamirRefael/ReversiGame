#pragma once
#include "Player.h"

class Locust : public Player
{
public:
	Locust(char* User_Name, char* Password, char* Type) :Player(User_Name, Password, Type)
	{

	};
};