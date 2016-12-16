#ifndef ETHERNET_H
#define ETHERNET_H
#include <net/ethernet.h>
#include <netinet/in.h>
#include <stdint.h>
#include"../display.h"
#include "../network/ip.h"
#ifndef IP
#define IP 0x0800
#endif
#ifndef ARP
#define ARP 0x806
#endif
#ifndef RARP
#define ETHERTYPE_RARP 0x835
#endif
void display_ether_addr(uint8_t ether_addr[ETH_ALEN]);
void display_ETHERTYPE(uint16_t type);
void handle_ethernet(const uint8_t *bytes);

#endif
