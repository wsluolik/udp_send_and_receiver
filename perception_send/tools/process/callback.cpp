#include "callback.h"

//把ros消息类型 转为proto类型
void Callback::setPerceptron(Perceptron *pt,const perception_send::PerceptionMsg &pm)
{
    //box info 
    pt->set_timestamp(pm.timestamp);

    Point3 *P3_location = pt->mutable_location();
    P3_location->set_x(pm.location.x);
    P3_location->set_y(pm.location.y);
    P3_location->set_z(pm.location.z);

    Point3 *P3_direction = pt->mutable_direction();
    P3_direction->set_x(pm.direction.x);
    P3_direction->set_y(pm.direction.y);
    P3_direction->set_z(pm.direction.z);

    pt->set_yaw(pm.yaw);
    pt->set_length(pm.length);
    pt->set_height(pm.height);

    Point3 *P3_nearest_point = pt->mutable_nearest_point();
    P3_nearest_point->set_x(pm.nearest_point.x);
    P3_nearest_point->set_y(pm.nearest_point.y);
    P3_nearest_point->set_z(pm.nearest_point.z);

    for(int i=0;i<pm.box_corners.size();i++)
    {
      Point3 *P3_box_corners = pt ->add_box_corners();
      P3_box_corners->set_x(pm.box_corners[i].x);
      P3_box_corners->set_y(pm.box_corners[i].y);
      P3_box_corners->set_z(pm.box_corners[i].z);
    }

    //tracking info
    pt->set_is_tracking_success(pm.is_tracking_success);
    pt->set_id(pm.id);
    pt->set_association_score(pm.association_score);
    pt->set_tracker_robustness(pm.tracker_robustness);

    Point3 *P3_velocity = pt->mutable_velocity();
    P3_velocity->set_x(pm.velocity.x);
    P3_velocity->set_y(pm.velocity.y);
    P3_velocity->set_z(pm.velocity.z);

    Point3 *P3_acceleration = pt->mutable_acceleration();
    P3_acceleration->set_x(pm.acceleration.x);
    P3_acceleration->set_y(pm.acceleration.y);
    P3_acceleration->set_z(pm.acceleration.z);

    pt->set_angular_velocity(pm.angular_velocity);
    pt->set_tracking_time(pm.tracking_time);
    pt->set_visible_tracking_time(pm.visible_tracking_time);

    for(int i=0;i<pm.history_velocity.size();i++)
    {
      Point3 *P3_history_velocity = pt ->add_history_velocity();
      P3_history_velocity->set_x(pm.history_velocity[i].x);
      P3_history_velocity->set_y(pm.history_velocity[i].y);
      P3_history_velocity->set_z(pm.history_velocity[i].z);
    }

    for(int i=0;i<pm.history_velocity.size();i++)
    {
      Point3 *P3_trajectory = pt ->add_trajectory();
      P3_trajectory->set_x(pm.trajectory[i].x);
      P3_trajectory->set_y(pm.trajectory[i].y);
      P3_trajectory->set_z(pm.trajectory[i].z);
    }

    //classification info
    pt->set_type(pm.type);
    pt->set_type_confidence(pm.type_confidence);
    pt->set_is_background(pm.is_background);

    for(int i=0;i<pm.polygon_point.size();i++)
    {
      Point3 *P3_polygon_point = pt ->add_polygon_point();
      P3_polygon_point->set_x(pm.polygon_point[i].x);
      P3_polygon_point->set_y(pm.polygon_point[i].y);
      P3_polygon_point->set_z(pm.polygon_point[i].z);
    }
}

//处理感知结果的回调函数
void Callback::PerceptionCallback(const perception_send::PerceptionListMsg &p)
{
  vector<perception_send::PerceptionMsg> plist = p.perceptions;
  PerceptronList List;
  List.set_frmnumber(frmNumber);
  
  for(int i=0;i<plist.size();i++)
  {
    Perceptron *pt;
    pt = List.add_perceptron();

    setPerceptron(pt,plist[i]);//把ros消息类型 转为proto类型
  }
  int list_length = List.ByteSize();
   void *pbuff = malloc(list_length);
   List.SerializeToArray(pbuff,list_length);
   int ret;
  ret = comm.send(pbuff,list_length);//发送数据
  if(ret<0)
  {
    ROS_ERROR("data send error!");
  }
  else
  {
    ROS_INFO("%d-----%d----%d-----%d",List.perceptron_size(),list_length,frmNumber,ret);
  }
  
  frmNumber++;
  free(pbuff);
}
//初始化，默认ip：192.168.1.255 端口：60000
Callback::Callback()
{
  frmNumber = 0;
  if(comm.init("192.168.1.255",60001)!=0)
  {
    ROS_INFO("socket init failure!");
    return;
  }
  else
  {
    ROS_INFO("socket init success!");
  }
  

}


