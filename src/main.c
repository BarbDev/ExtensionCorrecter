/*
 ============================================================================
 Name        : ExtensionCorrecter.c
 Author      : Tanguy Poret
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "pathUtility.h"

#define TEST_PATH "C:\\Users\\Tanguy\\Pictures\\Appareil\\2014-03-11\\testFile.gif"

int main(int argc, char* argv[]) {
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
	if (tinydir_open(&dir, ".") == -1) {
		perror("Error opening file");
		goto bail;
	}
	while (dir.has_next) {
		tinydir_file file;
		if (tinydir_readfile(&dir, &file) == -1) {
			perror("Error getting file");
			goto bail;
		}
		printf("%s", file.name);
		if (file.is_dir) {
			printf("/");
		}
		printf("\n");
		tinydir_next(&dir);
	}

	bail: tinydir_close(&dir);

	system("PAUSE");

	return EXIT_SUCCESS;
}
