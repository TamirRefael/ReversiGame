#pragma once
#include "Player.h"

class Dog : public Player
{
	public:
		Dog(char* User_Name, char* Password, char* Type) :Player(User_Name, Password, Type)
		{

		};
};