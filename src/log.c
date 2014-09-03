#include "log.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static unsigned int nbeFilesModified = 0;
static unsigned int nbeFilesFailed = 0;
static unsigned int nbeFilesParsed = 0;
static unsigned int nbeDirParsed = 0;
static unsigned int nbeDirFailed = 0;
static char** listModif = NULL;
static char** listFail = NULL;

void incrementDirParsed(void)
{
	nbeDirParsed++;
}

void incrementDirFailed(void)
{
	nbeDirFailed++;
}

void incrementFilesParsed(void)
{
	nbeFilesParsed++;
}

unsigned int getNbeDirParsed(void)
{
	return nbeDirParsed;
}

unsigned int getNbeDirFailed(void)
{
	return nbeDirFailed;
}

unsigned int getNbeFilesParsed(void)
{
	return nbeFilesParsed;
}

unsigned int getNbeFilesModif(void)
{
	return nbeFilesModified;
}

unsigned int getNbeFilesFailed(void)
{
	return nbeFilesFailed;
}

void addFileToModif(const char* file)
{
	char** temp = NULL;
	if (listModif == NULL)
	{
		listModif = (char**)malloc(sizeof(listModif));
		if (listModif == NULL)
		{
			puts("Error: failed to allocate list modif.\n");
			return;
		}
		listModif[0] = (char*)malloc(sizeof(listModif[0]) * (strlen(file) + 1));
		if (listModif[0] == NULL)
		{
			puts("Error: failed to allocate list modif str.\n");
			free(listModif);
			return;
		}
		strcpy(listModif[0], file);
		nbeFilesModified++;
	}
	else
	{
		temp = (char**)realloc(listModif, sizeof(listModif) * (nbeFilesModified + 1));
		if (temp == NULL)
		{
			puts("Error: failed to reallocate list modif.\n");
			return;
		}
		listModif = temp;
		listModif[nbeFilesModified] = (char*)malloc(sizeof(listModif[nbeFilesModified]) * (strlen(file) + 1));
		if (listModif[nbeFilesModified] == NULL)
		{
			puts("Error: failed to reallocate list modif str.\n");
			return;
		}
		strcpy(listModif[nbeFilesModified], file);
		nbeFilesModified++;
	}
}

void addFileToFail(const char* file)
{
	char** temp = NULL;
	if (listFail == NULL)
	{
		listFail = (char**)malloc(sizeof(listFail));
		if (listFail == NULL)
		{
			puts("Error: failed to allocate list fail.\n");
			return;
		}
		listFail[0] = (char*)malloc(sizeof(listFail[0]) * (strlen(file) + 1));
		if (listFail[0] == NULL)
		{
			puts("Error: failed to allocate list fail str.\n");
			free(listFail);
			return;
		}
		strcpy(listFail[0], file);
		nbeFilesFailed++;
	}
	else
	{
		temp = (char**)realloc(listFail, sizeof(listFail) * (nbeFilesFailed + 1));
		if (temp == NULL)
		{
			puts("Error: failed to reallocate list fail.\n");
			return;
		}
		listFail = temp;
		listFail[nbeFilesFailed] = (char*)malloc(sizeof(listFail[nbeFilesFailed]) * (strlen(file) + 1));
		if (listFail[nbeFilesFailed] == NULL)
		{
			puts("Error: failed to reallocate list fail str.\n");
			return;
		}
		strcpy(listFail[nbeFilesFailed], file);
		nbeFilesFailed++;
	}
}

void freeLists(void)
{
	size_t i = 0, j = 0;
	if (listModif != NULL)
	{
		for (i = 0; i < nbeFilesModified; i++)
		{
			free(listModif[i]);
		}
		free(listModif);
	}
	if (listFail != NULL)
	{
		for (i = 0; i < nbeFilesFailed; i++)
		{
			free(listFail[i]);
		}
		free(listFail);
	}
}

void printModifList(void)
{
	size_t i = 0;
	if (listModif != NULL)
	{
		puts("FILES MODIFIED:\n");
		for (i = 0; i < nbeFilesModified; i++)
		{
			puts(listModif[i]);
			puts("\n");
		}
		puts("END OF FILES MODIFIED\n");
	}
	//printf("Number of files modified: %d\n", nbeFilesModified);
}

void clearConsoleBuffer(void)
{
	char c = 0;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

char getInputCh(void)
{
	char c = 0;
	c = getchar();
	clearConsoleBuffer();
	return c;
}

void displayProgress(const char* currDir, const char* currFile)
{
	static unsigned char i = 0;
	char parseSymbole[] = { '|', '/', '-', '\\' };
#ifdef WIN32
	system("cls");
#else
	system("clear");
#endif
	flushall();
	printf("Processing %c%c%c\n", parseSymbole[i], parseSymbole[i], parseSymbole[i]);
	i++; if (i > 3) i = 0;
	printf("Number of files parsed: %d\n", nbeFilesParsed);
	printf("Number of files modified: %d\n", nbeFilesModified);
	printf("Number of files failed: %d\n", nbeFilesFailed);
	printf("Number of directory parsed: %d\n", nbeDirParsed);
	printf("Number of directory failed: %d\n", nbeDirFailed);
	printf("\nCurrent dir parsed: %s\n", currDir);
	printf("Current file parsed: %s\n", currFile);
}