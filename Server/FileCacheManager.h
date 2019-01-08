#ifndef SERVER_FILECACHEMANAGER_H
#define SERVER_FILECACHEMANAGER_H

#include <string>
#include "CacheManager.h"

using namespace std;

namespace server_side {

    class FileCacheManager : public CacheManager<string, string>{
    public:
        FileCacheManager(string fileName);
        ~FileCacheManager();
        virtual bool isSolutionCashed(string*);
        virtual string* getSolution(string*);
        virtual void cache(string* p, string* s);
    };
}

#endif //SERVER_FILECACHEMANAGER_H
