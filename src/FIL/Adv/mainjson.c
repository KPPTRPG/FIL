#include <KPP/FIL/Adv.h>
#include <KPP/Log.h>
#include <KPP/TokMgr.h>

static KPP_TokMgr toksjson[1], toksadv[1];

int main(int argc, const char** argv) {
	for(int i = 1; i < argc; i++) {
		KPP_printf("%s\n", argv[i]);
	}

	FIL_AdvJsonQuery query[1] = {0, };
	FIL_Adv adv[1] = {0, };

	{
		FILE* file = fopen(argv[1], "r");
		if(file) {
			KPP_TokMgrInit(toksjson, file);
			fclose(file);
		} else {
			puts("No JSON Query file specified.");
			puts("Example of Json Query be like:\n\n");
			FIL_AdvJsonQueryPrt(
					query
					, stdout
					);

			puts("\n\n");
		}
	}

	{
		FILE* file = fopen(argv[2], "r");
		if(file) {
			KPP_TokMgrInit(toksadv, file);
			fclose(file);
		} else {
			puts("No Adv Query file specified.");
			puts("Example of Adv Query be like:\n\n");

			FIL_AdvPrt(adv, stdout);
			puts("\n\n");
		}
	}

	FIL_AdvInit(adv
			, toksadv->tokc
			, toksadv->tokv
			);

	FIL_AdvJsonQueryMk(
			query
			, toksjson->tokc
			, toksjson->tokv
			);

	FIL_AdvJson(adv, stdout, query);

	return 0;
}
