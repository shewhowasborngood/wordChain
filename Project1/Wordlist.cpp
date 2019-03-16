#include <cstdlib>
#include "Wordlist.h"


Wordlist::Wordlist()
{
}
void Wordlist::SetWordlist(char list[256][256], int count, bool wordcount, bool charcount, bool assignhead, bool assigntail, bool allowring, char headchar, char tailchar)
{
	this->wordcount = wordcount;
	this->charcount = charcount;
	this->assignhead = assignhead;
	this->assigntail = assigntail;
	this->allowring = allowring;
	this->headchar = headchar;
	this->tailchar = tailchar;
	// 初始化单词链表
	for (int i = 0; i < count; i++)
	{
		Word t = Word(list[i]);
		wordlist.add(t);
	}
	//wordlist.show();
}

void Wordlist::checkring(List<Word> list)
{
	for (int i = 0; i < list.size(); i++)
	{
		for (int j = 0; j < list.size(); j++)
		{
			if (list.find(i).getHead() == list.find(j).getTail())
			{
				cout << "err: find ring!!" << endl;
				exit(0);
			}
		}
	}
}

void Wordlist::genchain()
{
	if (assignhead) // 指定头字母
	{
		result.Copy(getwordchain(wordlist, headchar));
		result.resShow();
	}
	else   // 常规情况
	{
		result.Copy(getwordchain(wordlist, '\0'));
		result.resShow();
	}
}

List<Word> Wordlist::getResult()
{
	return result;
}

List<Word> Wordlist::getwordchain(List<Word> list, char lasttail) {
	int best = 0;
	List<Word> result;
	//递归终止条件为：
	//1、找到了要求的尾部的情况
	if (assigntail)
	{
		if (lasttail == tailchar)
		{
			return result;
		}
	}
	//2、子链为空的情况
	if (list.size() == 0)
	{
		return result;
	}
	//3、子链中没有符合要求的单词
	// 递归找可连接的单词
	for (int i = 0; i < list.size(); i++)
	{
		Word w = list.find(i);
		if (w.getHead() == lasttail || lasttail == '\0')
		{
			//如果找到了可连接单词，在链表中删除该单词，然后在剩下单词组成的新链表中递归查找最长单词串
			List<Word> sublist = list;
			sublist.remove(w);
			//找子链表中的最大子链
			List<Word> subresult = getwordchain(sublist, w.getTail());
			//比较并找到最大子链
			subresult.add(w);
			if (wordcount)
			{
				if (subresult.size() > best)
				{
					best = subresult.size();
					result.Copy(subresult);
				}
			}
			else if (charcount)
			{
				if (subresult.getcharcount() > best)
				{
					best = subresult.getcharcount();
					result.Copy(subresult);
				}
			}
			else
			{
				cout << "error -w/-c not declared" << endl;
				exit(0);
			}
		}
	}
	if (!allowring)
	{
		checkring(result);
	}
	//返回最大子链，如果最大子链不存在，返回空链表
	return result;
}


Wordlist::~Wordlist()
{
}
