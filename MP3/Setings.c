#include "Setings.h"

struct Setings NewSettings()
{
    struct Setings s;
    return s;
}

void SetFilepath(struct Setings *s, char * value)
{
    s->filepath = value;
}

char* GetFilepath(struct Setings *s)
{
    return s->filepath;
}