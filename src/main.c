/*
 ============================================================================
 Name        : ExtensionCorrecter.c
 Author      : Tanguy Poret
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#ifdef _DEBUG
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include "correcter.h"

int main(int argc, char* argv[]) {
	unsigned char i = 0, parameters = 0, foundPath = 0;

#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(64);
#endif

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
		correctDir(".", NON_AGRESSIVE | REMOVE_UNUSED_EXT);
	else if(argc > 1)
	{
		if (argc > 8)
		{
			puts("Too much parameters.");
			puts("\nPress Enter to exit.");
			getchar();
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
				puts("HELP:\n\nCommands available:\n");
				puts("\t-agressive: even check files with an extension and\n\tadd the corresponding one.\n");
				puts("\t-nonAgressive: check files without extension and add\n\tthe corresponding one.\n");
				puts("\t-allSubDir: correct files of current directory and his sub directory.\n");
				puts("\t-onlySubDir: correct only files of sub directory of directory.\n");
				puts("\t-removeExts: Will make sure that files name does\n\tnot contains multiple extension.\n");
				puts("Default commands are: -nonAgressive -removeExts\n\n");
				puts("If you want to specify a path to correct, it MUST be put before any commands.\nExample: [path] -cmd -cmd...\n");
				puts("Please relaunch the application, it will close when you press Enter.");
				getchar();
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

	puts("\nPress Enter to exit.");
	getchar();

	return EXIT_SUCCESS;
}
