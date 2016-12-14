#include "display.h"

void display(char* string,int verbosity_level){
    if (verbosity>=verbosity_level) {
        printf("%s",string);
    }
}
