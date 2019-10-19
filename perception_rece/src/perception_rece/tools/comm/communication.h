#ifndef COMMUNICATION_H
#define COMMUNICATION_H
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <memory.h>
#include <iostream>
using namespace std;
class PerceptionCommunication
{
    public:
    int init(int port);
    int receive(void *list);

    private:
    int rece_sk;
    struct sockaddr_in sk_addr;
};

#endif //COMMUNICATION_H
