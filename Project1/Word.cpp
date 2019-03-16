#include "Word.h"


Word::Word()
{
	word = "\0";
}

Word::Word(string wordin)
{
	word = wordin;
}

//获取单词首字母
char Word::getHead()
{
	char head = word[0];
	return head;
}

//获取单词尾字母
char Word::getTail()
{
	char tail = word[word.length() - 1];
	return tail;
}

// 获取单词长度
int Word::getLen()
{
	int len = word.length();
	return len;
}

//获取单词字符串
string Word::getWord()
{
	return this->word;
}

Word::~Word()
{
}
