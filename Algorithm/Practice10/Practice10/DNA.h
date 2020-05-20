#pragma once
#include <iostream>
#include <string>

using namespace std;

class DNA
{
private:
	string str;
	int number;

public:
	DNA(string str, int number)
	{
		this->str = str;
		this->number = number;
	}

	string get_String();
	string get_String(int number);

	int get_Number();
	int get_Number(string str);

};