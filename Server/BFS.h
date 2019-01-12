#ifndef SERVER_BFS_H
#define SERVER_BFS_H

#include "Searcher.h"
#include <stack>
#include <set>

using namespace std;

// implement Breadth First Search
template <class T>
class BFS : public Searcher<T> {
public:
    virtual Solution<T>* search (Searchable<T>& searchable)
    {
        stack<State<T>*> s;
        std::set<State<T>*> closed;
        State<T>* goal = searchable.getGoalState();
        s.push(searchable.getInitialState());
        Searcher<T>::evaluatedNodes++;
        while(s.size() != 0)
        {
            State<T>* v = s.top();
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


#endif //SERVER_BFS_H
