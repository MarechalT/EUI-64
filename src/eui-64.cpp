#include <string>
#include <sys/socket.h>
#include <net/if.h> //ifr
#include <sys/ioctl.h>
#include <cstring> //strncpy
#include <unistd.h> //close
#include "eui-64.h"
#include <iostream>

std::string getMAC(const std::string &interface)
{
	int fd;
	struct ifreq ifr;
	char* macaddr;

	fd = socket(AF_INET, SOCK_DGRAM, 0);

	ifr.ifr_addr.sa_family = AF_INET;
	strncpy((char*)ifr.ifr_name, (const char*)interface.c_str(), IFNAMSIZ-1);
	ioctl(fd, SIOCGIFHWADDR, &ifr);
	close(fd);

	macaddr = (char*) ifr.ifr_hwaddr.sa_data;
	printf("HW Addr: %02X:%02X:%02X:%02X:%02X:%02X\n", macaddr[0], macaddr[1], macaddr[2], macaddr[3], macaddr[4], macaddr[5]);

	std::string a(macaddr);
	return a;
}
