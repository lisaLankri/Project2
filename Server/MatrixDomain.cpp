#include "MatrixDomain.h"

MatrixDomain::MatrixDomain(int** _matrix, int _size,
        int startx, int starty, int endx, int endy) :
        matrix(_matrix), size(_size), start(startx, starty), end(endx, endy)
{
}

MatrixDomain::~MatrixDomain()
{
    for (int j = 0; j < size; j++)
    {
        delete[] matrix[j];
    }
    delete[] matrix;
}

State<Point>* MatrixDomain::getInitialState()
{
    State<Point>* initialState = new State<Point>(Point(start));
    initialState->setCost(matrix[start.getX()][start.getY()]);
    return initialState;
}

State<Point>* MatrixDomain::getGoalState()
{
    State<Point>* endState = new State<Point>(Point(end));
    endState->setCost(matrix[end.getX()][end.getY()]);
    return endState;
}

#define INFINITE -1

vector<State<Point>*> MatrixDomain::getAllPossibleStates(State<Point>* p)
{
    vector<State<Point>*> possibleStates;
    int x = p->getState().getX();
    int y = p->getState().getY();
    State<Point>* newState;
    if ((x > 0) && (matrix[x - 1][y] != INFINITE))
    {
        newState = new State<Point>(Point(x - 1, y));
        newState->setCost(p->getCost() + matrix[x - 1][y]);
        possibleStates.push_back(newState);
    }
    if ((y > 0) && (matrix[x][y - 1] != INFINITE))
    {
        newState = new State<Point>(Point(x, y - 1));
        newState->setCost(p->getCost() + matrix[x][y - 1]);
        possibleStates.push_back(newState);
    }
    if ((x < size - 1) && (matrix[x + 1][y] != INFINITE))
    {
        newState = new State<Point>(Point(x + 1, y));
        newState->setCost(p->getCost() + matrix[x + 1][y]);
        possibleStates.push_back(newState);
    }
    if ((y < size - 1) && (matrix[x][y + 1] != INFINITE))
    {
        newState = new State<Point>(Point(x, y + 1));
        newState->setCost(p->getCost() + matrix[x][y + 1]);
        possibleStates.push_back(newState);
    }
    for (vector<State<Point>*>::iterator it = possibleStates.begin();
         it != possibleStates.end(); ++it)
    {
        (*it)->setCameFrom(p);
    }
    return possibleStates;
}

std::ostream& operator<<(std::ostream& os, const Point& obj)
{
    os << obj.getX() << "," << obj.getY();
    return os;
}
