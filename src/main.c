/*
 ============================================================================
 Name        : ExtensionCorrecter.c
 Author      : Tanguy Poret
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*******************************************************
*** This program permit to automaticaly rename files
*** according to their types. It detect only image files.
*** TO-DO:
*** -Detect file type -DONE
*** -Rename it according to type detected
*** -Check if it does not have an extension -PARTIALY DONE
*** -add launch options:
***     -force file detection (check even if it has an
***     extension) by argv or by command
***     -if argv contains file name, only check the file
***     -if argv contains folder name, check folder only
********************************************************/


#include <stdio.h>
#include <stdlib.h>

#include "pathUtility.h"

#define TEST_PATH "C:\\Users\\Tanguy\\Pictures\\Appareil\\2014-03-11\\testFile.gif"

int main(int argc, char* argv[])
{
	/*
	tinydir_file file;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: test filename\n");
		return 1;
	}
	if (tinydir_file_open(&file, argv[1]) == -1)
	{
		perror("Error opening file");
		return 1;
	}
	printf("Path: %s\nName: %s\nExtension: %s\nIs dir? %s\nIs regular file? %s\n",
		   file.path, file.name, file.extension,
		   file.is_dir?"yes":"no", file.is_reg?"yes":"no");
	*/

	tinydir_dir dir;
	tinydir_open(&dir, argv[1]);

	while (dir.has_next)
	{
	    tinydir_file file;
	    tinydir_readfile(&dir, &file);

	    printf("%s", file.name);
	    if (file.is_dir)
	    {
	        printf("/");
	    }
	    printf("\n");

	    tinydir_next(&dir);
	}

	tinydir_close(&dir);

	system("PAUSE");

	return EXIT_SUCCESS;
}
