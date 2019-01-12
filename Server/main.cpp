#include "Main.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "MySolver.h"
#include "MatrixFileCacheManager.h"
#include "MyParellelServer.h"

void boot::Main::main(int port)
{
    server_side::MyParellelServer<string,vector<string>> server;
    //server_side::MySerialServer<string,vector<string>> server;
    //server_side::FileCacheManager cache("filename");
    //server_side::StringReverser solver;
    server_side::MatrixFileCacheManager cache("filename");
    server_side::MySolver solver;
    MyTestClientHandler ch(&solver, &cache);
    server.open(port, &ch);
    server.stop();
}
