#include <stdio.h>
#include "BMPHeader.h"

#ifndef GAMEOFLIFE_BMPREADER_H
#define GAMEOFLIFE_BMPREADER_H

void ReadBMP(FILE *file, struct BMPHeader *bmp);

int ReadGamePosition(uint32_t** game, struct BMPHeader* bmp, uint32_t byteWidth, FILE *file);

#endif //GAMEOFLIFE_BMPREADER_H
