#include "MyTestClientHandler.h"
//#include <netdb.h>
#include <unistd.h>
//#include <netinet/in.h>
#include <string>
#include <string.h>
//#include <strings.h>
//#include <sys/socket.h>
#include "FileCacheManager.h"
#include "StringReverser.h"

#define BUFFER_SIZE 1024

using namespace std;

void MyTestClientHandler::handleClient(int inputPort, int outputPort)
{
    ///////////// implement
    char buffer[BUFFER_SIZE];
    int n;
    server_side::FileCacheManager cache("filename");
    server_side::StringReverser solver;
    while (true) {
        n = read(inputPort, buffer, BUFFER_SIZE);
        if (n < 0)
            break;
        buffer[n] = '\0';
        if (strcmp(buffer, "end") == 0) // finish
            break;
        string problem = buffer;
        string* solution = nullptr;
        if (cache.isSolutionCashed(&problem))
        {
            solution = cache.getSolution(&problem);
        }
        else {
            solution = solver.solve(&problem);
            cache.cache(&problem, solution);
        }

        if (solution != nullptr)
        {
            n = write(outputPort, solution->c_str(), solution->size());
            delete solution;
            if (n < 0)
                break;
        }
    }
}
