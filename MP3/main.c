#include <stdio.h>
#include "Parser.h"
#include "Setings.h"
#include "Header.h"

int main(int argc, char * argv[])
{
    struct Setings setings = NewSettings();
    struct Header hdr = NewHeader();
    Parse(&setings, argc, argv);
    FILE* file;
    file = fopen(GetFilepath(&setings), "rb");
    if (file == NULL) {
        printf("ERROR");
        return 1;
    }
    ReadHead(&hdr, file);
}
