#ifndef MP3_HEADER_H
#define MP3_HEADER_H
#include <stdint.h>
#include <stdio.h>

struct Header
{
    char _fileId[4];
    uint8_t  _majorVersion;
    uint8_t  _minorVersion;
    uint8_t  _flags;
    uint32_t _size;
};

struct Header NewHeader();
void ReadHead(struct Header *hdr, FILE *file);
#endif //MP3_HEADER_H
