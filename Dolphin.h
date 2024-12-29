#pragma once
#include "Player.h"

class Dolphin : public Player
{
	public:
		Dolphin(char* User_Name, char* Password, char* Type) :Player(User_Name, Password, Type)
		{

		};
};