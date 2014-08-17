/*
 * pathUtility.c
 *
 *  Created on: 11 août 2014
 *      Author: Tanguy
 */

#include "pathUtility.h"

/*
char* getFileExtensionPtr(const char const * file)
{
	return PathFindExtensionA(file);
}
*/

char* getFileName(const char * file)
{
	int count = 0;
	const char* c = file + strlen(file);
	char* name = NULL;

	// Search the first '\\' or '/' occurence from the end
	do {	c--;	if (*c == '\\') break;	if (*c == '/') break;	count++;	} while (1);

	name = malloc(sizeof(char) * count + 1);
	if (name == NULL) exit(1);

	strcpy(name, file + (strlen(file) - count));

	return name;
}

char* addFileExtension(const char * file, FileType const type)
{
	char* corrected = NULL;

	switch (type) {
		case JPG1:
		case JPG2:
			corrected = malloc(sizeof(char) * strlen(file) + strlen(".jpg") + 1);
			if (corrected == NULL) exit(1);
			strcpy(corrected, file);
			strcat(corrected, ".jpg");
			return corrected;
		case PNG:
			corrected = malloc(sizeof(char) * strlen(file) + strlen(".png") + 1);
			if (corrected == NULL) exit(1);
			strcpy(corrected, file);
			strcat(corrected, ".png");
			return corrected;
		case BMP:
			corrected = malloc(sizeof(char) * strlen(file) + strlen(".bmp") + 1);
			if (corrected == NULL) exit(1);
			strcpy(corrected, file);
			strcat(corrected, ".bmp");
			return corrected;
		case GIF:
			corrected = malloc(sizeof(char) * strlen(file) + strlen(".gif") + 1);
			if (corrected == NULL) exit(1);
			strcpy(corrected, file);
			strcat(corrected, ".gif");
			return corrected;
		case TIFF1:
		case TIFF2:
			corrected = malloc(sizeof(char) * strlen(file) + strlen(".tiff") + 1);
			if (corrected == NULL) exit(1);
			strcpy(corrected, file);
			strcat(corrected, ".tiff");
			return corrected;
		default:
			// Error: file type not handle
			break;
	}

	return NULL;
}

FileType getFileTypeFromFile(const char * file)
{
	FILE* fileOpened = fopen(file, "r");
	char buffer[4] = {};
	int i = 0, j = 0;
	unsigned char occurences = 0;

	if (fileOpened == NULL) exit(1);

	if (fread(buffer, sizeof(char), 4, fileOpened) != 4) exit(1); //reading error

	if (fileOpened != NULL) { fclose(fileOpened); fileOpened = NULL; }

	for (i = 0; i < FILETYPE_COUNT; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (FileTags[i][j] == buffer[j])
				occurences++;
			if (FileTags[i][j] == 0)
				occurences++;
		}
		if (occurences == 4) return i;
		else if (occurences < 4 && occurences > 0) occurences = 0;
	}
	return FILETYPE_COUNT;
}

FileType getFileTypeFromExtension(const char * extension)
{
	if (strcmp(extension, ".jpg") == 0 || strcmp(extension, ".jpeg") == 0)
		return JPG1;
	else if (strcmp(extension, ".png") == 0)
		return PNG;
	else if (strcmp(extension, ".gif") == 0)
		return GIF;
	else if (strcmp(extension, ".bmp") == 0)
		return BMP;
	else if (strcmp(extension, ".tiff") == 0)
		return TIFF1;

	return FILETYPE_COUNT;
}

/*
unsigned char isDirectory(const char const * path)
{
	return PathIsDirectoryA(path) == FALSE ? 0 : 1;
}

unsigned char hasExtension(const char const * file)
{
	return PathFindExtensionA(file) == NULL ? 0 : 1;
}

unsigned char fileExists(const char const * path)
{
	return PathFileExists(path) == TRUE ? 1 : 0;
}
*/
