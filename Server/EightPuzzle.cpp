#include "EightPuzzle.h"

State<string>* EightPuzzle::getInitialState()
{
    return new State<string>("3124756 8");
    //return State<string>("12 345678");
    //return State<string>("8 6547231");
}

State<string>* EightPuzzle::getGoalState()
{
    return new State<string>(" 12345678");
}

#define NUM 3

string convert(char stateMatrix[NUM][NUM])
{
    string result;
    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < NUM; j++) {
            result += stateMatrix[i][j];
        }
    }
    return result;
}

vector<State<string>*> EightPuzzle::getAllPossibleStates(State<string>* s)
{
    vector<State<string>*> possibleStates;
    char stateMatrix[NUM][NUM];
    string stateStr = s->getState();
    int i, j, index;
    for (i = 0; i < NUM; i++){
        for (j = 0; j < NUM; j++){
            stateMatrix[i][j] = stateStr[i * NUM + j];
        }
    }
    index = s->getState().find_first_of(' ');
    int x, y;
    x = index / NUM;
    y = index % NUM;
    if (x > 0)
    {
        stateMatrix[x][y] = stateMatrix[x - 1][y];
        stateMatrix[x - 1][y] = ' ';
        possibleStates.push_back(new State<string>(convert(stateMatrix)));
        stateMatrix[x - 1][y] = stateMatrix[x][y];
        stateMatrix[x][y] = ' ';
    }
    if (y > 0)
    {
        stateMatrix[x][y] = stateMatrix[x][y - 1];
        stateMatrix[x][y - 1] = ' ';
        possibleStates.push_back(new State<string>(convert(stateMatrix)));
        stateMatrix[x][y - 1] = stateMatrix[x][y];
        stateMatrix[x][y] = ' ';
    }
    if (x < NUM - 1)
    {
        stateMatrix[x][y] = stateMatrix[x + 1][y];
        stateMatrix[x + 1][y] = ' ';
        possibleStates.push_back(new State<string>(convert(stateMatrix)));
        stateMatrix[x + 1][y] = stateMatrix[x][y];
        stateMatrix[x][y] = ' ';
    }
    if (y < NUM - 1)
    {
        stateMatrix[x][y] = stateMatrix[x][y + 1];
        stateMatrix[x][y + 1] = ' ';
        possibleStates.push_back(new State<string>(convert(stateMatrix)));
        stateMatrix[x][y + 1] = stateMatrix[x][y];
        stateMatrix[x][y] = ' ';
    }
    for (vector<State<string>*>::iterator it = possibleStates.begin();
        it != possibleStates.end(); ++it)
    {
        (*it)->setCameFrom(s);
        (*it)->setCost(s->getCost() + 1);
    }
    return possibleStates;
}
