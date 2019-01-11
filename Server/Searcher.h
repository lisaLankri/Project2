#ifndef SERVER_SEARCHER_H
#define SERVER_SEARCHER_H

#include "Searchable.h"
#include "MyPriorityQueue.h"
#include <queue>

using namespace std;

class Solution;

template <class T>
class Searcher {
public:
    Searcher()
    {
        evaluatedNodes = 0;
    }
    int getOpenListSize()
    {
        return openList.size();
    }
    virtual Solution* search (Searchable<T>& searchable) = 0;
    int getNumberOfNodesEvaluated()
    {
        return evaluatedNodes;
    }

protected:
    Solution* backTrace(State<T> s)
    {
        return 0;/////////////
    }
    State<T> popOpenList()
    {
        evaluatedNodes++;
        State<T> state = openList.top();
        openList.pop();
        return state;
    }
    void addToOpenList(State<T> s)
    {
        openList.push(s);
    }
    bool openContains(State<T>& s)
    {
        return openList.contains(s);
    }
private:
    MyPriorityQueue<State<T>, std::vector<State<T>>, std::greater<State<T>>> openList;
    int evaluatedNodes;

};


#endif //SERVER_SEARCHER_H
