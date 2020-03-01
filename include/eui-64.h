
bool getMAC(const std::string &interface, char* macaddr);
void insertFFFE(char* macaddr);
void flip7thbit(char* macaddr);
void macToEUI_64(char* buffer);
