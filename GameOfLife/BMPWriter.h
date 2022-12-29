#ifndef GAMEOFLIFE_BMPWRITER_H
#define GAMEOFLIFE_BMPWRITER_H
#include <stdint.h>
#include "parameters.h"
#include "BMPHeader.h"

void Write(struct Parameters *param, struct BMPHeader *hdr, int **game, int **temp, int iter, int byteWidth);

#endif //GAMEOFLIFE_BMPWRITER_H
