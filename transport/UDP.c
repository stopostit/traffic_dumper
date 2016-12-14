#include "UDP.h"

void handle_udp(const unsigned char *bytes){
    struct udphdr *udp_hdr = (struct udphdr *)bytes;
    u_short source_port = ntohs(udp_hdr->source), dest_port = ntohs(udp_hdr->dest);
    display("Protocol : UDP || FROM PORT ",VERB_LEVEL_2);
    if(verbosity>=VERB_LEVEL_2){printf("%u", source_port);}
    display(" >>TO PORT>> ",VERB_LEVEL_2);
    if(verbosity>=VERB_LEVEL_2){printf("%u", dest_port);}
    display(" || Length : ",VERB_LEVEL_2);
    if(verbosity>=VERB_LEVEL_2){uint16_t udp_length=ntohs(udp_hdr->len); printf("%u", udp_length);}
    display(" || Checksum : ",VERB_LEVEL_2);
    if(verbosity>=VERB_LEVEL_2){uint16_t udp_checksum=ntohs(udp_hdr->check); printf("%u", udp_checksum);}
    bytes+=sizeof(struct udphdr);
    display("\n",VERB_LEVEL_2);
    if(source_port == DNS_PORT || dest_port == DNS_PORT){
        printf("handle_DNS(bytes);\n");
    } else if(source_port ==  BOOTP_SERVER_PORT || dest_port == BOOTP_SERVER_PORT || source_port == BOOTP_CLIENT_PORT  || dest_port == BOOTP_CLIENT_PORT){
        printf("handle_BOOTP();\n");
    } else if(source_port == NETBIOS_PORT || dest_port == NETBIOS_PORT || source_port == NETBIOS_PORT_BIS || dest_port == NETBIOS_PORT_BIS){
        display(" Protocol : NetBIOS",VERB_LEVEL_1);

    } else if (source_port == SNMP_PORT || dest_port == SNMP_PORT) {
        display(" Protocol : SNMP",VERB_LEVEL_1);
    }else {
        display("  ¯\\_(ツ)_/¯ Unknown UDP Protocol\n",VERB_LEVEL_1);
    }
}
