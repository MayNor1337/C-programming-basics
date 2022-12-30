#include <stdio.h>
#include <malloc.h>
#include "Frame.h"

uint32_t reverseByteorder(uint32_t x) {
    return (
            (x >> 24) | (((x >> 16) & 0x000000FF) << 8) | (((x >> 8) & 0x000000FF) << 16) | ((x & 0x000000FF) << 24)
    );
}

struct frame readFrame(FILE* file) {
    struct frame temp;
    fread(temp.tagId, sizeof(char), 4, file);
    fread(&temp.tagSize, sizeof(char), 4, file);
    fread(temp.flags, sizeof(char), 2, file);

    temp.tagSize = reverseByteorder(temp.tagSize);
    temp.data = (uint8_t*)malloc(sizeof(uint8_t)*temp.tagSize);
    fread(temp.data, sizeof(uint8_t), temp.tagSize, file);
    return temp;
}