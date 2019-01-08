#ifndef SERVER_MYPARELLELSERVER_H
#define SERVER_MYPARELLELSERVER_H


#include "Server.h"

namespace server_side {
    class MyParellelServer  : public Server{
    public:
        MyParellelServer();
        void open(int portNo, ClientHandler*) override;
        void stop() override;
    };
}


#endif //SERVER_MYPARELLELSERVER_H
