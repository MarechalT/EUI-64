#include <iostream>
#include "eui-64.h"

int main()
{
	char mac[6]{'\0'};
	char macHex[20]{'\0'};
	std::cout << "eui-64 starting" << std::endl;
	getMAC("wlan0",mac);
	sprintf(macHex,"%X%X:%X%X:%X%X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	std::cout << macHex << std::endl;
	insertFFFE(macHex);
	std::cout << macHex << std::endl;
	flip7thbit(macHex);
	std::cout << macHex << std::endl;

	return 0;
}
