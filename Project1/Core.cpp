
#include "stdafx.h"
#include "Core.h"
#include "List.h"


/*BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}*/

Core::Core()
{
}

int Core::gen_chain_word(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{
	char word[256][256];
	for (int i = 0; i < len; i++)
	{
		strcpy_s(word[i], words[i]);
	}
	Wordlist::SetWordlist(word, len, true, false, head == 0 ? false : true, tail == 0 ? false : true, enable_loop, head, tail);
	Wordlist::genchain();
	List<Word> res = Wordlist::getResult();
	for (int i = res.size() - 1; i >= 0; i--)
	{
		strcpy_s(result[i], 256, res.find(i).getWord().data());
	}
	return res.size();
}

int Core::gen_chain_char(char* words[], int len, char* result[], char head, char tail, bool enable_loop)
{
	char word[256][256];
	for (int i = 0; i < len; i++)
	{
		strcpy_s(word[i], words[i]);
	}
	Wordlist::SetWordlist(word, len, false, true, head == 0 ? false : true, tail == 0 ? false : true, enable_loop, head, tail);
	Wordlist::genchain();
	List<Word> res = Wordlist::getResult();
	for (int i = res.size() - 1; i >= 0; i--)
	{
		strcpy_s(result[i], 256, res.find(i).getWord().data());
	}
	return res.getcharcount();
}

Core::~Core()
{
}
