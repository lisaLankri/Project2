#include "Main.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"

void boot::Main::main(int port)
{
    server_side::MySerialServer<string,string> server;
    server_side::FileCacheManager cache("filename");
    server_side::StringReverser solver;
    MyTestClientHandler ch(&solver, &cache);
    server.open(port, &ch);
    server.stop();
}
