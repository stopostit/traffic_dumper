#ifndef UDP_H
#define UDP_H
#include <netinet/udp.h>
#include "../display.h"
#include <stdint.h>
#include<netinet/in.h>



#ifndef DNS_PORT
#define DNS_PORT 53
#endif
#ifndef BOOTP_SERVER_PORT
#define BOOTP_SERVER_PORT 67
#endif
#ifndef BOOTP_CLIENT_PORT
#define BOOTP_CLIENT_PORT 68
#endif
#ifndef NETBIOS_PORT
#define NETBIOS_PORT 137
#endif
#ifndef NETBIOS_PORT_BIS
#define NETBIOS_PORT_BIS 138
#endif
#ifndef SNMP_PORT
#define SNMP_PORT 161
#endif
void handle_udp(const unsigned char *bytes);
#endif
