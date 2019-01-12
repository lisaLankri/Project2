#ifndef SERVER_MYSERIALSERVER_H
#define SERVER_MYSERIALSERVER_H

#include <pthread.h>
#include "Server.h"
#include <thread>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string>
#include <strings.h>
#include <sys/socket.h>
#include <chrono>
#include <thread>
#include <string.h>
#include "ClientHandler.h"
#include "Utils.h"

using namespace std;

namespace server_side {
    template<class Problem, class Solution>
    class MySerialServer  : public Server<Problem, Solution>{
    public:
        MySerialServer() {}
        void open(int portNo, ClientHandler<Problem, Solution>* _clientHandler) override
        {
            this->portNo = portNo;
            this->clientHandler = _clientHandler;
            pthread_create(&serverThread, nullptr, runSerialServer, this);
        }

        void stop() override
        {
            pthread_join(serverThread, NULL);
        }
    private:
        static void* runSerialServer(void* arg)
        {
            MySerialServer* mySerialServer = (MySerialServer*)arg;
            struct sockaddr_in serv_addr, cli_addr;
            int portno, clilen;
            struct timeval      timeout;
            fd_set              master_set, working_set;
            /* First call to socket() function */
            int sockfd = socket(AF_INET, SOCK_STREAM, 0);

            if (sockfd < 0) {
                perror("ERROR opening socket");
                exit(1);
            }

            /* Initialize socket structure */
            bzero((char*) &serv_addr, sizeof(serv_addr));
            portno = mySerialServer->portNo;

            serv_addr.sin_family = AF_INET;
            serv_addr.sin_addr.s_addr = INADDR_ANY;
            serv_addr.sin_port = htons((u_int16_t )portno);

            /* Now bind the host address using bind() call.*/
            if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
                perror("ERROR on binding");
                exit(1);
            }

            /* Now start listening for the clients, here process will
               * go in sleep mode and will wait for the incoming connection
            */

            listen(sockfd, 5);
            clilen = sizeof(cli_addr);
            int newsockfd;
            bool firstTime = true;

            while(true) {
                FD_ZERO(&master_set);
                FD_SET(sockfd, &master_set);

                timeout.tv_sec  = 1;
                timeout.tv_usec = 0;
                memcpy(&working_set, &master_set, sizeof(master_set));

                struct timeval* realTimeout = firstTime ? NULL : &timeout;
                firstTime = false;
                if (select(sockfd + 1, &working_set, NULL, NULL, realTimeout) <= 0)
                {
                    //perror("ERROR on select");
                    break;
                    //exit(1);
                }
                /* Accept actual connection from the client */
                newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

                if (newsockfd < 0) {
                    perror("ERROR on accept");
                    exit(1);
                }
                mySerialServer->clientHandler->handleClient(newsockfd, newsockfd);
                close(newsockfd);
            }
            close(sockfd);

            return NULL;
        }
        pthread_t serverThread;
        int portNo;
        ClientHandler<Problem, Solution>* clientHandler;
    };
}

#endif //SERVER_MYSERIALSERVER_H
