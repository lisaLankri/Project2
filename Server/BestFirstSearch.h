#ifndef SERVER_BESTFIRSTSEARCH_H
#define SERVER_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include <stdio.h>
#include <set>
#include <iostream>

template <class T>
class BestFirstSearch : public Searcher<T> {
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
            for (typename vector<State<T>*>::iterator it = succerssors.begin();
                it != succerssors.end(); ++it)
            {
                if((find(closed, (*it)) == closed.end()) && !Searcher<T>::openContains(*it))
                {
                    Searcher<T>::addToOpenList(*it);
                }
                else
                {
                    typename set<State<T>*>::iterator a = find(closed, (*it));
                    if ((a != closed.end()) && ((*a)->getCost() > (*it)->getCost()))
                    {
                        if (!Searcher<T>::openContains(*it)) {
                            Searcher<T>::addToOpenList(*it);
                        } else {
                            typename set<State<T>*>::iterator b = find(closed, (*it)->getCameFrom());
                            ((State<T>*)(*a))->setCost((*it)->getCost());
                            ((State<T>*)(*a))->setCameFrom((State<T>*)(&(*b)));
                        }
                    }

                }

            }

        }

        cout << "Failed to Finished successfully" << endl;
        return NULL;
    }

};


#endif //SERVER_BESTFIRSTSEARCH_H
