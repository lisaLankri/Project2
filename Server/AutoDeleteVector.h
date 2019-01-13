#ifndef SERVER_AUTODELETEVECTOR_H
#define SERVER_AUTODELETEVECTOR_H

#include <list>

using namespace std;

template <class T>
class AutoDeleteVector : public list<T> {
public:
    ~AutoDeleteVector()
    {
        for (typename list<T>::iterator it = list<T>::begin();
             it != list<T>::end(); ++it)
        {
            delete (*it);
        }
    }

};

#endif //SERVER_AUTODELETEVECTOR_H
