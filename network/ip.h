#ifndef IP_H
#define IP_H
#include<netinet/in.h>
#include<netinet/ip.h>
#include "../display.h"

void display_ip_addr(int32_t ip_addr);
void handle_IP();
#endif
