#ifndef ETHERNET_H
#define ETHERNET_H
#include <net/ethernet.h>
#include <stdint.h>
#include <netinet/if_ether.h> //access to ethertypes and arp

void print_ether_address(uint8_t ether_addr[ETH_ALEN]);
void print_ether_type(u_int16_t type);
void handle_ethernet(const uint8_t *bytes);

#endif
