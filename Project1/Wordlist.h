#pragma once
#include "List.h"
#include "Word.h"

class Wordlist
{
public:
	Wordlist();
	void SetWordlist(char list[256][256], int count, bool wordcount, bool charcount, bool assignhead, bool assigntail, bool allowring, char headchar, char tailchar);
	void genchain();
	List<Word> getResult();
	~Wordlist();
private:
	void checkring(List<Word> list);
	List<Word> getwordchain(List<Word> list, char lasttail);
	List<Word> wordlist;
	List<Word> result;
	bool wordcount = false;
	bool charcount = false;
	bool assignhead = false;
	bool assigntail = false;
	bool allowring = false;
	char headchar;
	char tailchar;
};

