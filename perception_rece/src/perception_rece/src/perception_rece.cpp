#include "ros/ros.h"
#include "communication.h"
#include <perceptron.pb.h>
#include "perceptron_show.h"

using namespace robosense::perception;
int main(int argc, char **argv)
{
  ros::init(argc,argv,"perception_rece");
  ros::NodeHandle n;
  PerceptionCommunication comm;
  comm.init(60001);

  ros::Publisher pub_percept = n.advertise<visualization_msgs::MarkerArray>("perception_show", 10);
  std_msgs::Header _header;
  _header.frame_id = "rslidar";
  DrawRviz dr;
  while(ros::ok)
  {
    PerceptronList List;
    void *rdata = malloc(1024*1024);
    int ret = comm.receive(rdata);
    if(ret > 0)
    {
	   if(!List.ParseFromArray(rdata,ret))
           {
 		ROS_INFO("PArseFromArray error!");
		return -1;
           }
       ROS_INFO("%d",List.frmnumber());
    }
    free(rdata);
    dr.show_percept(pub_percept,_header,List);
  }
  return 0;
}
