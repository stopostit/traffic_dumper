#include "ip.h"

void display_ip_addr(int32_t ip_addr){
    int32_t bytes[4];
    bytes[0] =  ip_addr        & 0xFF;
    bytes[1] = (ip_addr >> 8)  & 0xFF;
    bytes[2] = (ip_addr >> 16) & 0xFF;
    bytes[3] = (ip_addr >> 24) & 0xFF;
    printf("%d.%d.%d.%d",bytes[0], bytes[1], bytes[2], bytes[3]);
}
void handle_IP(const uint8_t *bytes){
    struct iphdr *ip_hdr=(struct iphdr *)bytes;
    display("Network layer : IPV",VERB_LEVEL_2);
    if(verbosity>=VERB_LEVEL_2){printf("%u", ip_hdr->version);}
    display(" || ",VERB_LEVEL_2);
    display("FROM ",VERB_LEVEL_1);
    if(verbosity>=VERB_LEVEL_1){display_ip_addr(ip_hdr->saddr);}
    display(" >>TO>> ",VERB_LEVEL_1);
    if(verbosity>=VERB_LEVEL_1){display_ip_addr(ip_hdr->daddr);}

    display(" || IHL : ",VERB_LEVEL_3);
    if(verbosity>=VERB_LEVEL_3){printf("%u", ip_hdr->ihl);}
    display(" || ToS : ",VERB_LEVEL_3);
    if(verbosity>=VERB_LEVEL_3){printf("%u", ip_hdr->tos);}
    display(" || Len : ",VERB_LEVEL_2);
    uint16_t total_length = ntohs(ip_hdr->tot_len);
    if(verbosity>=VERB_LEVEL_2){printf("%u",total_length);}
    display(" || ID : ",VERB_LEVEL_2);
    if(verbosity>=VERB_LEVEL_2){printf("%u", ip_hdr->id);}
    display(" || Frag Off : ",VERB_LEVEL_3);
    if(verbosity>=VERB_LEVEL_3){printf("%u", ip_hdr->frag_off);}
    display(" || TTL : ",VERB_LEVEL_3);
    if(verbosity>=VERB_LEVEL_3){printf("%u", ip_hdr->ttl);}
    display(" || Protocol : ",VERB_LEVEL_3);
    if(verbosity>=VERB_LEVEL_3){printf("%u", ip_hdr->protocol);}
    display(" || Checksum : ",VERB_LEVEL_3);
    if(verbosity>=VERB_LEVEL_3){printf("%u", ip_hdr->check);}
    display("\n",VERB_LEVEL_2);
    int i;
    for ( i = 0; i < 4*ip_hdr->ihl; i++) {
        bytes++;
    }

    switch (ip_hdr->protocol) {
        case 0x01:
            printf("handle_ICMP(bytes);");
            break;
        case 0x06:
            printf("handle_TCP();\n");
            break;
        case 0x11:
            printf("handle_UDP(bytes);\n");
            break;
        default:
            printf("Unknown protocol 0x%x\n", ip_hdr->protocol);
    }



}
