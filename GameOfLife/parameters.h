#ifndef GAMEOFLIFE_PARAMETERS_H
#define GAMEOFLIFE_PARAMETERS_H

struct Parameters
{
    char* _fileName;
    char* _directoryName;
    unsigned int _maxIteration;
    unsigned int _dumpFreq;

};

struct Parameters NewParameters();

char* GetFileName(struct Parameters * p);
void SetFileName(struct Parameters *p, char* fileName);
char* GetDirectoryName(struct Parameters * p);
void SetDirectoryName(struct Parameters* p, char* directoryName);
int GetMaxIteration(struct Parameters * p);
void SetMaxIteration(struct Parameters * p, unsigned int maxIteration);
int GetDumpFreq(struct Parameters * p);
void SetDumpFreq(struct Parameters * p, unsigned int dumpFreq);

#endif //GAMEOFLIFE_PARAMETERS_H
