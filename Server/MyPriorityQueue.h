#ifndef SERVER_MYPRIORITYQUEUE_H
#define SERVER_MYPRIORITYQUEUE_H

#include <queue>

using namespace std;

template <class T1, class T2, class T3>
class MyPriorityQueue : public priority_queue<T1, T2, T3> {
public:
    MyPriorityQueue() {}
    bool contains(const T1& t1)
    {
        auto first = this->c.begin();
        auto last = this->c.end();
        while (first!=last) {
            if (*first==t1) return true;
            ++first;
        }
        return false;
    }

};


#endif //SERVER_MYPRIORITYQUEUE_H