#include "FileCacheManager.h"
#include <fstream>

server_side::FileCacheManager::FileCacheManager(string _fileName) : fileName(_fileName)
{
    string key;
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
            solutions[key] = line;
        }
        newReadKey = !newReadKey;

    }
    fs.close();
}

server_side::FileCacheManager::~FileCacheManager()
{
}

bool server_side::FileCacheManager::isSolutionCashed(string* s)
{
    return solutions.find(*s) != solutions.end() ;
}

string* server_side::FileCacheManager::getSolution(string* s)
{
    string* answer = new string(*s);
    return answer;
}

void server_side::FileCacheManager::cache(string* p, string* s)
{
    solutions[*p] = *s;
    ofstream fs;
    fs.open ("cache.txt", std::ofstream::out | std::ofstream::app);
    fs << (*p) << endl;
    fs << (*s) << endl;
    fs.close();
}
