#include <stdio.h>
#include "Parser.h"
#include "Setings.h"
#include "Header.h"

int main(int argc, char * argv[])
{
    struct Setings setings = NewSettings();
    struct Header hdr = NewHeader();
    Parse(&setings, argc, argv);
}
