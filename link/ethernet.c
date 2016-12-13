#include "ethernet.h"

void print_ether_address(uint8_t ether_addr[ETH_ALEN]) {
    printf("%02x:%02x:%02x:%02x:%02x:%02x",
           ether_addr[0], ether_addr[1], ether_addr[2],
           ether_addr[3], ether_addr[4], ether_addr[5]);
}
void print_ether_type(uint16_t type){

}
void handle_ethernet(const uint8_t *bytes){
    struct ether_header *eth_hdr = (struct ether_header *)bytes;
    

}
