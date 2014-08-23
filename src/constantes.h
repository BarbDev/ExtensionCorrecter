/*
 * constantes.h
 *
 *  Created on: 11 août 2014
 *      Author: Tanguy
 */

#ifndef CONSTANTES_H_
#define CONSTANTES_H_

#include <crtdefs.h>

#define ID_SIZE 4
#define TYPE_SIZE 16

typedef struct Extension
{
	char type[TYPE_SIZE]; // Contain the string that will be concatenated to file's name
	char id[ID_SIZE]; // Contain the 'id' that will be used to recognise the type of a file
} Extension;

extern const Extension global_ExtsCollection[];
extern const size_t global_ExtsCollSize;

#endif /* CONSTANTES_H_ */
