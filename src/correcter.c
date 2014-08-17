/*
 * correcter.c
 *
 *  Created on: 17 août 2014
 *      Author: Tanguy
 */

#include "correcter.h"

void correctDir(const char * directory, unsigned char params)
{
	if (((params & NON_AGRESSIVE) && (params & AGRESSIVE)) ||
			((params & ALL_SUB_DIR) && (params & ONLY_SUB_DIR)) ||
			((params & LIMITED_TO_DIR) && (params & ALL_SUB_DIR)) ||
			((params & LIMITED_TO_DIR) && (params & ONLY_SUB_DIR)))
	{
		// Error
		return;
	}
	else
	{
		deletesExts(0);
	}
}

static void deletesExts(char* file)
{

}
