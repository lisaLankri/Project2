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
#include "Point.h"
#include "Utils.h"
#include <vector>
#include <iostream>

using namespace std;

class MyTestClientHandler : public server_side::ClientHandler<string, vector<string>> {
public:
    MyTestClientHandler(server_side::Solver<string, vector<string>>* _solver,
                        server_side::CacheManager<string, vector<string>>* _cm) :
                        server_side::ClientHandler<string, vector<string>>(_solver, _cm) {}
    virtual void handleClient(int inputPort, int outputPort)
    {
        char buffer[BUFFER_SIZE];
        vector<string> strings;
        int n;
        bool error = false;
        bool finish = false;
        while (! finish) {
            n = read(inputPort, buffer, BUFFER_SIZE - 1);
            if (n < 0)
            {
                error = true;
                break;
            }
            buffer[n] = '\0';
            //cout << "buffer: " << buffer << endl;
            if ((strlen(buffer) >= 3) && strcmp(&buffer[strlen(buffer) - 3], "end") == 0) // finish
            {
                buffer[strlen(buffer) - 3] = '\0';
                if (strlen(buffer) == 0)
                    break;
                finish = true;
            }
            string problem = buffer;
            if (problem[problem.size() - 5] == '\r')
                problem = problem.substr(0, problem.size() - 1);
            strings.push_back(problem);
        }
        if (! error)
        {
            vector<string>* solution = nullptr;
            string problem;
            for (vector<string>::iterator it = strings.begin(); it != strings.end(); ++it)
            {
                problem += (*it);// + "$";
            }
            problem = problem.substr(0, problem.size() - 1); // remove the last $
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
                string strSolution;
                for (vector<string>::iterator it = solution->begin(); it != solution->end(); ++it)
                {
                    strSolution += (*it) + ",";
                }
                strSolution = strSolution.substr(0, strSolution.size() - 1); // remove the last ,
                n = write(outputPort, strSolution.c_str(), strSolution.size());
                delete solution;
            }
        }
    }

};


#endif //SERVER_MYTESTCLIENTHANDLER_H
