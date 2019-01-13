#ifndef SERVER_ASTAR_H
#define SERVER_ASTAR_H

#include "Searcher.h"
#include "AutoDeleteVector.h"
#include <vector>

using namespace std;

template <class T>
class AStar : public Searcher<T> {
public:
    virtual Solution<T>* search (Searchable<T>& searchable)
    {
        AutoDeleteVector<State<T>*> allStates;
        std::set<State<T>*> closed;
        State<T>* initialState = searchable.getInitialState();
        State<T>* goal = searchable.getGoalState();
        allStates.push_back(initialState);
        allStates.push_back(goal);
        Searcher<T>::addToOpenList(initialState);
        while(Searcher<T>::getOpenListSize() > 0) {
            State<T>* n = Searcher<T>::popOpenList();
            closed.insert(n);
            if(*n == *goal) {
                cout << "Finished successfully" << endl;
                Searcher<T>::setCost(n->getCost());
                return this->backTrace(n);
            }
            vector<State<T>*> succerssors = searchable.getAllPossibleStates(n);
            allStates.insert(allStates.end(), succerssors.begin(), succerssors.end());
            for (typename vector<State<T>*>::iterator it = succerssors.begin();
                 it != succerssors.end(); ++it)
            {
                if (Searcher<T>::openContains(*it))
                {
                    State<T>* state = *Searcher<T>::getState(*it);
                    if ((state != nullptr) && (state->getCost() < (*it)->getCost()))
                    {
                        state->setCost((*it)->getCost());
                        state->setCameFrom((*it)->getCameFrom());
                    }
                }
                else
                {
                    Searcher<T>::addToOpenList(*it);
                }
            }

        }

        cout << "Failed to Finished successfully" << endl;
        return NULL;
    }

};


#endif //SERVER_ASTAR_H
