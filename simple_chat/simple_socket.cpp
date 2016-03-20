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

void TCPListener::Close() {
    close(SockDesc);
}

// Should return Connection
TCPConnection* TCPListener::Accept() {
    // change 2nd arg to store clientaddress info, 3rd will be size
    sockaddr_in ClientAddr;
    socklen_t ClientLen = sizeof(sockaddr_in);
    int ConectionSockDesc = accept(SockDesc, (sockaddr*) &ClientAddr, &ClientLen);
    TCPConnection* Connection = new TCPConnection(ConectionSockDesc);
    return Connection;
}

TCPConnection::TCPConnection(int sockDesc) {
    SockDesc = sockDesc;
}

int TCPConnection::Read(SimpleConnBuffer &Buffer) {
   return recv(SockDesc, &Buffer, Buffer.size(), 0);
}

std::string TCPConnection::ReadString(char delimiter) {
    std::string Result = "";
    int ReadSize;
    SimpleConnBuffer Buff;
    bool found = false;
    while((ReadSize = Read(Buff)) > 0) {
        if(found) continue; // drain rest of info from socket
        for(int i=0; i<Buff.size(); i++) {
            if(Buff.at(i) == delimiter) {
                found = true;
                // std::string(Buff.begin(), );
            }
        }
        if(!found) { // fill in everything so far
            Result += std::string(Buff.begin(), Buff.end());
        }
    }
    return Result;
}

int TCPConnection::Write(SimpleConnBuffer &Buffer, int WriteSize) {
    return send(SockDesc, &Buffer, WriteSize, 0);
}

void TCPConnection::Close() {
    close(SockDesc);
}
