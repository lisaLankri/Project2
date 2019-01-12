#ifndef SERVER_MYSOLVER_H
#define SERVER_MYSOLVER_H

#include "Solver.h"
#include "DFS.h"
#include "MatrixDomain.h"
#include "Point.h"
#include "BestFirstSearch.h"
#include "AStar.h"
#include "BFS.h"

namespace server_side {
    class MySolver : public Solver<string, vector<string>>{
    public:
        virtual vector<string>* solve(string* problem)
        {
            //DFS<string> dfs;
            MatrixDomain md(*problem);
            //BestFirstSearch<string> bfs;
            //AStar<string> bfs;
            BFS<string> bfs;
            vector<string>* solution = bfs.search(md);
            if (solution == nullptr)
                return nullptr;
            /*for (typename vector<T>::iterator it = solution->begin(); it != solution->end(); ++it)
            {
                cout << (*it) << endl;
            }*/
            cout << "Cost: " << bfs.getCost() << endl;
            //int n = bfs.getNumberOfNodesEvaluated();
            //cout << "Number Of Nodes Evaluated: " << n << endl;
            cout << "Path length: " << solution->size() << endl;
            vector<string>* steps = new vector<string>();
            for (int i = 0; i < solution->size() - 1; i++)
            {
                Point current = Point::fromString((*solution)[i]);
                Point next = Point::fromString((*solution)[i + 1]);
                if (current.getX() < next.getX())
                    steps->push_back("Right");
                else
                if (current.getX() > next.getX())
                    steps->push_back("Left");
                else
                if (current.getY() < next.getY())
                    steps->push_back("Down");
                else
                if (current.getY() > next.getY())
                    steps->push_back("Up");
            }
            delete solution;
            return steps;
        }

    };
}


#endif //SERVER_MYSOLVER_H
