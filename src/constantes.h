/*
 * constantes.h
 *
 *  Created on: 11 août 2014
 *      Author: Tanguy
 */

#ifndef CONSTANTES_H_
#define CONSTANTES_H_

typedef enum FileType { PNG, BMP, GIF, JPG1, JPG2, TIFF1, TIFF2, FILETYPE_COUNT } FileType;

extern const char FileTags[FILETYPE_COUNT][4];

#endif /* CONSTANTES_H_ */
