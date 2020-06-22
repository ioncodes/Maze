#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>

#pragma comment(lib, "Ws2_32.lib")

class ipc
{
public:
    static void send(std::string message)
    {
        auto sock = socket(AF_INET, SOCK_DGRAM, 0);
        
        sockaddr_in addrListen = {};
        addrListen.sin_family = AF_INET;
        auto result = bind(sock, (sockaddr*)&addrListen, sizeof(addrListen));
        if (result == -1)
        {
            int lasterror = errno;
            std::cout << "error: " << lasterror << std::endl;
            return;
        }

        sockaddr_storage dest = {};
        result = ipc::resolve("127.0.0.1", AF_INET, "12000", &dest);
        if (result != 0)
        {
            int lasterror = errno;
            std::cout << "error: " << lasterror << std::endl;
            return;
        }

        auto bytes_sent = sendto(sock, message.c_str(), message.size(), 0, (sockaddr*)&dest, sizeof(dest));
    }
private:
    static int resolve(const char* hostname, int family, const char* service, sockaddr_storage* addr)
    {
        int result;
        addrinfo* result_list = NULL;
        addrinfo hints = {};
        hints.ai_family = family;
        hints.ai_socktype = SOCK_DGRAM;
        result = getaddrinfo(hostname, service, &hints, &result_list);
        if (result == 0)
        {
            memcpy(addr, result_list->ai_addr, result_list->ai_addrlen);
            freeaddrinfo(result_list);
        }

        return result;
    }
};