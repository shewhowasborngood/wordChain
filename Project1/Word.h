#pragma once
#include <iostream>
#include <string>
using namespace std;

class Word
{
public:
	Word();
	Word(string wordin);
	char getHead();
	char getTail();
	int getLen();
	string getWord();
	~Word();
private:
	string word;
};

