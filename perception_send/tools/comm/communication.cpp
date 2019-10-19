#include "communication.h"

int PerceptionCommunication::init(std::string ip,int port)
{
    
    int sk_addr_len = sizeof(struct sockaddr_in);
    send_sk= socket(AF_INET, SOCK_DGRAM, 0);

	if (send_sk == -1) {
		cout << "Communication: Create Upd Sender Socket Failed !" << endl ;
		return -1;
	}
        memset((char *) &sk_addr, 0, sizeof(sk_addr));
	sk_addr.sin_family = AF_INET;
	sk_addr.sin_port = htons(port);
	inet_pton(AF_INET, ip.c_str(), &sk_addr.sin_addr);
    int opt = 1;
	setsockopt(send_sk, SOL_SOCKET, SO_BROADCAST, &opt, sizeof(opt));
    return 0;
}

int PerceptionCommunication::send(void *data,int len)
{
	int ret;
    ret = sendto(send_sk,data,len, 0,
                 (struct sockaddr *) &sk_addr,
	             sizeof(sk_addr));
	return ret;
}
