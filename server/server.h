#ifndef MY_SERVER
#define MY_SERVER

#include <iostream>
#include <stdexcept>
#include <vector>

#include <arpa/inet.h>
#include <cstring>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "utils/utils.h"

struct server_exception : std::runtime_error {
    server_exception(std::string cause);
};

struct server {
    server(char* address, uint16_t port);
    server(server const&) = delete;
    server& operator=(server const&) = delete;

    [[noreturn]] void run();

  private:
    sockaddr_in server_address;
    fd_wrapper socket_fd;

    const int BACKLOG = 3;
    const size_t BUFFER_SIZE = 1024;
};

#endif // MY_SERVER
