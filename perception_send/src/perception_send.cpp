#include "ros/ros.h"
#include "callback.h"
int main(int argc, char **argv)
{
  ros::init(argc,argv,"perception_send");
  ros::NodeHandle n;
  //创建一个处理类，处理感知数据 和 发送感知数据，其中PerceptionCallback函数是传递给接收器的回调函数
  Callback cb;
  //创建一个接收器，获取感知结果
  ros::Subscriber revPerceptionList = n.subscribe("/rs_percept_result",100,&Callback::PerceptionCallback,&cb);
  ros::spin();
  

  return 0;
}
