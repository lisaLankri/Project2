#ifndef SERVER_MYTESTCLIENTHANDLER_H
#define SERVER_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include <string>
#include "Solver.h"
//#include <netdb.h>
#include <unistd.h>
//#include <netinet/in.h>
#include <string>
#include <string.h>
//#include <strings.h>
//#include <sys/socket.h>
#include "FileCacheManager.h"
#include "StringReverser.h"
#include <vector>
#include <iostream>

#define BUFFER_SIZE 1024

using namespace std;

class MyTestClientHandler : public server_side::ClientHandler<string, string> {
public:
    MyTestClientHandler(server_side::Solver<string, string>* _solver,
                        server_side::CacheManager<string, string>* _cm) :
                        server_side::ClientHandler<string, string>(_solver, _cm) {}
    virtual void handleClient(int inputPort, int outputPort)
    {
        ///////////// implement
        char buffer[BUFFER_SIZE];
        vector<string> strings;
        int n;
        bool error = false;
        while (true) {
            n = read(inputPort, buffer, BUFFER_SIZE);
            if (n < 0)
            {
                error = true;
                break;
            }
            buffer[n] = '\0';
            if (strcmp(buffer, "end") == 0) // finish
                break;
            string problem = buffer;
            strings.push_back(problem);
        }
        if (! error)
        {
            string* solution = nullptr;
            string problem;
            for (vector<string>::iterator it = strings.begin(); it != strings.end(); ++it)
            {
                problem += (*it) + "#";
            }
            problem = problem.substr(0, problem.size() - 1); // remove the last #
            if (cm->isSolutionCashed(&problem))
            {
                solution = cm->getSolution(&problem);
            }
            else {
                solution = solver->solve(&problem);
                cm->cache(&problem, solution);
            }

            if (solution != nullptr)
            {
                n = write(outputPort, solution->c_str(), solution->size());
                delete solution;
            }
        }
    }

};


#endif //SERVER_MYTESTCLIENTHANDLER_H
