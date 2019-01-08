#ifndef SERVER_CACHEMANAGER_H
#define SERVER_CACHEMANAGER_H

namespace server_side {
    template<class Problem, class Solution>
    class CacheManager {
        virtual bool isSolutionCashed(Problem*) = 0;
        virtual Solution* getSolution(Problem*) = 0;
        virtual void cache(Problem* p, Solution* s) = 0;

    };
}

#endif //SERVER_CACHEMANAGER_H
