#include "ethernet.h"

void display_ether_addr(uint8_t ether_addr[ETH_ALEN]) {
    printf("%02x:%02x:%02x:%02x:%02x:%02x",ether_addr[0], ether_addr[1], ether_addr[2], ether_addr[3], ether_addr[4], ether_addr[5]);
}
void display_ETHERTYPE(uint16_t eth_type){
    switch (eth_type) {
        case ETHERTYPE_IP:
            display("IP",VERB_LEVEL_2);
            break;
        case ETHERTYPE_ARP:
            display("ARP",VERB_LEVEL_2);
            break;
        case ETHERTYPE_RARP:
            display("RARP",VERB_LEVEL_2);
            break;
        case ETHERTYPE_IPV6:
            display("IPV6",VERB_LEVEL_2);
            break;
        default :
            display("UNKNOWN",VERB_LEVEL_2);
            break;

    }
}
void handle_ethernet(const uint8_t *bytes){
    struct ether_header *eth_hdr = (struct ether_header *)bytes;
    eth_hdr->ether_type = ntohs(eth_hdr->ether_type);
    display("Link Layer : Ethernet || FROM  ",VERB_LEVEL_2);
    if(verbosity >= VERB_LEVEL_2){display_ether_addr(eth_hdr->ether_shost);}
    display(" >>TO>> ",VERB_LEVEL_2);
    if(verbosity >= VERB_LEVEL_2){display_ether_addr(eth_hdr->ether_dhost);}
    display("\n",VERB_LEVEL_2);
    bytes+=sizeof(struct ether_header); //On décale pour se place au début de l'en-tête IP/ARP
    switch (eth_hdr->ether_type) {
        case IP:
            handle_IP(bytes);
            break;
        default:
            printf("Not managed yet\n");

    }

}
