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
#include "constantes.h"
#include <tinydir.h>

/*******************************************************
*** Check if the string point to NULL if not, free
*** the string.
********************************************************/
#define CHECKFREED(str) { if (str != NULL){ free(str); str = NULL; } }

/*******************************************************
*** Return a string with the type added
*** The string returned must be freed later
********************************************************/
void addFileExtension(char ** file, const char * type);

/*******************************************************
*** Return 0 if passed file does not exists
********************************************************/
unsigned char fileExists(const char * file);

/*******************************************************
*** Return an Enum representing the file type
*** WARNING: Return FILETYPE_COUNT in case of detection
*** error.
********************************************************/
const char* getFileTypeFromFile(const char * file);

/*******************************************************
*** Return an Enum representing the file type
*** WARNING: Return FILETYPE_COUNT in case of detection
*** error.
********************************************************/
const char* getFileTypeFromExtension(const char * extension);

#endif /* PATHUTILITY_H_ */
