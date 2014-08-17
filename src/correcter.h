/*
 * correcter.h
 *
 *  Created on: 17 août 2014
 *      Author: Tanguy
 */

#ifndef CORRECTER_H_
#define CORRECTER_H_

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
*** LIMITED_TO_DIR: only correct files of the dir
*** ALL_SUB_DIR: correct files of current dir and his
*** sub dir.
*** ONLY_SUB_DIR: correct only files of sub dir of dir
********************************************************/
#define LIMITED_TO_DIR 2
#define ALL_SUB_DIR 4
#define ONLY_SUB_DIR 8

/*******************************************************
*** Will make sure that files name does not contains
*** multiple extension.
********************************************************/
#define REMOVE_UNUSED_EXT 16

void correctDir(const char * directory, unsigned char params);
static void deletesExts(char* file);

#endif /* CORRECTER_H_ */
