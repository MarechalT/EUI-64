#include <string>
#include <sys/socket.h>
#include <net/if.h> //ifr
#include <sys/ioctl.h>
#include <cstring> //strncpy
#include <unistd.h> //close
#include "eui-64.h"
#include <iostream>
#include <sstream>
#include <bitset>

void getMAC(const std::string &interface, char* macaddr)
{
	int fd;
	struct ifreq ifr;

	fd = socket(AF_INET, SOCK_DGRAM, 0);

	ifr.ifr_addr.sa_family = AF_INET;
	strncpy((char*)ifr.ifr_name, (const char*)interface.c_str(), IFNAMSIZ-1);
	ioctl(fd, SIOCGIFHWADDR, &ifr);
	close(fd);

	memcpy(macaddr,(char*) ifr.ifr_hwaddr.sa_data,6);
	return ;
}

void insertFFFE(char* macaddr)
{
	char buffer[8]{'\0'};
	memcpy(buffer,macaddr+7,7);
	memcpy(macaddr+7,"FF:FE",5);
	memcpy(macaddr+12,buffer,7);
}

void flip7thbit(char* macaddr) {
	char val[2];
	unsigned int value;
	std::stringstream ss;
	memcpy(val, macaddr, 2);
	ss << val;
	ss >> std::hex >> value;
	std::bitset<8> firstbyte(value);
	firstbyte.flip(6);
	value = firstbyte.to_ulong();
	sprintf(val, "%02X", value);
	memcpy(macaddr, val, 2);
}
