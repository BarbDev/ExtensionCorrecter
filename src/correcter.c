/*
 * correcter.c
 *
 *  Created on: 17 août 2014
 *      Author: Tanguy
 */

#include "correcter.h"
#include "pathUtility.h"
#include <stdio.h>
#include <stdlib.h>
#include "log.h"
#include "error.h"

static void deletesExts(char* file);
static void correctFile(const tinydir_file* file, unsigned char params);

void correctDir(const char * directory, unsigned char params)
{
	tinydir_dir dir;
	tinydir_file file;

	if (((params & NON_AGRESSIVE) && (params & AGRESSIVE)) || ((params & ALL_SUB_DIR) && (params & ONLY_SUB_DIR)))
	{
		if ((params & NON_AGRESSIVE) && (params & AGRESSIVE))
			addError("Got two uncompatible commands:\n\t-agressive -nonAgressive");
		if ((params & ALL_SUB_DIR) && (params & ONLY_SUB_DIR))
			addError("Got two uncompatible commands:\n\t-allSubDir -onlySubDir");
		return;
	}
	else
	{
		if (tinydir_open(&dir, directory) == -1)
		{
			errorInitStream();
			perror("Error opening directory");
			printf("%s\n", directory);
			return;
		}
		while (dir.has_next)
		{
			displayProgress(dir.path, file.name, params);
			if (tinydir_readfile(&dir, &file) == -1)
			{
				errorInitStream();
				perror("Error opening file");
				incrementDirFailed();
				tinydir_next(&dir);
				continue;
			}
			if (strcmp(file.name, ".") == 0 || strcmp(file.name, "..") == 0) // see if it's parent directory
			{
				tinydir_next(&dir);
				continue;
			}
			if (file.is_dir)
			{
				if ((params & ALL_SUB_DIR) || (params & ONLY_SUB_DIR))
				{
					correctDir(file.path, params);
					incrementDirParsed();
				}
			}
			else
			{
				incrementFilesParsed();
				if ((params & ONLY_SUB_DIR) && strcmp(dir.path, global_launchPath) == 0)
				{
					tinydir_next(&dir);
					continue;
				}
				// It is a file
				if ((params & NON_AGRESSIVE) && (file.extension != NULL)) // Has an extension: Jump to next file
				{
					tinydir_next(&dir);
					continue;
				}
				else if ((params & AGRESSIVE) && (file.extension != NULL)) // Has an extension: Force detection
				{
					correctFile(&file, params);
					addFileToModif(file.name);
					tinydir_next(&dir);
					continue;
				}
				if (file.extension[0] == '\0' || (strcmp(getFileTypeFromExtension(file.extension),"error") == 0 && strlen(file.extension) > 10)) // We assume that it isnt an extension
				{
					correctFile(&file, params);
					addFileToModif(file.name);
				}
			}
			tinydir_next(&dir);
		}
	}
}

static void deletesExts(char* file)
{
	/* Search for dot till it encounter the first '\\' or '/'
	When dot encountered, check if the extension is known*/
	int i = 0, charCount = 0;
	char extension[16] = { "" };

	for (i = strlen(file); i > 0; i--)
	{
		if (file[i] == '\\') return;
		else if (file[i] == '/') return;
		else if (file[i] == '.')
		{
			if (charCount > TYPE_SIZE)
			{
				addError("Couldn't suppress extension. Too long string.\n");
				return;
			}
			strncpy(extension, file + (strlen(file) - charCount - 1), charCount + 1);
			if (strcmp(getFileTypeFromExtension(extension), "error") != 0)
			{
				file[strlen(file) - charCount - 1] = '\0';
				charCount = 0;
			}
		}
		charCount++;
	}
}

static void correctFile(const tinydir_file* file, unsigned char params)
{
	char* temp = NULL;

	temp = malloc(sizeof(char)* strlen(file->path) + 1);
	strcpy(temp, file->path);

	if ((params & REMOVE_UNUSED_EXT) && file->extension[0] != '\0')
		deletesExts(temp);

	addFileExtension(&temp, getFileTypeFromFile(file->path));

	if (fileExists(temp))
	{
		// Do stuff, like telling user that it didn't corrected cus file already exist.
		free(temp);	temp = NULL;
		addError("Couldn't rename file. File already exists.\n");
		return;
	}
	rename(file->path, temp);
	free(temp);	temp = NULL;
}