#pragma once
/*
#ifdef DLL1_EXPORTS
#define DLL1_API __declspec(dllexport)
#else
#define DLL1_API __declspec(dllimport)
#endif
*/
#include "Wordlist.h"

// class DLL1_API Core :
class Core :
	public Wordlist
{
public:
	Core();
	int gen_chain_word(char * words[], int len, char * result[], char head, char tail, bool enable_loop);
	int gen_chain_char(char * words[], int len, char * result[], char head, char tail, bool enable_loop);
	~Core();
};
/*
extern DLL1_API int ndll1;

DLL1_API int fndll1(void);
*/

