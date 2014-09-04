#include "error.h"
#include <stdio.h>
#include <time.h>

static unsigned char streamOpened = 0;

void errorInitStream(void)
{
	if (!streamOpened)
	{
		freopen("logExtCorr.txt", "a", stderr);
		streamOpened = 1;
	}
}

void closeErrorStream(void)
{
	if (streamOpened)
		fclose(stderr);
}

void addError(const char* str)
{
	time_t rawtime;
	struct tm* timeinfo;

	if (!streamOpened)
	{
		errorInitStream();
		streamOpened = 1;
	}
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	fprintf(stderr, "%s\n", asctime(timeinfo));
	fprintf(stderr, "An error occured: ");
	fputs(str, stderr);
}