#ifndef GAMEOFLIFE_BMPHEADER_H
#define GAMEOFLIFE_BMPHEADER_H
#include <stdint.h>

//https://habr.com/ru/post/142662/
#pragma pack(push, 1)
struct BMPHeader
{
    int8_t   _type[2];
    uint32_t _size;
    uint32_t _reserved;
    uint32_t _offsetBits;

    uint32_t _headerSize;
    int32_t  _width;
    int32_t  _height;
    uint16_t _planes;
    uint16_t _bitsCount;
    uint32_t _compression;
    uint32_t _imageSize;

    // Compression
    uint32_t _xPixelsPerMeter;
    uint32_t _yPixelsPerMeter;
    uint32_t _colorsUsed;
    uint32_t _colorsImportant;
};
#pragma pack(pop)

struct BMPHeader NewBMPHeader();
#endif //GAMEOFLIFE_BMPHEADER_H
