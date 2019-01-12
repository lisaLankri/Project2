#ifndef SERVER_UTILS_H
#define SERVER_UTILS_H

#include <vector>
#include <string>
using namespace std;

#define BUFFER_SIZE 1024

class Utils {
public:
    static void tokenize(const string& str, vector<string>& tokens, const string& delimiters = ",");
};


#endif //SERVER_UTILS_H
