#include "MatrixFileCacheManager.h"
#include "Utils.h"
#include <fstream>

server_side::MatrixFileCacheManager::MatrixFileCacheManager(string _fileName) : fileName(_fileName)
{
    string key;
    vector<string> value;
    std::string line;
    bool newReadKey = true;
    ifstream fs("cache.txt");
    while (std::getline(fs, line))
    {
        if (line.empty())
            continue;
        if (newReadKey)
        {
            key = line;
        }
        else
        {
            Utils::tokenize(line, value, ",");
            solutions[key] = value;
        }
        newReadKey = !newReadKey;

    }
    fs.close();
}

server_side::MatrixFileCacheManager::~MatrixFileCacheManager()
{
}

bool server_side::MatrixFileCacheManager::isSolutionCashed(string* s)
{
    return solutions.find(*s) != solutions.end() ;
}

vector<string>* server_side::MatrixFileCacheManager::getSolution(string* s)
{
    vector<string> value = solutions[*s];
    vector<string>* answer = new vector<string>;
    answer->insert(answer->end(), value.begin(), value.end());
    return answer;
}

void server_side::MatrixFileCacheManager::cache(string* p, vector<string>* s)
{
    solutions[*p] = *s;
    ofstream fs;
    fs.open ("cache.txt", std::ofstream::out | std::ofstream::app);
    fs << (*p) << endl;
    for (int i = 0; i < s->size(); i++)
    {
        fs << (*s)[i];
        if (i < s->size() - 1)
            fs << ",";
    }
    fs << endl;
    fs.close();
}
