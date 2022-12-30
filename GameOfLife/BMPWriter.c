#include <string.h>
#include <stdio.h>
#include "BMPWriter.h"
#include "parameters.h"
#include "BMPHeader.h"

uint32_t reverse(uint32_t x)
{
    x = (x >> 24) | (((x >> 16) & 0xFF) << 8) | (((x >> 8) & 0xFF) << 16) | ((x & 0xFF) << 24);
    return x;
}

void Write(struct Parameters *param, struct BMPHeader *hdr, int **game, int **temp, int iter, int byteWidth)
{
    char outputPath[4096];

    memset(outputPath, '\0', sizeof(outputPath));
    sprintf(outputPath, "%s/gen-%d.bmp",GetDirectoryName(param), iter + 1);
    printf("%s\n", outputPath);
    FILE* output = fopen(outputPath, "wb");

    struct BMPHeader tempi = *hdr;
    tempi._size =  sizeof(game) + hdr->_offsetBits;
    tempi._headerSize = 40;
    fwrite(&tempi, 62, 1, output);

    uint32_t field;
    for (int h = 0; h < hdr->_height; h++)
    {
        for (int w = 0; w < byteWidth; w++)
        {
            field = reverse(temp[h][w]);
            fwrite(&field, sizeof(uint32_t), 1, output);
        }
    }

    fclose(output);
    printf("Generation %d has been created!\n", iter + 1);
}
