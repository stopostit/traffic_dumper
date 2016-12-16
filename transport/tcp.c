#include "tcp.h"

void handle_tcp(const uint8_t *bytes){
    struct tcphdr *tcp_hdr;
    tcp_hdr=(struct tcphdr *)bytes;
    tcp_hdr->th_sport = ntohs(tcp_hdr->th_sport);
    tcp_hdr->th_dport = ntohs(tcp_hdr->th_dport);
    display("Protocol : TCP || FROM PORT ",VERB_LEVEL_2);
    if(verbosity>=VERB_LEVEL_2){printf("%u", tcp_hdr->th_sport);}
    display(" >>TO PORT>> ",VERB_LEVEL_2);
    if(verbosity>=VERB_LEVEL_2){printf("%u", tcp_hdr->th_dport);}

    display(" || FLAGS: [ ",VERB_LEVEL_2);
	if (tcp_hdr->th_flags & TH_FIN)
		display(" FIN",VERB_LEVEL_2);
	if (tcp_hdr->th_flags & TH_SYN)
		display("   SYN  ",VERB_LEVEL_2);
	if (tcp_hdr->th_flags & TH_RST)
		display("   RST  ",VERB_LEVEL_2);
	if (tcp_hdr->th_flags & TH_PUSH)
		display("   PUSH  ",VERB_LEVEL_2);
	if (tcp_hdr->th_flags & TH_ACK)
		display("   ACK  ",VERB_LEVEL_2);
	if (tcp_hdr->th_flags & TH_URG)
		display("   URG  ",VERB_LEVEL_2);
    display(" ] ||  ",VERB_LEVEL_2);


    display("seq : ",VERB_LEVEL_2);if(verbosity>=VERB_LEVEL_2){printf("%u", ntohl(tcp_hdr->seq));}
    display(" || ack : ",VERB_LEVEL_2);if(verbosity>=VERB_LEVEL_2){printf("%u", ntohl(tcp_hdr->ack_seq));}
    display(" || win :",VERB_LEVEL_2);if(verbosity>=VERB_LEVEL_2){printf("%u", ntohs(tcp_hdr->window));}

    size_t i;
    size_t tcp_hdrsize = (size_t)tcp_hdr->th_off;
    for (i = 0; i < tcp_hdrsize; i++) {
        *bytes++;
    }
    display("\n\t",VERB_LEVEL_3);

    if(tcp_hdr->th_sport == 80 || tcp_hdr->th_dport == 80) {
        handle_http((const char *) bytes);
    } else{
        display("\tUnknown TCP protocol",VERB_LEVEL_1);
        if(verbosity>=VERB_LEVEL_1){printf("\tsource port: %u dest port: %u", tcp_hdr->th_sport, tcp_hdr->th_dport);}
    }

}
