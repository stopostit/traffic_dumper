#ifndef IP_H
#define IP_H
#include<netinet/in.h>
#include<netinet/ip.h>
#include "../display.h"
#include "../transport/UDP.h"
#include "../transport/tcp.h"

void display_ip_addr(int32_t ip_addr);
void handle_IP(const uint8_t *bytes);
#endif
