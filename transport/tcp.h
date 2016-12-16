#ifndef TCP_H
#define TCP_H
#include<netinet/tcp.h>
#include <netinet/in.h>
#include "../display.h"
#include "../application/http.h"

void handle_tcp(const uint8_t *bytes);
#endif
