/*
 * constantes.c
 *
 *  Created on: 11 août 2014
 *      Author: Tanguy
 */

#include "constantes.h"

const Extension global_ExtsCollection[] = {
	{ ".jpg", { 255, 216, 255, 224 } }, //JPG
	{ ".jpg", { 255, 216, 255, 225 } },
	{ ".tiff", { 73, 73, 42, 0 } }, //TIFF
	{ ".tiff", { 77, 77, 42, 0 } },
	{ ".png", { 137, 80, 78, 71 } }, //PNG
	{ ".bmp", { 0x42, 0x4D, 0, 0 } }, //BMP
	{ ".gif", { 0x47, 0x49, 0x46, 0 } }, //GIF
	{ "error", "err" }
};

const size_t global_ExtsCollSize = sizeof(global_ExtsCollection) / sizeof(Extension);