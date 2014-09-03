/*
 * constantes.h
 *
 *  Created on: 11 août 2014
 *      Author: Tanguy
 */

#ifndef CONSTANTES_H_
#define CONSTANTES_H_

#include <stddef.h>

#define ID_SIZE 4
#define TYPE_SIZE 16

/*******************************************************
*** NON_AGRESSIVE mode:
*** check files without extension and add the
*** corresponding one.
*** AGRESSIVE mode:
*** even check files with an extension and add the
*** corresponding one.
********************************************************/
#define NON_AGRESSIVE 0
#define AGRESSIVE 1

/*******************************************************
*** ALL_SUB_DIR: correct files of current dir and his
*** sub dir.
*** ONLY_SUB_DIR: correct only files of sub dir of dir
********************************************************/
#define ALL_SUB_DIR 2
#define ONLY_SUB_DIR 4

/*******************************************************
*** Will make sure that files name does not contains
*** multiple extension.
********************************************************/
#define REMOVE_UNUSED_EXT 8

typedef struct Extension
{
	char type[TYPE_SIZE]; // Contain the string that will be concatenated to file's name
	char id[ID_SIZE]; // Contain the 'id' that will be used to recognise the type of a file
} Extension;

extern const Extension global_ExtsCollection[];
extern const size_t global_ExtsCollSize;

#endif /* CONSTANTES_H_ */
