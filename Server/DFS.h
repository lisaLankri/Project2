#ifndef SERVER_DFS_H
#define SERVER_DFS_H

#include "Searcher.h"
#include "AutoDeleteVector.h"
#include <stack>
#include <set>

using namespace std;

template <class T>
class DFS : public Searcher<T> {
public:
    virtual Solution<T>* search (Searchable<T>& searchable)
    {
        AutoDeleteVector<State<T>*> allStates;
        queue<State<T>*> s;
        std::set<State<T>*> closed;
        State<T>* initialState = searchable.getInitialState();
        State<T>* goal = searchable.getGoalState();
        s.push(initialState);
        allStates.push_back(initialState);
        allStates.push_back(goal);
        Searcher<T>::evaluatedNodes++;
        while(s.size() != 0)
        {
            State<T>* v = s.front();
            s.pop();
            if(*v == *goal) {
                cout << "Finished successfully" << endl;
                Searcher<T>::setCost(v->getCost());
                return this->backTrace(v);
            }
            if(find(closed, v) == closed.end())
            {
                closed.insert(v);
                vector<State<T>*> succerssors = searchable.getAllPossibleStates(v);
                allStates.insert(allStates.end(), succerssors.begin(), succerssors.end());
                for (typename vector<State<T>*>::iterator it = succerssors.begin();
                     it != succerssors.end(); ++it)
                {
                    if(find(closed, *it) == closed.end()) {
                        s.push(*it);
                        Searcher<T>::evaluatedNodes++;
                    }
                }
            }
        }
        cout << "Failed to Finished successfully" << endl;
        return nullptr;
    }

};


#endif //SERVER_DFS_H
