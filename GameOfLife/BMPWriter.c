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

    //////// BM Header
    // BM
    fwrite(hdr->_type, sizeof(uint8_t), 2, output);
    // File size
    uint32_t temp32 = sizeof(game) + hdr->_offsetBits;
    fwrite(&temp32, sizeof(uint32_t), 1, output);
    // Unused
    temp32 = 0;
    fwrite(&temp32, sizeof(uint32_t), 1, output);
    // Header size
    temp32 = hdr->_offsetBits;
    fwrite(&temp32, sizeof(uint32_t), 1, output);

    //////// DIB Header
    // DIB Header size
    temp32 = 40;
    fwrite(&temp32, sizeof(uint32_t), 1, output);
    // Dimensions
    fwrite(&hdr->_width, sizeof(uint32_t), 1, output);
    fwrite(&hdr->_height, sizeof(uint32_t), 1, output);
    // Color plane
    uint16_t temp16 = 1;
    fwrite(&temp16, sizeof(uint16_t), 1, output);
    // Palette
    fwrite(&temp16, sizeof(uint16_t), 1, output);

    // No compression
    temp32 = 0;
    fwrite(&temp32, sizeof(uint32_t), 1, output);
    // Image size
    temp32 = sizeof(game);
    fwrite(&temp32, sizeof(uint32_t),1, output);
    // Print dimensions
    fwrite(&hdr->_xPixelsPerMeter, sizeof(uint32_t), 1, output);
    fwrite(&hdr->_yPixelsPerMeter, sizeof(uint32_t), 1, output);
    temp32 = 0;
    fwrite(&temp32, sizeof(uint32_t), 1, output);
    fwrite(&temp32, sizeof(uint32_t), 1, output);
    // Palette
    temp32 = 0;
    fwrite(&temp32, sizeof(uint32_t), 1, output);
    temp32 = 0x00FFFFFF;
    fwrite(&temp32, sizeof(uint32_t), 1, output);

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
