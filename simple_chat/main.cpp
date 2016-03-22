#include <iostream>
#include <sys/types.h>       // For data types
#include <sys/socket.h>      // For socket(), connect(), send(), and recv()
#include <netdb.h>           // For gethostbyname()
#include <arpa/inet.h>       // For inet_addr()
#include <unistd.h>          // For close()
#include <netinet/in.h>      // For sockaddr_in
#include <pthread.h>
#include <signal.h>

#include "simple_socket.h"

void TCPListenServer();
void* HandlePThread(void* Conn);

void shutdown_handler(int s) {
    std::cout << "Caught signal: " << s << std::endl;
    exit(1);
}

int main() {
    std::cout << "Yo Server2" << std::endl;
    struct sigaction sigIntHandler;
    
    sigIntHandler.sa_handler = shutdown_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, nullptr);

    TCPListenServer();
}

void TCPListenServer() {
    TCPListener Listener = TCPListener("", 9954);
    Listener.Listen(5);
    
    for (;;) {
        TCPConnection* Conn = Listener.Accept(); 
        pthread_t ThreadID;
        if (pthread_create(&ThreadID, nullptr, HandlePThread, (void*)Conn) != 0) {
            std::cerr << "Unable to create thread" << std::endl;
            Conn->Close();
            delete Conn;
            return;
        }    
    }
    
}

void* HandlePThread(void* Conn) {
    pthread_detach(pthread_self());
    TCPConnection* ClientConn = (TCPConnection*)Conn;
    
    SimpleConnBuffer Buff {};
    int ReadSize;
    while((ReadSize = ClientConn->Read(Buff)) > 0) {
        std::cout << "Client["<< ClientConn->GetAddr() << "] sent: " << std::string(Buff.begin(), Buff.end());
        std::cout << "(" << ReadSize << ")" << std::endl;
        int WriteSize = ClientConn->Write(Buff, ReadSize);
        if (WriteSize < 0) {
            std::cout << "Failed to send" << std::endl;
        }
        std::cout << "Wrote bytes: " << WriteSize << std::endl;
        memset(&Buff, 0, WriteSize);
    }
    std::cout << "Closing: " << ClientConn->GetAddr() << std::endl;
    ClientConn->Close();
    
    delete ClientConn;
    return nullptr;
}
