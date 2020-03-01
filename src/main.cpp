#include <iostream>
#include "eui-64.h"

int main()
{
	std::cout << "eui-64 starting" << std::endl;
	std::cout << getMAC("wlan0") << std::endl;

	return 0;
}
