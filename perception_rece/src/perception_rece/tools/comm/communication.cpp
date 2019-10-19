#include "communication.h"

int PerceptionCommunication::init(int port)
{
    
    rece_sk= socket(AF_INET, SOCK_DGRAM, 0);

	if (rece_sk == -1) {
		cout << "Communication: Create Upd Reciver Socket Failed !" << endl ;
		return -1;
	}
    memset((char *) &sk_addr, 0, sizeof(sk_addr));
	sk_addr.sin_family = AF_INET;
	sk_addr.sin_port = htons(port);
	sk_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 绑定网卡所有ip地址，INADDR_ANY为通配地址，值为0
    int err_log = ::bind(rece_sk, (struct sockaddr *) &sk_addr, sizeof(sk_addr)); // 绑定
	if (err_log != 0) {
		cout << "Communication: Bind Network Failed!" << endl; 
		close(rece_sk);
		return -2;
	}
	int bufferSize = 2 * 1024 * 1024;
	setsockopt(rece_sk, SOL_SOCKET, SO_RCVBUF, (const char*)(&bufferSize), sizeof(int));
    return 0;
}

int PerceptionCommunication::receive(void *data)
{
   int ret;
   int bSize = 1024*1024;
   char *rbuff = new char[bSize];
   unsigned int sk_addr_len = sizeof(sk_addr);
   ret = recvfrom(rece_sk, rbuff,bSize, 0,
	               (struct sockaddr *) &sk_addr,&sk_addr_len);
   if(ret==-1)
   {
	   cout << "Communication: Receive Message Data Failed, Error!"  << endl;
	   return -1;
	   
   }
   else
   {

	   memcpy(data,rbuff,ret);
   }
   delete [] rbuff;
   return ret;
}
