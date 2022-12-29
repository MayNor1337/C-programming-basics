#include "parameters.h"
#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>

struct Parameters NewParameters()//char* fileName , char* directoryName, int maxIteration, int dumpFreq
{
    char* fileName = "input/ITMO_University.bmp";
    char* directoryName = "out";
    int maxIteration = 2147483647;
    int dumpFreq = 1;
    struct Parameters p = {fileName, directoryName, maxIteration, dumpFreq};

    return p;
}


char* GetFileName(struct Parameters * p)
{
    return p->_fileName;
}

void SetFileName(struct Parameters *p, char* fileName)
{
    p->_fileName = fileName;
}

char* GetDirectoryName(struct Parameters * p)
{
    return p->_directoryName;
}

void SetDirectoryName(struct Parameters *p, char* directoryName)
{
    p->_directoryName = directoryName;
}

int GetMaxIteration(struct Parameters * p)
{
    return p->_maxIteration;
}

void SetMaxIteration(struct Parameters * p, unsigned int maxIteration)
{
    p->_maxIteration = maxIteration;
}

int GetDumpFreq(struct Parameters * p)
{
    return p->_dumpFreq;
}

void SetDumpFreq(struct Parameters * p, unsigned int dumpFreq)
{
    p->_dumpFreq = dumpFreq;
}
