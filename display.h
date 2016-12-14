#ifndef DISPLAY_H
#define DISPLAY_H
#include<stdio.h>
#include <stdlib.h>

#ifndef VERB_LEVEL_1
#define VERB_LEVEL_1 1
#endif
#ifndef VERB_LEVEL_2
#define VERB_LEVEL_2 2
#endif
#ifndef VERB_LEVEL_3
#define VERB_LEVEL_3 3
#endif
extern int verbosity;

void display(char* string,int verbosity_level);
#endif
