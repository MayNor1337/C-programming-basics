#include <string.h>
#include "Parser.h"
#include "Setings.h"

void Parse(struct Setings *s, int argc, char * argv[])
{
    char * filepath;
    for (int i = 1; i < argc; i++)
    {
        if (strstr(argv[i], "--set=") == argv[i])
        {

        }
        else if (strstr(argv[i], "--show") == argv[i])
        {

        }
        else if (strstr(argv[i], "--get=") == argv[i])
        {


        }
        else if (strstr(argv[i], "--filepath=") == argv[i])
        {
            filepath = argv[i] + 11;
            SetFilepath(s, filepath);
        }
    }
}