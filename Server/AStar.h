#ifndef SERVER_ASTAR_H
#define SERVER_ASTAR_H

#include "Searcher.h"
#include <vector>

using namespace std;

template <class T>
class AStar : public Searcher<T> {
public:
    virtual Solution<T>* search (Searchable<T>& searchable)
    {
        Searcher<T>::addToOpenList(searchable.getInitialState());
        std::set<State<T>*> closed;
        State<T>* goal = searchable.getGoalState();
        while(Searcher<T>::getOpenListSize() > 0) {
            State<T>* n = Searcher<T>::popOpenList();
            closed.insert(n);
            if(*n == *goal) {
                cout << "Finished successfully" << endl;
                Searcher<T>::setCost(n->getCost());
                return this->backTrace(n);
            }
            vector<State<T>*> succerssors = searchable.getAllPossibleStates(n);
            int minCost = -1;
            State<T>* minCostState = nullptr;
            for (typename vector<State<T>*>::iterator it = succerssors.begin();
                 it != succerssors.end(); ++it)
            {
                typename set<State<T>*>::iterator a = find(closed, (*it));
                if(a == closed.end())
                {
                    if ((minCostState == nullptr) || (minCost > (*it)->getCost()))
                    {
                        minCostState = (*it);
                        minCost = minCost > (*it)->getCost();
                    }
                }
            }
            if (minCostState != nullptr)
            {
                Searcher<T>::addToOpenList(minCostState);
                closed.insert(minCostState);
            }

        }

        cout << "Failed to Finished successfully" << endl;
        return NULL;
    }

};


#endif //SERVER_ASTAR_H
