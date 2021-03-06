#include "client/client.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Wrong usage. Two arguments expected: <address> <port>"
                  << std::endl;
        return -1;
    }
    try {
        client client(argv[1], static_cast<uint16_t>(std::stoul(argv[2])));
        std::cout << "It's echo-client, type anything. Type exit to end it."
                  << std::endl;
        std::string text;
        while (!std::cin.eof()) {
            accumulator acc;
            std::cout << "Request: ";
            std::cout.flush();
            std::getline(std::cin, text);
            if (text == "exit")
                break;
            std::cout << "Responce: " << client.request(text, acc) << std::endl;
        }
    } catch (client_exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
