#ifndef SERVER_MYSOLVER_H
#define SERVER_MYSOLVER_H

#include "Solver.h"
#include "DFS.h"
#include "MatrixDomain.h"

namespace server_side {
    template<class Problem, class Solution>
    class MySolver : public Solver<Problem, Solution>{
    public:
        virtual Solution* solve(Problem* problem)
        {
            DFS<Point> dfs;
            MatrixDomain md(problem);
            Solution* solution = dfs.search(md);
            if (solution == nullptr)
                return;
            /*for (typename vector<T>::iterator it = solution->begin(); it != solution->end(); ++it)
            {
                cout << (*it) << endl;
            }*/
            cout << "Cost: " << dfs.getCost() << endl;
            int n = dfs.getNumberOfNodesEvaluated();
            cout << "Number Of Nodes Evaluated: " << n << endl;
            ////// create test with searcher and searchable
            return 0;////////////////////////
        }

    };
}


#endif //SERVER_MYSOLVER_H
