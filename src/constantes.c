/*
 * constantes.c
 *
 *  Created on: 11 août 2014
 *      Author: Tanguy
 */

#include "constantes.h"

const char FileTags[FILETYPE_COUNT][4] = {{137, 80, 78, 71},	//PNG
										{0x42, 0x4D, 0, 0},		//BMP
										{0x47, 0x49, 0x46, 0},	//GIF
										{255, 216, 255, 224},	//JPEG1
										{255, 216, 255, 225},	//JPEG2
										{73, 73, 42, 0},		//TIFF1
										{77, 77, 42, 0}};		//TIFF2
