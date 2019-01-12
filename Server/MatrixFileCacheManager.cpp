#include "MatrixFileCacheManager.h"

server_side::MatrixFileCacheManager::MatrixFileCacheManager(string _fileName) : fileName(_fileName)
{

}

server_side::MatrixFileCacheManager::~MatrixFileCacheManager()
{
    ///// close the file
}

bool server_side::MatrixFileCacheManager::isSolutionCashed(string*)
{
    ////////////
    return false;
}

vector<string>* server_side::MatrixFileCacheManager::getSolution(string*)
{
    ////////////
}

void server_side::MatrixFileCacheManager::cache(string* p, vector<string>* s)
{
    ////////////
}
