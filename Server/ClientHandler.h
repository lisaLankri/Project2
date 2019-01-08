#ifndef SERVER_CLIENTHANDLER_H
#define SERVER_CLIENTHANDLER_H

namespace server_side {
    class ClientHandler {
    public:
        virtual void handleClient(int inputPort, int outputPort) = 0;

    };
}

#endif //SERVER_CLIENTHANDLER_H
