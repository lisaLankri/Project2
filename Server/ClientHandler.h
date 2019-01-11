#ifndef SERVER_CLIENTHANDLER_H
#define SERVER_CLIENTHANDLER_H

#include "Solver.h"
#include "CacheManager.h"

namespace server_side {
    template<class Problem, class Solution>
    class ClientHandler {
    public:
        ClientHandler(Solver<Problem, Solution>* _solver,
                CacheManager<Problem, Solution>* _cm) : solver(_solver), cm(_cm) {}
        virtual void handleClient(int inputPort, int outputPort) = 0;

    protected:
        Solver<Problem, Solution>* solver;
        CacheManager<Problem, Solution>* cm;
    };
}

#endif //SERVER_CLIENTHANDLER_H
