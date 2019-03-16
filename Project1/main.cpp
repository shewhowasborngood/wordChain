#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <Windows.h>
#include "Wordlist.h"
using namespace std;

//获取exe文件路径
string GetProgramDir()
{
	char exeFullPath[MAX_PATH]; // Full path
	string strPath = "";

	GetModuleFileName(NULL, exeFullPath, MAX_PATH);
	strPath = (string)exeFullPath;    // Get full path of the file
	int pos = strPath.find_last_of('\\', strPath.length());
	return strPath.substr(0, pos);  // Return the directory without the file name
}

int main(int argc, char *argv[])
{
	bool wordcount = false;
	bool charcount = false;
	bool assignhead = false;
	bool assigntail = false;
	bool allowring = false;

	char headchar = '\0';
	char tailchar = '\0';

	// 处理命令行参数
	for (int i = 1; i < argc - 1; i++)
	{
		printf("%s\n", argv[i]);
		if (strcmp(argv[i], "-w") == 0)
		{
			wordcount = true;
		}
		else if (strcmp(argv[i], "-c") == 0)
		{
			charcount = true;
		}
		else if (strcmp(argv[i], "-h") == 0)
		{
			assignhead = true;
			if (i + 1 < argc - 1)
			{
				headchar = argv[i + 1][0];
				i++;
			}
			else
			{
				cout << "error " << endl;
				return 0;
			}
		}
		else if (strcmp(argv[i], "-t") == 0)
		{
			assigntail = true;
			if (i + 1 < argc - 1)
			{
				tailchar = argv[i + 1][0];
				i++;
			}
			else
			{
				cout << "error " << endl;
				return 0;
			}
		}
		else if (strcmp(argv[i], "-r") == 0)
		{
			allowring = true;
		}
	}

	//读取文件内容
	ifstream in(argv[argc - 1]);
	if (!in.is_open())
	{
		cout << "Error opening file"; exit(1);
	}
	int count = 0;
	char words[256][256];
	while (!in.eof())
	{
		in.getline(words[count], 200);
		// 转换大小写
		for (int j = 0; j < sizeof(words[count]); j++)
		{
			if (words[count][j] <= 'Z' && words[count][j] >= 'A')
				words[count][j] = words[count][j] + 'a' - 'A';
		}
		count++;
	}

	Wordlist wlist;
	wlist.SetWordlist(words, count, wordcount, charcount, assignhead, assigntail, allowring, headchar, tailchar);
	wlist.genchain();
	List<Word> res = wlist.getResult();
	string str = GetProgramDir();
	ofstream fout(str.append("\\Solution.txt"));
	for (int i = res.size() - 1; i >= 0; i--)
	{
		fout << res.find(i).getWord() << endl;
	}
	fout.close();
	return 0;
}