#include "Header.h"


uint32_t AntiSynchsafe (uint32_t x) {
    return (
            (x >> 24) | (((x >> 16) & 0x000000FF) << 7) | (((x >> 8) & 0x000000FF) << 14) | ((x & 0x000000FF) << 21)
    );
}

struct Header NewHeader()
{
    static struct Header hdr;
    return hdr;
}


void ReadHead(struct Header *hdr, FILE *file)
{
    fread(hdr->_fileId, sizeof(char), 3, file);
    fread(&hdr->_majorVersion, sizeof(uint8_t), 1, file);
    fread(&hdr->_minorVersion, sizeof(uint8_t), 1, file);
    fread(&hdr->_flags, sizeof(uint8_t), 1, file);
    fread(&hdr->_size, sizeof(uint32_t), 1, file);
    hdr->_size = AntiSynchsafe(hdr->_size);
    hdr->_fileId[3] = '\0';
}
