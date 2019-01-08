#include "Main.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"

void boot::Main::main(int port)
{
    server_side::MySerialServer server;
    MyTestClientHandler ch;
    server.open(port, &ch);
    server.stop();
}
