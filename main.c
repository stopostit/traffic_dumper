#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pcap.h>
#include "getopt.h"
#include "link/ethernet.h"
#include "display.h"
//#include "network/ip.h"
//*
int verbosity;
//*/
void abort_pcap(const char *errbuf) {
    perror("error");
    fprintf(stderr, "%s\n", errbuf);
    exit(EXIT_FAILURE);
}
void got_packet(u_char *user, const struct pcap_pkthdr *h, const u_char *bytes){
    static int packet_count=0;

    //*
    //display fonction
    printf("Packet #%d\n",packet_count++);
    //*/
    handle_ethernet(bytes);
}
int main(int argc, char const *argv[]) {
  char* device=NULL;
  char* capture_file=NULL;
  char* filter="";
  verbosity=2; // default level of verbosity: medium
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *capture;
  bpf_u_int32 ip;
  bpf_u_int32 mask;
  struct bpf_program bpf_program;
  parse_opt(argc,argv,&device, &capture_file,&filter,&verbosity);
  printf("device used is : %s\ncapture_file is %s\n", device,capture_file);
  if(device != NULL && capture_file != NULL) {
        fprintf(stderr, "error: you must choose between live capture analysis or file capture analysis\n");
        exit(EXIT_FAILURE);
    }

    if(capture_file == NULL) {
        if(device == NULL && (device = pcap_lookupdev(errbuf)) == NULL) {
            abort_pcap("pcap_lookupdev");
        }
        printf("using device %s for capture \n", device);

        if(pcap_lookupnet(device, &ip, &mask, errbuf) != 0) {
            abort_pcap("pcap_lookupnet");
        }
        //print_ip_addr(ip); printf(" ^ "); print_ip_addr(mask); printf(")\n");
    }
    else {
        if((capture = pcap_open_offline(capture_file, errbuf)) == NULL) {
            abort_pcap("pcap_open_offline");
        }
    }
    if(pcap_compile(capture, &bpf_program, filter, 0, ip) == -1) {
        //pcap_perror(capture);
        abort_pcap("pcap_compile");
    }
    if(pcap_setfilter(capture, &bpf_program) != 0) {
        abort_pcap("pcap_setfilter");
    }
    pcap_freecode(&bpf_program);

    pcap_loop(capture, -1, &got_packet, NULL);
  return 0;
}
