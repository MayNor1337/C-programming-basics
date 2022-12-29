#ifndef GAMEOFLIFE_GAMELOGIC_H
#define GAMEOFLIFE_GAMELOGIC_H
#include "parameters.h"
#include "BMPHeader.h"

void GameLogic(struct Parameters *param, struct BMPHeader* hdr, int ** game, int byteWidth);

#endif //GAMEOFLIFE_GAMELOGIC_H
