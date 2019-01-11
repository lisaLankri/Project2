#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include "ClientHandler.h"

namespace server_side {
    template<class Problem, class Solution>
    class Server {
    public:
        virtual void open(int portNo, ClientHandler<Problem, Solution>*) = 0;
        virtual void stop() = 0;

    };

}
#endif //SERVER_SERVER_H
