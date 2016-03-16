#include <iostream>
#include <sys/types.h>       // For data types
#include <sys/socket.h>      // For socket(), connect(), send(), and recv()
#include <netdb.h>           // For gethostbyname()
#include <arpa/inet.h>       // For inet_addr()
#include <unistd.h>          // For close()
#include <netinet/in.h>      // For sockaddr_in
#include <string.h>
typedef void raw_type;       // Type used for raw data on this platform

#include "simple_socket.h"

int main() {
    std::cout << "Yo Server" << std::endl;
    unsigned short port = 9954;
    // SimpleSocket sock;

    // Create serverSocket, handle accept
    int sockDesc = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockDesc < 0) {
        std::cout << "Failed to create socket" << std::endl;
        exit(1);
    }
    sockaddr_in LocalAddr;
    memset(&LocalAddr, 0, sizeof(LocalAddr));
    LocalAddr.sin_family = AF_INET;
    LocalAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    LocalAddr.sin_port = htons(port);

    if(bind(sockDesc, (sockaddr*) &LocalAddr, sizeof(sockaddr_in)) < 0) {
        std::cout << "Failed to bind port" << std::endl;
        exit(1);
    }
    if(listen(sockDesc, 5) < 0) {
        std::cout << "Unable to listen" << std::endl;
        exit(1);
    }

    int ClientSockDesc = accept(sockDesc, NULL, 0);
    if(ClientSockDesc < 0) {
        std::cout << "Failed to accept connection" << std::endl;
        exit(1);
    }
    // when accept, recv until
    char echoBuffer[32];
    memset(&echoBuffer, 0, sizeof(echoBuffer));
    int recvMsgSize;
    while((recvMsgSize = recv(ClientSockDesc, echoBuffer, sizeof(echoBuffer), 0))>0) {
        std::cout << "Client: " << echoBuffer << " ->b " << recvMsgSize << std::endl;
        int sendSize = send(ClientSockDesc, echoBuffer, strlen(echoBuffer), 0);
        if (sendSize < 0) {
            std::cout << "Failed to send" << std::endl;
        }
        std::cout << "Wrote bytes: " << sendSize << std::endl;
        memset(&echoBuffer, 0, sizeof(echoBuffer));
    }
    // close connection
    close(sockDesc);
    close(ClientSockDesc);
    return 0;
}
