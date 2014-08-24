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
*** Modifie directly the file passed, append to it the
*** type passed.
********************************************************/
void addFileExtension(char ** file, const char * type);

/*******************************************************
*** Return 0 if passed file does not exists
********************************************************/
unsigned char fileExists(const char * file);

/*******************************************************
*** Return an string representing the file type
*** WARNING: Return "error" in case of detection
*** error.
********************************************************/
const char* getFileTypeFromFile(const char * file);

/*******************************************************
*** Return an string representing the file type
*** WARNING: Return "error" in case of detection
*** error.
********************************************************/
const char* getFileTypeFromExtension(const char * extension);

#endif /* PATHUTILITY_H_ */
