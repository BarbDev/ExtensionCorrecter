#ifdef _DEBUG
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include "correcter.h"
#include "log.h"
#include "error.h"
#include "constantes.h"

void displayMenu(void);
void displayHelp(void);
unsigned char updateChoice(void);

int main(int argc, char* argv[]) {
	unsigned char i = 0, parameters = 0, foundPath = 0;

#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(64);
#endif

	atexit(freeLists);
	atexit(closeErrorStream);

	// We get the path from where the app is launched
	strcpy(global_launchPath, argv[0]);
	for (i = strlen(global_launchPath); i > 0; i--)
	{
		if (global_launchPath[i] == '\\' || global_launchPath[i] == '/')
		{
			global_launchPath[i] = '\0';
			break;
		}
	}

	if (argc == 1)
	{
		displayMenu();
		parameters = updateChoice();
		correctDir(global_launchPath, parameters);
	}
	else if(argc > 1)
	{
		if (argc > 8)
		{
			puts("Too much parameters.");
			puts("\nPress Enter to exit.");
			clearConsoleBuffer();
			return EXIT_FAILURE;
		}
		for (i = 0; i < argc; i++)
		{
			if (strcmp(argv[i], "-agressive") == 0)
				parameters |= AGRESSIVE;
			else if (strcmp(argv[i], "-nonAgressive") == 0)
				parameters |= NON_AGRESSIVE;
			else if (strcmp(argv[i], "-allSubDir") == 0)
				parameters |= ALL_SUB_DIR;
			else if (strcmp(argv[i], "-onlySubDir") == 0)
				parameters |= ONLY_SUB_DIR;
			else if (strcmp(argv[i], "-removeExts") == 0)
				parameters |= REMOVE_UNUSED_EXT;
			else if (strcmp(argv[i], "-help") == 0)
			{
				displayHelp();
				puts("Please relaunch the application, it will close when you press Enter.");
				clearConsoleBuffer();
				return EXIT_SUCCESS;
			}
			else if (i == 1) // string wasn't a parameter so we assume it's a path
				foundPath = 1;
		}
		if (foundPath)
			correctDir(argv[1], parameters);
		else
			correctDir(global_launchPath, parameters);
	}

	printModifList();
	getNbeDirParsed();
	getNbeFilesModif();

	puts("\nPress Enter to exit.");
	clearConsoleBuffer();

	return EXIT_SUCCESS;
}

void displayMenu(void)
{
	puts("Make your choice:\n");
	puts("1.Non agressive");
	puts("2.Agressive");
	puts("3.All sub directory");
	puts("4.Only sub directory");
	puts("5.Remove unused extension");
	puts("6.Help");
	puts("9.Start");
}

void displayHelp(void)
{
	puts("HELP:\n\nCommands available:\n");
	puts("\t-agressive: even check files with an extension and\n\tadd the corresponding one.");
	puts("\t-nonAgressive: check files without extension and add\n\tthe corresponding one.");
	puts("\t-allSubDir: correct files of current directory and his sub directory.");
	puts("\t-onlySubDir: correct only files of sub directory of directory.");
	puts("\t-removeExts: Will make sure that files name does\n\tnot contains multiple extension.");
	puts("Default commands are: -nonAgressive -removeExts\n");
	puts("If you want to specify a path to correct, it MUST be put before any commands.\nExample: [path] -cmd -cmd...");
}

unsigned char updateChoice(void)
{
	static unsigned char choice = 0;
	char c = 0;

	do
	{
		c = getInputCh();
		if (c == '1')
			choice |= NON_AGRESSIVE;
		else if (c == '2')
			choice |= AGRESSIVE;
		else if (c == '3')
			choice |= ALL_SUB_DIR;
		else if (c == '4')
			choice |= ONLY_SUB_DIR;
		else if (c == '5')
			choice |= REMOVE_UNUSED_EXT;
		else if (c == '6')
			displayHelp();

		puts("Current choice:");
		if (choice & NON_AGRESSIVE)
			puts(" non agressive");
		if (choice & AGRESSIVE)
			puts(" agressive");
		if (choice & ALL_SUB_DIR)
			puts(" all sub dir");
		if (choice & ONLY_SUB_DIR)
			puts(" only sub dir");
		if (choice & REMOVE_UNUSED_EXT)
			puts(" remove unused ext");
	} while (c != '9');

	return choice;
}