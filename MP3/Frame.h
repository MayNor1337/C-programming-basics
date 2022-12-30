#ifndef MP3_FRAME_H
#define MP3_FRAME_H

#include <stdint.h>

struct frame readFrame(FILE* file);
#pragma pack(push, 8)
struct frame {
    char tagId[4];
    uint32_t tagSize;
    uint8_t  flags[2];
    uint8_t* data;
};
#pragma pack(pop)


#endif //MP3_FRAME_H
