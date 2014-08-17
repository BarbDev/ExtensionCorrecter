/*
 * pathUtility.h
 *
 *  Created on: 11 août 2014
 *      Author: Tanguy
 */

#ifndef PATHUTILITY_H_
#define PATHUTILITY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <Shlwapi.h> //Window thingy - added -lShlwapi to linker
#include "constantes.h"
#include <tinydir.h>

/*******************************************************
*** Check if the string point to NULL if not, free
*** the string.
********************************************************/
#define CHECKFREED(str) { if (str != NULL){ free(str); str = NULL; } }

/*******************************************************
*** Returns the address of the "." that precedes
*** the extension.
********************************************************/
//char* getFileExtensionPtr(const char const * file);

/*******************************************************
*** Extract the file name from a file path
*** Return the name
*** WARNING: the returned string must be freed
********************************************************/
char* getFileName(const char * file);

/*******************************************************
*** Return a string with the type added
*** The string returned must be freed later
********************************************************/
char* addFileExtension(const char * file, FileType const type);

/*******************************************************
*** Return an Enum representing the file type
*** WARNING: Return FILETYPE_COUNT in case of detection
*** error.
********************************************************/
FileType getFileTypeFromFile(const char * file);

/*******************************************************
*** Return an Enum representing the file type
*** WARNING: Return FILETYPE_COUNT in case of detection
*** error.
********************************************************/
FileType getFileTypeFromExtension(const char * extension);

/*******************************************************
*** Tell if the path point to a directory or to a file.
*** Return 1 if it's a directory or 0 if not
********************************************************/
//unsigned char isDirectory(const char const * path);

/*******************************************************
*** Tell if the file passed has an extension
*** Return 1 if it has one or else 0
********************************************************/
//unsigned char hasExtension(const char const * file);

/*******************************************************
*** Check if the path passed point to an existing valid
*** file.
*** Return 1 if yes, or 0
********************************************************/
//unsigned char fileExists(const char const * path);

#endif /* PATHUTILITY_H_ */
