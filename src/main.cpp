#include <iostream>
#include "eui-64.h"

int main(int argc, char** argv)
{
	std::cout << "eui-64 starting" << std::endl;
	std::string interface("wlan0");

	if (argc<2)
	{
		std::cout << "retrieving the wlan0 interface MAC Address. Pass other interface as parameter" << std::endl;
	}
	else
	{
		interface= argv[1];
		std::cout <<  "Using the interface " << interface << std::endl;
	}

	char mac[6]{'\0'};
	char eui_64[20]{'\0'};

	if(!getMAC(interface,mac))
	{
		std::cerr << "Could not retrieve the hw address. Stopping..." << std::endl;
		return -1;
	}

	sprintf(eui_64,"%02X%02X:%02X%02X:%02X%02X", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
	std::cout << "MAC Address retrieved: " << eui_64 << std::endl;

	macToEUI_64(eui_64);
	std::cout << "EUI_64 created: " << eui_64 << std::endl;

	return 0;
}
