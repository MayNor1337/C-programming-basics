#ifndef GAMEOFLIFE_PARSER_H
#define GAMEOFLIFE_PARSER_H
#include "parameters.h"


void Handle(struct Parameters *p, char* argv[], int i);
struct Parameters GetSettings(int argc, char * argv[]);

#endif //GAMEOFLIFE_PARSER_H
