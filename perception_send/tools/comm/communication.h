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
    int init(std::string ip,int port);//初始化socket
    int send(void* data,int size);//发送数据

    private:
    int send_sk; //socket句柄
    struct sockaddr_in sk_addr;
};

#endif //COMMUNICATION_H
