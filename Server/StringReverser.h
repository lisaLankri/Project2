#ifndef SERVER_STRINGREVERSER_H
#define SERVER_STRINGREVERSER_H

#include "Solver.h"
#include <string>

using namespace std;

namespace server_side {
    class StringReverser : public  Solver<string, string>{
    public:
        virtual string* solve(string*);

    };
}

#endif //SERVER_STRINGREVERSER_H
