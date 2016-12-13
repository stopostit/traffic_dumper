#ifndef GETOPT_H
#define  GETOPT_H
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>

void parse_opt(int argc, const char* argv[],char** device, char** capture_file, char** filter, int* verbosity);
#endif
