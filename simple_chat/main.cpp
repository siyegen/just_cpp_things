#include <iostream>
#include <sys/types.h>       // For data types
#include <sys/socket.h>      // For socket(), connect(), send(), and recv()
#include <netdb.h>           // For gethostbyname()
#include <arpa/inet.h>       // For inet_addr()
#include <unistd.h>          // For close()
#include <netinet/in.h>      // For sockaddr_in
#include <array>

#include "simple_socket.h"

void rawServer();
void TCPListenServer();

int main() {
    std::cout << "Yo Server" << std::endl;
    // rawServer();
    TCPListenServer();
}

void TCPListenServer() {
    TCPListener Listener = TCPListener("", 9954);
    Listener.Listen(5);
    TCPConnection* Conn = Listener.Accept(); // Blocks
    
    SimpleConnBuffer Buff {};
    int ReadSize;
    while((ReadSize = Conn->Read(Buff)) > 0) {
        std::cout << "Client sent: " << std::string(Buff.begin(), Buff.end());
        std::cout << "(" << ReadSize << ")" << std::endl;
        int WriteSize = Conn->Write(Buff, ReadSize);
        if (WriteSize < 0) {
            std::cout << "Failed to send" << std::endl;
        }
        std::cout << "Wrote bytes: " << WriteSize << std::endl;
        memset(&Buff, 0, WriteSize);
    }
    Conn->Close();
    Listener.Close();
    delete Conn;
}

void rawServer() {
    unsigned short port = 9954;

    // Create serverSocket
    int sockDesc = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockDesc < 0) {
        std::cout << "Failed to create socket" << std::endl;
        exit(1);
    }
    sockaddr_in LocalAddr;
    memset(&LocalAddr, 0, sizeof(LocalAddr));
    LocalAddr.sin_family = AF_INET;
    LocalAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    // LocalAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    LocalAddr.sin_port = htons(port);

    // bind socket to address
    if(bind(sockDesc, (sockaddr*) &LocalAddr, sizeof(sockaddr_in)) < 0) {
        std::cout << "Failed to bind port" << std::endl;
        exit(1);
    }
    
    // start listening
    if(listen(sockDesc, 5) < 0) {
        std::cout << "Unable to listen" << std::endl;
        exit(1);
    }

    // Accept on the socket, accept() blocks
    int ClientSockDesc = accept(sockDesc, nullptr, 0); // returns new FD for new socket
    if(ClientSockDesc < 0) {
        std::cout << "Failed to accept connection" << std::endl;
        exit(1);
    }
    // create buffer to hold data
    std::array<char, 32> myBuffer;
    memset(&myBuffer, 0, 32);
    // recv data and store in buffer
    int recvMsgSize;
    while((recvMsgSize = recv(ClientSockDesc, &myBuffer, myBuffer.size(), 0))>0) {
        std::cout << "Client: " << myBuffer.data() << " ->b " << recvMsgSize << std::endl;
        // send the data back over
        int sendSize = send(ClientSockDesc, &myBuffer, recvMsgSize, 0);
        if (sendSize < 0) {
            std::cout << "Failed to send" << std::endl;
        }
        std::cout << "Wrote bytes: " << sendSize << std::endl;
        memset(&myBuffer, 0, sendSize);
    }
    // close connection
    close(sockDesc);
    close(ClientSockDesc);
}
