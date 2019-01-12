#ifndef SERVER_MATRIXFILECACHEMANAGER_H
#define SERVER_MATRIXFILECACHEMANAGER_H

#include <string>
#include <vector>
#include "CacheManager.h"
#include "Point.h"

using namespace std;

namespace server_side {
    class MatrixFileCacheManager : public CacheManager<string, vector<string>> {
    public:
        MatrixFileCacheManager(string fileName);
        ~MatrixFileCacheManager();
        virtual bool isSolutionCashed(string*);
        virtual vector<string>* getSolution(string*);
        virtual void cache(string* p, vector<string>* s);

    private:
        string fileName;
    };
}

#endif //SERVER_MATRIXFILECACHEMANAGER_H
