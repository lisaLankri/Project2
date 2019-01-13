#include "MatrixDomain.h"
#include "Utils.h"

MatrixDomain::MatrixDomain(int** _matrix, int _size,
        int startx, int starty, int endx, int endy) :
        matrix(_matrix), sizex(_size), sizey(_size), start(startx, starty), end(endx, endy)
{
}

MatrixDomain::MatrixDomain(string& input)
{
    vector<string> strings;
    Utils::tokenize(input, strings, "$");
    sizey = strings.size() - 2;
    matrix = new int*[sizey];
    sizex = 0;
    for (int i = 0; i < sizey; i++)
    {
        vector<string> numbers;
        Utils::tokenize(strings[i], numbers, ",");
        if (sizex == 0)
        {
            sizex = numbers.size();
        }
        matrix[i] = new int[sizex];
        for (int j = 0; j < sizex; j++)
        {
            matrix[i][j] = std::stoi(numbers[j]);
        }
    }
    // update the start and end
    start = Point::fromString(strings[strings.size() - 2]);
    end = Point::fromString(strings[strings.size() - 1]);
}

MatrixDomain::~MatrixDomain()
{
    for (int j = 0; j < sizey; j++)
    {
        delete[] matrix[j];
    }
    delete[] matrix;
}

State<string>* MatrixDomain::getInitialState()
{
    State<string>* initialState = new State<string>(start.toString());
    initialState->setCost(matrix[start.getX()][start.getY()]);
    return initialState;
}

State<string>* MatrixDomain::getGoalState()
{
    State<string>* endState = new State<string>(end.toString());
    endState->setCost(matrix[end.getX()][end.getY()]);
    return endState;
}

#define INFINITE -1

vector<State<string>*> MatrixDomain::getAllPossibleStates(State<string>* s)
{
    Point p = Point::fromString(s->getState());
    vector<State<string>*> possibleStates;
    int x = p.getX();
    int y = p.getY();
    State<string>* newState;
    if ((x > 0) && (matrix[x - 1][y] != INFINITE))
    {
        newState = new State<string>(Point(x - 1, y).toString());
        newState->setCost(s->getCost() + matrix[x - 1][y]);
        possibleStates.push_back(newState);
    }
    if ((y > 0) && (matrix[x][y - 1] != INFINITE))
    {
        newState = new State<string>(Point(x, y - 1).toString());
        newState->setCost(s->getCost() + matrix[x][y - 1]);
        possibleStates.push_back(newState);
    }
    if ((x < sizex - 1) && (matrix[x + 1][y] != INFINITE))
    {
        newState = new State<string>(Point(x + 1, y).toString());
        newState->setCost(s->getCost() + matrix[x + 1][y]);
        possibleStates.push_back(newState);
    }
    if ((y < sizey - 1) && (matrix[x][y + 1] != INFINITE))
    {
        newState = new State<string>(Point(x, y + 1).toString());
        newState->setCost(s->getCost() + matrix[x][y + 1]);
        possibleStates.push_back(newState);
    }
    for (vector<State<string>*>::iterator it = possibleStates.begin();
         it != possibleStates.end(); ++it)
    {
        (*it)->setCameFrom(s);
    }
    return possibleStates;
}

