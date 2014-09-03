/*
 * correcter.h
 *
 *  Created on: 17 août 2014
 *      Author: Tanguy
 */

#ifndef CORRECTER_H_
#define CORRECTER_H_

#include <tinydir.h>

char global_launchPath[_TINYDIR_PATH_MAX];

void correctDir(const char * directory, unsigned char params);

#endif /* CORRECTER_H_ */
