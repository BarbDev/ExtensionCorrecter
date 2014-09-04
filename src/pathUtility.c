/*
 * pathUtility.c
 *
 *  Created on: 11 août 2014
 *      Author: Tanguy
 */

#include "pathUtility.h"

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

void addFileExtension(char ** file, const char * type)
{
	char* realloc_ptr = NULL;
	
	realloc_ptr = realloc(*file, sizeof(char)* (strlen(*file) + strlen(type) + 1));
	if (realloc_ptr == NULL)
	{
		errorInitStream();
		perror("Failed to reallocate memory.");
		free(*file);
		*file = NULL;
		return;
	}
	*file = realloc_ptr;
	strcat(*file, type);
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

const char* getFileTypeFromFile(const char * file)
{
	FILE* fileOpened = fopen(file, "r");
	char buffer[ID_SIZE] = {""};
	size_t i = 0, j = 0;
	unsigned char occurences = 0;
	char c = 0;

	if (fileOpened == NULL) exit(1);

	if (fread(buffer, sizeof(char), ID_SIZE, fileOpened) != ID_SIZE) exit(1); //reading error

	if (fileOpened != NULL) { fclose(fileOpened); fileOpened = NULL; }

	for (i = 0; i < global_ExtsCollSize; i++)
	{
		for (j = 0; j < ID_SIZE; j++)
		{
			c = global_ExtsCollection[i].id[j];
			if (c == buffer[j])
				occurences++;
			if (c == 0)
				occurences++;
		}
		if (occurences == ID_SIZE) return global_ExtsCollection[i].type;
		else if (occurences < ID_SIZE && occurences > 0) occurences = 0;
	}
	return "error";
}

const char* getFileTypeFromExtension(const char * extension)
{
	size_t i = 0;
	for (i = 0; i < global_ExtsCollSize; i++)
	{
		if (strcmp(global_ExtsCollection[i].type, extension) == 0)
			return global_ExtsCollection[i].type;
	}

	return "error";
}
