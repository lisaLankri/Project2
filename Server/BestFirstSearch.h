#ifndef SERVER_BESTFIRSTSEARCH_H
#define SERVER_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include <stdio.h>
#include <set>
#include <iostream>

template <class T>
class BestFirstSearch : public Searcher<T> {
private:
    typename set<State<T>>::iterator find(std::set<State<T>>& setOfStates, State<T>& s)
    {
        for (typename set<State<T>>::iterator it = setOfStates.begin();
             it != setOfStates.end(); ++it)
        {
            if (s == (*it))
                return it;
        }
        return setOfStates.end();
    }
public:
    virtual Solution* search (Searchable<T>& searchable)
    {
        Searcher<T>::addToOpenList(searchable.getInitialState());
        ///////std::set<State<T>, bool(*)(const State<T>& lhs, const State<T>& rhs)> closed(&comparator);
        std::set<State<T>> closed;
        while(Searcher<T>::getOpenListSize() > 0) {
            State<T> n = Searcher<T>::popOpenList();
            closed.insert(n);
            if(n == searchable.getGoalState())
                return this->backTrace(n);
            vector<State<T>> succerssors = searchable.getAllPossibleStates(n);
            //double cost = -1;
            for (typename vector<State<T>>::iterator it = succerssors.begin();
                it != succerssors.end(); ++it)
            {
                /*typename set<State<T>>::iterator z = closed.find(*it);
                if (closed.find(*it) == closed.end())
                {
                    std::cout << "bbb" << std::endl;
                }
                if (!Searcher<T>::openContains(*it))
                {
                    std::cout << "aaa" << std::endl;
                }*/
                //////if((closed.find(*it) == closed.end()) && !Searcher<T>::openContains(*it))
                if((find(closed, (*it)) == closed.end()) && !Searcher<T>::openContains(*it))
                {
                    Searcher<T>::addToOpenList(*it);
                }
                else
                {
                    /////typename set<State<T>>::iterator a = closed.find(*it);
                    typename set<State<T>>::iterator a = find(closed, (*it));
                    /*if (a != closed.end())
                    {
                        std::cout << "AAAAAAAAAAAAAs" << std::endl;
                    }*/
                    if ((a != closed.end()) && ((*a).getCost() > (*it).getCost()))
                    //double tempCost = (*it).getCost();
                    //cout << tempCost << endl;
                    //if ((cost == -1) || ((*it).getCost() < cost))
                    {
                        std::cout << "BBBBBBBBBBBB" << std::endl;
                        //cost = (*it).getCost();
                        if (!Searcher<T>::openContains(*it)) {
                            Searcher<T>::addToOpenList(*it);
                            std::cout << "TTTTTTTT" << std::endl;
                            exit(0);
                        } else {
                            /////// adjust its priority in OPEN
                            std::cout << "SSSSSSSSSS" << std::endl;
                            /////typename set<State<T>>::iterator b = closed.find(*(*it).getCameFrom());
                            typename set<State<T>>::iterator b = find(closed, (*(*it).getCameFrom()));
                            ((State<T>&)(*a)).setCost((*it).getCost());
                            ((State<T>&)(*a)).setCameFrom((State<T>*)(&(*b)));
                        }
                    }

                }

            }

        }

        return NULL;
    }

};


#endif //SERVER_BESTFIRSTSEARCH_H
