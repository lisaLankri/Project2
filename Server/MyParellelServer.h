#ifndef SERVER_MYPARELLELSERVER_H
#define SERVER_MYPARELLELSERVER_H


#include "Server.h"

namespace server_side {
    template<class Problem, class Solution>
    class MyParellelServer  : public Server<Problem, Solution>{
    public:
        MyParellelServer();
        void open(int portNo, ClientHandler<Problem, Solution>**) override;
        void stop() override;
    };
}


#endif //SERVER_MYPARELLELSERVER_H
