#ifndef SERVER_MATRIXDOMAIN_H
#define SERVER_MATRIXDOMAIN_H

#include "Searchable.h"
#include <iostream>
#include "Point.h"


class MatrixDomain : public Searchable<string> {
public:
    MatrixDomain(int** matrix, int size, int startx, int starty, int endx, int endy);
    MatrixDomain(string& strings);
    ~MatrixDomain();
    virtual State<string>* getInitialState();
    virtual State<string>* getGoalState();
    virtual vector<State<string>*> getAllPossibleStates(State<string>* p);

private:
    int** matrix;
    int sizex, sizey;
    Point start, end;
};


#endif //SERVER_MATRIXDOMAIN_H
