#include "Word.h"


Word::Word()
{
	word = "\0";
}

Word::Word(string wordin)
{
	word = wordin;
}

//��ȡ��������ĸ
char Word::getHead()
{
	char head = word[0];
	return head;
}

//��ȡ����β��ĸ
char Word::getTail()
{
	char tail = word[word.length() - 1];
	return tail;
}

// ��ȡ���ʳ���
int Word::getLen()
{
	int len = word.length();
	return len;
}

//��ȡ�����ַ���
string Word::getWord()
{
	return this->word;
}

Word::~Word()
{
}
