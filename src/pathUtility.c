/*
 * pathUtility.c
 *
 *  Created on: 11 ao�t 2014
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

void addFileExtension(char ** file, FileType const type)
{
	char* realloc_ptr = NULL;
	switch (type) {
		case JPG1:
		case JPG2:
			realloc_ptr = realloc(*file, sizeof(char) * (strlen(*file) + strlen(".jpg") + 1));
			if (realloc_ptr == NULL)
			{
				perror("Failed to reallocate memory.");
				free(*file);
				*file = NULL;
				return;
			}
			*file = realloc_ptr;
			strcat(*file, ".jpg");
			break;
		case PNG:
			realloc_ptr = realloc(*file, sizeof(char)* (strlen(*file) + strlen(".png") + 1));
			if (realloc_ptr == NULL)
			{
				perror("Failed to reallocate memory.");
				free(*file);
				*file = NULL;
				return;
			}
			*file = realloc_ptr;
			strcat(*file, ".png");
			break;
		case BMP:
			realloc_ptr = realloc(*file, sizeof(char)* (strlen(*file) + strlen(".bmp") + 1));
			if (realloc_ptr == NULL)
			{
				perror("Failed to reallocate memory.");
				free(*file);
				*file = NULL;
				return;
			}
			*file = realloc_ptr;
			strcat(*file, ".bmp");
			break;
		case GIF:
			realloc_ptr = realloc(*file, sizeof(char)* (strlen(*file) + strlen(".gif") + 1));
			if (realloc_ptr == NULL)
			{
				perror("Failed to reallocate memory.");
				free(*file);
				*file = NULL;
				return;
			}
			*file = realloc_ptr;
			strcat(*file, ".gif");
			break;
		case TIFF1:
		case TIFF2:
			realloc_ptr = realloc(*file, sizeof(char)* (strlen(*file) + strlen(".tiff") + 1));
			if (realloc_ptr == NULL)
			{
				perror("Failed to reallocate memory.");
				free(*file);
				*file = NULL;
				return;
			}
			*file = realloc_ptr;
			strcat(*file, ".tiff");
			break;
		default:
			// Error: file type not handle
			puts("Error: AddExtension - type not handled.\n");
			break;
	}
}

unsigned char fileExists(const char * file)
{
	FILE* fileE = NULL;
	
	fileE = fopen(file, "r");

	if (fileE != NULL)
	{
		fclose(fileE);	fileE = NULL;
		return 1;
	}
	return 0;
}

FileType getFileTypeFromFile(const char * file)
{
	FILE* fileOpened = fopen(file, "r");
	char buffer[4] = {""};
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
