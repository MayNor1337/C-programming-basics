#ifndef MP3_HEADER_H
#define MP3_HEADER_H
#include <stdint.h>
#include <stdio.h>

#pragma pack(push, 2)
struct Header
{
    char _fileId[3];
    uint8_t  _majorVersion;
    uint8_t  _minorVersion;
    uint8_t  _flags;
    uint32_t _size;
};
#pragma pack(pop)

struct Header NewHeader();
void ReadHead(struct Header *hdr, FILE *file);
#endif //MP3_HEADER_H
