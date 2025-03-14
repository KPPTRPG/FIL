#include <KPP/TokMgr.h>
#include <string.h>
#include <KPP/Log.h>

ae2f_SHAREDEXPORT
int KPP_TokMgrInit(
		KPP_TokMgr* mgr,
		FILE* istream
		) 
{
	if(!mgr) {
		KPP_puts("KPP_TokMgrInit mgr is NULL\n");
		return -1;

	}
	if(!istream) 
	{
		KPP_puts("KPP_TokMgrInit istream is NULL\n");
		return -2;
	}

	int rdc;
	if((rdc = fread(
					mgr->mem
					, 1
					, KPP_TOKML
					, istream
					)) > KPP_TOKML || rdc < 0)
	{
		KPP_puts("KPP_TokMgrInit fread has failed\n");
		return -3;
	}

	mgr->mem[rdc - 1] = 0;
	KPP_printf(
			"Read count: %d\n"
			"Read value: %s\n\n"
			, rdc
			, mgr->mem
			);
	char* tok = mgr->mem;
	int i = 1, toklen = 0;
	char* del = 0;


	mgr->tokv[0] = mgr->mem;
	
	for(
			strtok(
				tok
				, " \n\t\r"
				);
			(i < KPP_TOKC) && tok && *tok && (tok = strtok(
					NULL
					, " \n\t\r")
				);
			i++)
	{
		toklen = strlen(tok);

		if(!del) 
			mgr->tokv[i] = tok;
		else
		{
			KPP_printf(
					"del is registered. %s\n"
					"last token char: %c[%d]\n"

					, tok
					, tok[toklen - 1]
					, tok[toklen - 1]
					);

			for(char* t = tok - 1; t >= mgr->mem && !*t; t--)
				*t = ' ';

			if(tok[toklen - 1] != *del)
			{
				i--;
			}

			else 
			{
				KPP_puts("del is done. escaping...\n");
				tok[toklen - 1] = 0;
				del = 0;
			}

			continue;
		}
		KPP_printf("Trial %d, \n%s\n", i, tok);

		switch(*tok) {
			;
			case '\"':
			case '\'':
			{
				del = tok;
				mgr->tokv[i] = tok + 1;

				KPP_printf(
						"Got \", Token migrating\n%s\n"
						, tok + 1
						);

				if(tok[toklen - 1] == *del)
				{
					KPP_puts("Nevermind. We got him\n");
					tok[toklen - 1] = 0;
					del = 0;
					break;
				}

				i--;
			} default: break;
		}
	}

IMOUTIEHERE:

	if(!mgr->tokv[i - 1]) i--;
	mgr->tokc = i;

	return 0;
}
