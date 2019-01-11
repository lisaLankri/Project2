#include "MatrixDomain.h"

MatrixDomain::MatrixDomain(int** _matrix, int _size,
        int startx, int starty, int endx, int endy) :
        matrix(_matrix), size(_size), start(startx, starty), end(endx, endy)
{
}

MatrixDomain::MatrixDomain(vector<string>& strings)
{
    matrix = new int*[strings.size() - 2];
    for (int i = 0; i < strings.size() - 2; i++)
    {
        matrix[i] = new int[strings.size() - 2];
        string str = strings[i];
        // create new line
        // Skip delimiters at beginning.
        string::size_type lastPos = str.find_first_not_of(",", 0);

        // Find first non-delimiter.
        string::size_type pos = str.find_first_of(",", lastPos);
        int j = 0;

        while (string::npos != pos || string::npos != lastPos) {
            // Found a token, add it to the vector.
            matrix[i][j++] = std::stoi(str.substr(lastPos, pos - lastPos));

            // Skip delimiters.
            lastPos = str.find_first_not_of(",", pos);

            // Find next non-delimiter.
            pos = str.find_first_of(",", lastPos);
        }
    }
    ////// update the start and end

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
