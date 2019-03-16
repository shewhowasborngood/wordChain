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
	// ��ʼ����������
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
	if (assignhead) // ָ��ͷ��ĸ
	{
		result.Copy(getwordchain(wordlist, headchar));
		result.resShow();
	}
	else   // �������
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
	//�ݹ���ֹ����Ϊ��
	//1���ҵ���Ҫ���β�������
	if (assigntail)
	{
		if (lasttail == tailchar)
		{
			return result;
		}
	}
	//2������Ϊ�յ����
	if (list.size() == 0)
	{
		return result;
	}
	//3��������û�з���Ҫ��ĵ���
	// �ݹ��ҿ����ӵĵ���
	for (int i = 0; i < list.size(); i++)
	{
		Word w = list.find(i);
		if (w.getHead() == lasttail || lasttail == '\0')
		{
			//����ҵ��˿����ӵ��ʣ���������ɾ���õ��ʣ�Ȼ����ʣ�µ�����ɵ��������еݹ��������ʴ�
			List<Word> sublist = list;
			sublist.remove(w);
			//���������е��������
			List<Word> subresult = getwordchain(sublist, w.getTail());
			//�Ƚϲ��ҵ��������
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
	//����������������������������ڣ����ؿ�����
	return result;
}


Wordlist::~Wordlist()
{
}
