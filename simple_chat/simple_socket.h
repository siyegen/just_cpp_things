#include <sys/types.h>       // For data types
#include <sys/socket.h>      // For socket(), connect(), send(), and recv()
#include <netdb.h>           // For gethostbyname()
#include <arpa/inet.h>       // For inet_addr()
#include <unistd.h>          // For close()
#include <netinet/in.h>      // For sockaddr_in
#include <string>
#include <array>

using SimpleConnBuffer = std::array<char, 255>;

class TCPConnection {
public:
    // read from connection into buffer<char>, return bytes written
    int Read(SimpleConnBuffer &Buffer);
    int Write(SimpleConnBuffer &Buffer, int WriteSize);
    
    std::string ReadString(char delimiter);
    void Close();
    
    std::string GetAddr();

protected:
    int SockDesc;
    sockaddr_in ClientAddr;
private:
    TCPConnection(int SockDesc, sockaddr_in Addr);
    friend class TCPListener;
};

class TCPListener {
public:
    TCPListener(std::string addr, int port);
    
    void Listen(int queueLength);
    TCPConnection* Accept();
    void Close();

protected:
    int SockDesc;
    std::string Addr;
    int Port;
    sockaddr_in LocalAddr;
};
