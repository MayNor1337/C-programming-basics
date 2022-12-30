#ifndef MP3_SETINGS_H
#define MP3_SETINGS_H

struct Setings
{
    char* filepath;
};


void SetFilepath(struct Setings *s, char * value);
char* GetFilepath(struct Setings *s);
struct Setings NewSettings();

#endif //MP3_SETINGS_H
