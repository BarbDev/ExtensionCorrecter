#include "error.h"
#include <stdio.h>
#include <time.h>

static unsigned char streamOpened = 0;

void closeErrorStream(void)
{
	if (streamOpened)
		fclose(stderr);
}

static void errorInitStream(void)
{
	freopen("logExtCorr.txt", "a", stderr);
}

void addError(const char* str)
{
	time_t rawtime;
	struct tm* timeinfo;

	if (!streamOpened)
		errorInitStream();
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	fprintf(stderr, "%s\n", asctime(timeinfo));
	fprintf(stderr, "An error occured: ");
	fputs(str, stderr);
}