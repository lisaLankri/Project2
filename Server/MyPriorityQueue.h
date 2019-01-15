#ifndef SERVER_MYPRIORITYQUEUE_H
#define SERVER_MYPRIORITYQUEUE_H

#include <queue>
#include <vector>

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
            if (**first==*t1) return true;
            ++first;
        }
        return false;
    }
    typename T2::iterator find(const T1& t1)
    {
        auto first = this->c.begin();
        auto last = this->c.end();
        while (first!=last) {
            if (**first==*t1) return first;
            ++first;
        }
        return last;
    }

};


#endif //SERVER_MYPRIORITYQUEUE_H
