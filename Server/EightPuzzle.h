#ifndef SERVER_EIGHTPUZZLE_H
#define SERVER_EIGHTPUZZLE_H

#include "Searchable.h"
#include <string>

using namespace std;

class EightPuzzle : public Searchable<string> {
public:
    virtual State<string>* getInitialState();
    virtual State<string>* getGoalState();
    virtual vector<State<string>*> getAllPossibleStates(State<string>* s);
};


#endif //SERVER_EIGHTPUZZLE_H
