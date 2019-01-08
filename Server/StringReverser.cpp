#include "StringReverser.h"
#include <algorithm>

string* server_side::StringReverser::solve(string* str)
{
    string* reverse = new string(*str);
    std::reverse(reverse->begin(), reverse->end());
    return reverse;
}
