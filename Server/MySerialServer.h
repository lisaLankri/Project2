#ifndef SERVER_MYSERIALSERVER_H
#define SERVER_MYSERIALSERVER_H

#include <pthread.h>
#include "Server.h"

namespace server_side {
    class MySerialServer  : public Server{
    public:
        MySerialServer();
        void open(int portNo, ClientHandler*) override;

        void stop() override;
    private:
        static void* runSerialServer(void* arg);
        pthread_t serverThread;
        int portNo;
        ClientHandler* clientHandler;
    };
}

#endif //SERVER_MYSERIALSERVER_H
