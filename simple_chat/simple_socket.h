#include <sys/types.h>       // For data types
#include <sys/socket.h>      // For socket(), connect(), send(), and recv()
#include <netdb.h>           // For gethostbyname()
#include <arpa/inet.h>       // For inet_addr()
#include <unistd.h>          // For close()
#include <netinet/in.h>      // For sockaddr_in
#include <string.h>
#include <string>
#include <array>

class SimpleSocket {
public:
    ~SimpleSocket();
protected:
    int sockDesc;
};

class TCPConnection {
public:
    ~TCPConnection();
    
    // read from connection into buffer<char>, return bytes written
    int Read(std::array<char,255> &Buffer);
    int Write(std::array<char,255> &Buffer, int WriteSize);
    void Close();

protected:
    int SockDesc;
private:
    TCPConnection(int SockDesc);
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

// TcpListener, creates socket and holds listener
// .accept() returns a *connection*
// connection has read/write on it