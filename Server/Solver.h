#ifndef SERVER_SOLVER_H
#define SERVER_SOLVER_H

namespace server_side {
    template<class Problem, class Solution>
    class Solver {
    public:
        virtual Solution* solve(Problem*) = 0;

    };
}

#endif //SERVER_SOLVER_H
