#include "http.h"

void handle_http(const char *bytes){
    display("\n",VERB_LEVEL_2);
    display("\t\t",VERB_LEVEL_3);
    display("Application : HTTP ",1);
    size_t i=0;
    while(bytes[i]!='\n') putchar(bytes[i++]);
    if ((strncmp("HTTP", bytes, 4) == 0)
     || (strncmp("GET" , bytes, 3) == 0)
     || (strncmp("POST", bytes, 4) == 0)
     || (strncmp("PUT" , bytes, 3) == 0)
     || (strncmp("DELETE",bytes,6) == 0)
     || (strncmp("HEAD", bytes, 4) == 0) ) {

         while(*bytes!='\n'){if(verbosity>=VERB_LEVEL_1){putchar(*bytes++);}}
        putchar('\n');
        bytes++;
    } else {
        display("[ HTTP CONTENT ]",1);
    }


}
