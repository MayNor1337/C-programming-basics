#include <stdint.h>
#include <malloc.h>
#include "GameLogic.h"
#include "parameters.h"
#include "BMPHeader.h"
#include "BMPWriter.h"

int CountNeighbours(int with, int height, int maxWith, int maxHeight, int bitIndex, int byteIndex, int ** game)
{
    int neighbours = 0;
    // 6 7 8
    // 4 # 5
    // 1 2 3

    // 1
    if(with > 0 && height > 0)
        neighbours += (game[height - 1][(with - 1) / 32] & (0x80000000 >> ((with - 1) % 32))) ? 1 : 0;
    // 2
    if(height > 0)
        neighbours += (game[height - 1][byteIndex] & (0x80000000 >> bitIndex)) ? 1 : 0;
    // 3
    if(height > 0 && with < maxWith)
        neighbours += (game[height - 1][(with + 1) / 32] & (0x80000000 >> (( with+ 1) % 32))) ? 1 : 0;
    // 4
    if(with > 0)
        neighbours += (game[height][(with - 1) / 32] & (0x80000000 >> ((with - 1) % 32))) ? 1 : 0;
    // 5
    if(with < maxWith)
        neighbours += (game[height][(with + 1) / 32] & (0x80000000 >> ((with + 1) % 32))) ? 1 : 0;
    // 6
    if(with > 0 && height < maxHeight)
        neighbours += (game[height + 1][(with - 1) / 32] & (0x80000000 >> ((with - 1) % 32))) ? 1 : 0;
    // 7
    if(height < maxHeight)
        neighbours += (game[height + 1][byteIndex] & (0x80000000 >> bitIndex)) ? 1 : 0;
    // 8
    if(with < maxWith && height < maxHeight)
        neighbours += (game[height + 1][(with + 1) / 32] & (0x80000000 >> ((with + 1) % 32))) ? 1 : 0;
    return neighbours;
}

void GameLogic(struct Parameters *param, struct BMPHeader* hdr, int ** game, int byteWidth)
{
    int height = hdr->_height;
    int width = hdr->_width;
    int **temp;
    temp = (uint32_t**) calloc(hdr->_height, sizeof(uint32_t*));
    for(int i = 0; i < hdr->_height; i++)
    {
        temp[i] = (uint32_t*) calloc(byteWidth, sizeof(uint32_t));
    }
    int dumpFreq = GetDumpFreq(param);
    int maxIter = GetMaxIteration(param);
    int neighbours;
    int bitIndex;
    int byteIndex;

    for (int iter = 0; iter < maxIter; iter++)
    {
        for (int h = 0; h < height; h++)
        {
            for (int w = 0; w < width; w++)
            {
                byteIndex = w / 32;
                bitIndex  = w % 32;

                if (bitIndex == 0)
                {
                    temp[h][byteIndex] = 0;
                }

                neighbours = CountNeighbours(w, h, width - 1, height - 1, bitIndex, byteIndex, game);

                if (((neighbours == 2 || neighbours == 3) && (game[h][byteIndex] & (0x80000000 >> bitIndex))) || (neighbours == 3))
                {
                    temp[h][byteIndex] = temp[h][byteIndex] | (0x80000000 >> bitIndex);
                }
            }
        }

        if ((iter + 1) % dumpFreq == 0 || iter == maxIter - 1)
        {
            Write(param, hdr, game, temp, iter, byteWidth);
        }

        for (int h = 0; h < height; h++) {
            for (int w = 0; w < byteWidth; w++) {
                game[h][w] = temp[h][w];
            }
        }
    }
}
