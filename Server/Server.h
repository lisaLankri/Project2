#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

namespace server_side {
    class ClientHandler;
    class Server {
    public:
        virtual void open(int portNo, ClientHandler*) = 0;
        virtual void stop() = 0;

    };

}
#endif //SERVER_SERVER_H
