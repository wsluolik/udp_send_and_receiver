#ifndef CALLBACK_H
#define CALLBACK_H
#include "perception_send/PerceptionMsg.h"
#include "perception_send/PerceptionListMsg.h"
#include "communication.h"
#include "perceptron.pb.h"
#include "ros/ros.h"
#include "sys/time.h"
#include <unistd.h>
using namespace robosense::perception;
//定义一个类，序列化感知发出来的数据，然后通过udp发送出去
class Callback
{
  public:
        Callback();//初始化，默认ip：192.168.1.255 端口：60000
        void PerceptionCallback(const perception_send::PerceptionListMsg &p);

  private:
  int frmNumber;
  PerceptionCommunication comm; //创建数据链接类
  void setPerceptron(Perceptron *pt,const perception_send::PerceptionMsg &ptm);//把ros的消息类型转成protoc类型；
};
#endif //CALLBACK_H
