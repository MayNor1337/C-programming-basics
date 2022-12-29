#include <stdio.h>
#include <malloc.h>
#include "parser.h"
#include "parameters.h"
#include "BMPHeader.h"
#include "BMPReader.h"
#include "GameLogic.h"

int main(int argc, char * argv[]) {
    ///// Set Settings (parse commands)
    struct Parameters param = GetSettings(argc, argv);
    printf("%s\n", "Settings seted");

    struct BMPHeader bmp = NewBMPHeader();

    ///// Open file
    printf("%s", GetFileName(&param));
    FILE* file = fopen(GetFileName(&param), "rb");
    if(file == NULL)
    {
        printf("%s\n", "not bmp file");
        return 1;
    }
    printf("%s\n", "File opened");

    ///// Read bmp settings
    ReadBMP(file, &bmp);

    //// Read game position
    int byteWidth = (bmp._width + 31) / 32;
    uint32_t **game;
    game = (uint32_t**) calloc(bmp._height, sizeof(uint32_t*));
    for(int i = 0; i < bmp._height; i++)
    {
        game[i] = (uint32_t*) calloc(byteWidth, sizeof(uint32_t));
    }

    if(ReadGamePosition(game, &bmp, byteWidth, file))
        return 1;

    printf("%s\n", "Game position ready");

    ////Game + write
    GameLogic(&param, &bmp, game, byteWidth);

    printf("%s\n", "End");

    return 0;
}
