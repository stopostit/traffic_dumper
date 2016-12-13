#include "getopt.h"

void parse_opt(int argc, const char* argv[],  char** device, char** capture_file, char** filter, int* verbosity){
  int opt;
  while((opt = getopt(argc, argv, "hi:o:f:v:")) != -1) {
         switch(opt) {
             case 'h':
                 fprintf(stderr, "usage: %s [-v verbosity] [-f filter] [-i interface]|[-o capture_file]\n", argv[0]);
                 exit(EXIT_SUCCESS);
             case 'i':
                 *device = optarg;
                 break;
             case 'o':
                 *capture_file = optarg;
                 break;
             case 'f':
                 *filter = optarg;
                 printf("using \"%s\" as BPF filter\n", *filter);
                 break;
             case 'v':
                 *verbosity = atoi(optarg);
                 if(*verbosity < 1 || *verbosity > 3) {
                     fprintf(stderr, "invalid verbosity level %d\n", *verbosity);
                     exit(EXIT_FAILURE);
                 }
                 break;
             default:
                break;
         }
     }
}
