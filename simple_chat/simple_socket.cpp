#include <stdlib.h>

#include "simple_socket.h"

void error(std::string msg) {
    perror(msg.c_str());
    exit(1);
}

TCPListener::TCPListener(std::string addr, int port) {
    Port = port;
    Addr = addr;
    SockDesc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    memset(&LocalAddr, 0, sizeof(LocalAddr));
    LocalAddr.sin_family = AF_INET;
    LocalAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    LocalAddr.sin_port = htons(port);
    
    // Bind socket
    if(bind(SockDesc, (sockaddr*) &LocalAddr, sizeof(sockaddr_in)) < 0) {
        error("Failed to bind port/addr");
    }
}

/// Should happen when creating socket?
void TCPListener::Listen(int queueLen) {
    if(listen(SockDesc, queueLen) < 0) {
        error("Unable to listen");
    }
}

// Should return Connection
TCPConnection* TCPListener::Accept() {
    int ConectionSockDesc = accept(SockDesc, nullptr, 0);
    TCPConnection* Connection = new TCPConnection(ConectionSockDesc);
    return Connection;
}

TCPConnection::TCPConnection(int sockDesc) {
    SockDesc = sockDesc;
}

    // int Read(std::array<char,255> &Buffer);
int TCPConnection::Read(std::array<char,255> &Buffer) {
   return recv(SockDesc, &Buffer, Buffer.size(), 0);
}

int TCPConnection::Write(std::array<char,255> &Buffer, int WriteSize) {
    return send(SockDesc, &Buffer, WriteSize, 0);
}

void TCPConnection::Close() {
    close(SockDesc);
}
