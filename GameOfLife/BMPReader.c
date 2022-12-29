#include <math.h>
#include "BMPReader.h"
#include "BMPReader.h"

//https://ru.bmstu.wiki/BMP_(Bitmap_Picture)
void ReadBMP(FILE *file, struct BMPHeader *bmp)
{
    //////// Read header
    fread(&bmp->_type,         sizeof(uint8_t ), 2, file);
    fread(&bmp->_size,         sizeof(uint32_t), 1, file);
    fread(&bmp->_reserved,     sizeof(uint32_t), 1, file);
    fread(&bmp->_offsetBits, sizeof(uint32_t), 1, file);

    //////// Read DIB header
    fread(&bmp->_headerSize,      sizeof(uint32_t), 1, file);
    fread(&bmp->_width,           sizeof(uint32_t), 1, file);
    fread(&bmp->_height,          sizeof(uint32_t), 1, file);
    fread(&bmp->_planes,          sizeof(uint16_t), 1, file);
    fread(&bmp->_bitsCount,    sizeof(uint16_t), 1, file);
    fread(&bmp->_compression,     sizeof(uint32_t), 1, file);
    fread(&bmp->_imageSize,       sizeof(uint32_t), 1, file);
    fread(&bmp->_xPixelsPerMeter,     sizeof(uint32_t), 1, file);
    fread(&bmp->_yPixelsPerMeter,     sizeof(uint32_t), 1, file);
    fread(&bmp->_colorsUsed,      sizeof(uint32_t), 1, file);
    fread(&bmp->_colorsImportant, sizeof(uint32_t), 1, file);

    bmp->_width = abs(bmp->_width);
    bmp->_height = abs(bmp->_height);
}


int ReadGamePosition(uint32_t** game, struct BMPHeader* bmp, uint32_t byteWidth, FILE *file)
{
    fseek(file, bmp->_offsetBits, SEEK_SET);
    if (bmp->_bitsCount == 1)
    {
        for (int h = 0; h < bmp->_height; h++)
        {
            for (int w = 0; w < byteWidth; w++)
            {
                fread(&(game[h][w]), sizeof(uint32_t), 1, file);
            }
        }

        return 0;
    } else {
        printf("%s", "loh");
        return 1;
    }
}
