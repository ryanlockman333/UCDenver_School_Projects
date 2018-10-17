#include <cstdlib>
#include <string>
#include "serversocket.h"

std::string strToUpper(const std::string str);

int main(int argc, char **argv) {
    ServerSocket serv(std::atoi(argv[1])); // listen socket

    for(;;)
        try {
            ServerSocket conn_sock;
            serv.accept(conn_sock);
            std::string str;
            conn_sock >> str;
            conn_sock << strToUpper(str); // echo
        }
        catch(int) {
            return EXIT_FAILURE;
        }
}

std::string strToUpper(const std::string str) {
	std::string ans = str;

	// Process strToUpper
	for(size_t i = 0; i < str.length(); i++)
		ans[i] = std::toupper((unsigned char)str[i]);

	return ans;
}
