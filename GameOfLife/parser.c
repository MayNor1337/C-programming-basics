#include "parser.h"
#include "parameters.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Handle(struct Parameters *p, char* argv[], int i)
{
    if(strcmp(argv[i], "--input") == 0)
    {
        SetFileName(p, argv[i + 1]);
    }
    if(strcmp(argv[i], "--output") == 0)
    {
        SetDirectoryName(p, argv[i + 1]);
    }
    if(strcmp(argv[i], "--max_iter") == 0)
    {
        char *end;
        SetMaxIteration(p, strtol(argv[i + 1], &end, 10));
    }
    if(strcmp(argv[i], "--dump_freq") == 0)
    {
        char *end;
        SetDumpFreq(p, strtol(argv[i + 1], &end, 10));
    }
}

struct Parameters GetSettings(int argc, char * argv[])
{
    struct Parameters p = NewParameters();

    for(int i = 1; i < argc; i++)
    {
        Handle(&p, argv, i);
    }

    return p;
}
