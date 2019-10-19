#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include "perceptron.pb.h"
#include <pcl_conversions/pcl_conversions.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <cv_bridge/cv_bridge.h>
#include <pcl/common/common.h>
#include <pcl/common/transforms.h>
#include <tf/tf.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
using namespace robosense::perception;
class DrawRviz
{
   public:
    void show_percept(const ros::Publisher &pub,const std_msgs::Header &_header,const PerceptronList &list);

    private:
 	int marker_per_num=0;
        void draw_box(const Perceptron percept,const int &marker_id,visualization_msgs::Marker &marker);

};
#endif //PERCEPTRON_H
