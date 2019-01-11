#ifndef SERVER_SEARCHER_H
#define SERVER_SEARCHER_H

#include "Searchable.h"
#include "MyPriorityQueue.h"
#include <queue>
#include <iostream>
#include "Solution.h"

using namespace std;

template <class T>
class Searcher {
public:
    Searcher()
    {
        evaluatedNodes = 0;
        cost == 0;
    }
    int getOpenListSize()
    {
        return openList.size();
    }
    virtual Solution<T>* search (Searchable<T>& searchable) = 0;
    int getNumberOfNodesEvaluated()
    {
        return evaluatedNodes;
    }

    int getCost() const {
        return cost;
    }
protected:
    Solution<T>* backTrace(State<T>* s)
    {
        Solution<T>* solution = new Solution<T>;
        add(s, solution);
        return solution;
    }
    void add(State<T>* s, Solution<T>* solution)
    {
        if (s == nullptr)
            return;
        add(s->getCameFrom(), solution);
        solution->push_back(s->getState());
    }
    State<T>* popOpenList()
    {
        evaluatedNodes++;
        State<T>* state = openList.top();
        openList.pop();
        return state;
    }
    void addToOpenList(State<T>* s)
    {
        openList.push(s);
    }
    bool openContains(State<T>* s)
    {
        return openList.contains(s);
    }
    void setCost(int _cost)
    {
        cost = _cost;
    }

protected:
    int evaluatedNodes;
private:
    MyPriorityQueue<State<T>*, std::vector<State<T>*>, std::greater<State<T>*>> openList;
    int cost;

};


#endif //SERVER_SEARCHER_H
