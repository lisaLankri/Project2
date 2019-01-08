#ifndef SERVER_MYTESTCLIENTHANDLER_H
#define SERVER_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"

class MyTestClientHandler : public server_side::ClientHandler {
public:
    virtual void handleClient(int inputPort, int outputPort);

};


#endif //SERVER_MYTESTCLIENTHANDLER_H
