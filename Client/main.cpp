#include <arpa/inet.h>
#include <netdb.h> /* getprotobyname */
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

#define BUFFER_SIZE 1024

int main()
{

    const char *server_hostname = "127.0.0.1";
    in_addr_t in_addr;
    struct hostent *hostent;
    /* This is the struct used by INet addresses. */
    struct sockaddr_in sockaddr_in;
    unsigned short server_port = 5001;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    /* Prepare sockaddr_in. */
    hostent = gethostbyname(server_hostname);
    if (hostent == NULL) {
        fprintf(stderr, "error: gethostbyname(\"%s\")\n", server_hostname);
        exit(EXIT_FAILURE);
    }
    in_addr = inet_addr(inet_ntoa(*(struct in_addr*)*(hostent->h_addr_list)));
    if (in_addr == (in_addr_t)-1) {
        fprintf(stderr, "error: inet_addr(\"%s\")\n", *(hostent->h_addr_list));
        exit(EXIT_FAILURE);
    }
    sockaddr_in.sin_addr.s_addr = in_addr;
    sockaddr_in.sin_family = AF_INET;
    sockaddr_in.sin_port = htons(server_port);

    char input[BUFFER_SIZE], output[BUFFER_SIZE];
    int n;


    /* Do the actual connection. */
    while (connect(sockfd, (struct sockaddr*)&sockaddr_in, sizeof(sockaddr_in)) == -1) {
        sleep(2);
    }

    ifstream fs("file.txt");
    if (! fs.good())
    {
        cout << "bad" << endl;
    }
    else
    {
        cout << "good" << endl;
    }
std::string line;
while (std::getline(fs, line))
{
    if (write(sockfd, line.c_str(), line.size()) == -1) {
                //perror("write");
                //break;
            }
    if (write(sockfd, " $ ", 3) == -1) {
                //perror("write");
                //break;
            }
//fsync(sockfd); // flush the output
//usleep(100);
//flush(&sockfd);
cout << "line: " << line << endl;
}
    if (write(sockfd, "end", 3) == -1) {
                //perror("write");
                //break;
            }
cout << "line: end" << endl;
fsync(sockfd); // flush the output
    if ((n = read(sockfd, input, BUFFER_SIZE)) == -1) {
                //perror("write");
                //break;
            }
input[n] = '\0';
std::cout<<"input: " << input<<std::endl;
close(sockfd);
exit(0);
    while (1) {
            if (write(sockfd, "", 0) == -1) {
                //perror("write");
                break;
            }
        }
    return 0;
}
