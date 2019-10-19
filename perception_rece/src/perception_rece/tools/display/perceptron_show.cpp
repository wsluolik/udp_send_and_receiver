#include "perceptron_show.h"
//根据接收到的数据创建ｍａｒｋｅｒ，并添加到ｒｏｓ消息中，用于ｒｖｉｚ显示
void DrawRviz::show_percept(const ros::Publisher &pub, const std_msgs::Header &_header,
                                    const PerceptronList &List) {
	visualization_msgs::MarkerArrayPtr marker_array(new visualization_msgs::MarkerArray);
	visualization_msgs::Marker marker_box;
	// visualization_msgs::Marker marker_cube;
	// visualization_msgs::Marker marker_text_box;
	// visualization_msgs::Marker marker_text_label;
	// visualization_msgs::Marker marker_text_track;
	// visualization_msgs::Marker marker_track_arrow;

	Eigen::Vector3f colors[5];
	colors[0] = Eigen::Vector3f(0.6, 0.5, 0.6);//淡紫色 background
	colors[1] = Eigen::Vector3f(1, 1, 0);//黄色 pedestrian
	colors[2] = Eigen::Vector3f(0, 1, 1);//青色 bike
	colors[3] = Eigen::Vector3f(0.5, 0, 0);//红色 car
	colors[4] = Eigen::Vector3f(0, 0, 1);//蓝色 truck

	std::string info[5] = {"unknow", "ped", "bike", "car", "truck"};

	// marker_text_box.header = _header;
	// marker_text_box.ns = "box_info";
	// marker_text_box.scale.x = TEXT_SCALE;
	// marker_text_box.scale.y = TEXT_SCALE;
	// marker_text_box.scale.z = TEXT_SCALE;
	// marker_text_box.color.r = 0.f;
	// marker_text_box.color.g = 0.6f;
	// marker_text_box.color.b = 0.7f;
	// marker_text_box.color.a = 1.f;

	// marker_text_track.header = _header;
	// marker_text_track.ns = "track_info";
	// marker_text_track.scale.x = TEXT_SCALE;
	// marker_text_track.scale.y = TEXT_SCALE;
	// marker_text_track.scale.z = TEXT_SCALE;
	// marker_text_track.color.r = 0.f;
	// marker_text_track.color.g = 0.7f;
	// marker_text_track.color.b = 0.6f;
	// marker_text_track.color.a = 1.f;

	// marker_text_label.header = _header;
	// marker_text_label.ns = "label_info";
	// marker_text_label.scale.x = TEXT_SCALE;
	// marker_text_label.scale.y = TEXT_SCALE;
	// marker_text_label.scale.z = TEXT_SCALE;
	// marker_text_label.color.a = 1.0;

	// marker_track_arrow.header = _header;
	// marker_track_arrow.ns = "velocity_dir";
	// marker_track_arrow.color.r = 0.f;
	// marker_track_arrow.color.g = 0.7f;
	// marker_track_arrow.color.b = 0.3f;
	// marker_track_arrow.color.a = 0.8f;

	marker_box.header = _header;
	marker_box.ns = "box";
	marker_box.color.r = colors[0](0);
	marker_box.color.g = colors[0](1);
	marker_box.color.b = colors[0](2);
	marker_box.scale.x = marker_box.scale.y = marker_box.scale.z = 0.03;

	// marker_cube.header = _header;
	// marker_cube.ns = "cube";

	//	std::string link_mode[4] ={"Bary", "Center", "S-center", "Corner"};

	int marker_id = 0;

	for (int i = 0; i < List.perceptron_size(); ++i) {


		//-------------------------------box----------------------------
		draw_box(List.perceptron(i), marker_id, marker_box);

		// Eigen::Vector3f nearest = perceptron->nearest_point;
		// std::string text_box =
		// 	num2str<float>(nearest.norm(), 1) + " (" + num2str<float>(perceptron->center(0), 1) + " " +
		// 	num2str<float>(perceptron->center(1), 1) + " " + num2str<float>(perceptron->center(2), 1) + ")";

		// Eigen::Vector3f pos0 = perceptron->center;
		// pos0(2) += perceptron->height * 0.5f + 0.2f;
		// draw_text(pos0, text_box, marker_id, marker_text_box, 1.0);

		marker_array->markers.push_back(marker_box);
		//marker_array->markers.push_back(marker_text_box);
		
		//--------------------------------tracking------------------------------
// 		float velocity = perceptron->velocity.norm();
// 		bool is_valid_vel = velocity > 0.3f;
// 		draw_track_arrow(perceptron, marker_id, marker_track_arrow, is_valid_vel ? 0.8 : 0);

// 		Eigen::Vector3f pos1 = perceptron->center;
// 		pos1(2) += perceptron->height * 0.5f + 0.7f;

// 		float angle_vel = perceptron->angle_velocity / PI_OVER_180;

// 		std::string text_track =
// 			"<" + num2str<int>(perceptron->tracker_id, 0) + ">" + num2str<float>(velocity * 3.6f, 1) + "km/h"
// //			+ "--> " + num2str<float>(perceptron->yaw/PI_OVER_180, 1);
// 			+" >>" + num2str<float>(perceptron->association_score, 3);

// //			+" >> " + num2str<float>(perceptron->angle_velocity/PI_OVER_180, 2); //association_score

// 		//num2str<float>(angle_vel, 1);
// 		//+ " / " + num2str<float>(perceptron->sequence_robustness, 3);
// 		draw_text(pos1, text_track, marker_id, marker_text_track, is_valid_vel ? 0.8 : 0);

// 		marker_array->markers.push_back(marker_track_arrow);
// 		marker_array->markers.push_back(marker_text_track);


// 		//--------------------------------classification---------------------------
// 		int type = perceptron->type;
// 		Eigen::Vector3f color = colors[type];
// 		bool is_bgd = (type == 0);
// 		//cube
// 		marker_cube.color.r = color(0);
// 		marker_cube.color.g = color(1);
// 		marker_cube.color.b = color(2);

// 		draw_cube(perceptron, marker_id, marker_cube, is_bgd ? 0.3 : 0.6, 1.0);

// 		marker_text_label.color.r = color(0);
// 		marker_text_label.color.g = color(1);
// 		marker_text_label.color.b = color(2);

// 		Eigen::Vector3f pos2 = perceptron->center;
// 		pos2(2) += perceptron->height * 0.5f + 1.2f;

// 		std::string text_label = info[type] + " >>" + num2str<float>(perceptron->type_confidence, 2);

// 		draw_text(pos2, text_label, marker_id, marker_text_label, is_bgd ? 0 : 0.95);
		
// 		marker_array->markers.push_back(marker_cube);
// 		marker_array->markers.push_back(marker_text_label);

		marker_id++;
	}

	if (marker_id < marker_per_num) {
		for (int i = marker_id; i < marker_per_num; ++i) {
			marker_box.id = i;
			marker_box.color.a = 0.f;
			marker_array->markers.push_back(marker_box);

			// marker_cube.id = i;
			// marker_cube.color.a = 0.f;
			// marker_array->markers.push_back(marker_cube);

			// marker_text_box.id = i;
			// marker_text_box.color.a = 0.f;
			// marker_array->markers.push_back(marker_text_box);

			// marker_text_track.id = i;
			// marker_text_track.color.a = 0.f;
			// marker_array->markers.push_back(marker_text_track);

			// marker_track_arrow.id = i;
			// marker_track_arrow.color.a = 0.f;
			// marker_array->markers.push_back(marker_track_arrow);

			// marker_text_label.id = i;
			// marker_text_label.color.a = 0.f;
			// marker_array->markers.push_back(marker_text_label);
		}
	}

	marker_per_num = marker_id;
	pub.publish(marker_array);

}

void DrawRviz::draw_box(const Perceptron percept,const int &marker_id,visualization_msgs::Marker &marker)
{
	marker.id = marker_id;
	marker.type = visualization_msgs::Marker::LINE_LIST;
	marker.action = visualization_msgs::Marker::ADD;


	tf::Quaternion quat = tf::createQuaternionFromRPY(0, 0, 0);
	tf::quaternionTFToMsg(quat, marker.pose.orientation);
	marker.color.a = 0.5;

	std::vector<geometry_msgs::Point> cub_points;
        std::vector<Eigen::Vector3f> corners;

        Eigen::Vector3f dir = Eigen::Vector3f::Zero();
	dir(0) = percept.direction().x();
	dir(1) = percept.direction().y();
	dir(2) = 0.f;
	dir.normalize();

	Eigen::Vector3f ortho_dir = Eigen::Vector3f(-dir(1), dir(0), 0);

	Eigen::Vector3f z_dir = Eigen::Vector3f(0,0,1);

	Eigen::Vector3f center = Eigen::Vector3f::Zero();
	center(0) = percept.location().x();
	center(1) = percept.location().y();
	center(2) = percept.location().z();

	Eigen::Vector3f size = Eigen::Vector3f::Zero();
	size(0)= percept.length();
	size(1)= percept.width();
	size(2)= percept.height();


    corners.resize(8, Eigen::Vector3f::Zero());
	corners[0] = center + dir * size(0) * 0.5f + ortho_dir * size(1) * 0.5f - z_dir * size(2) * 0.5f;
	corners[1] = center - dir * size(0) * 0.5f + ortho_dir * size(1) * 0.5f - z_dir * size(2) * 0.5f;
	corners[2] = center - dir * size(0) * 0.5f - ortho_dir * size(1) * 0.5f - z_dir * size(2) * 0.5f;
	corners[3] = center + dir * size(0) * 0.5f - ortho_dir * size(1) * 0.5f - z_dir * size(2) * 0.5f;
	corners[4] = center + dir * size(0) * 0.5f + ortho_dir * size(1) * 0.5f + z_dir * size(2) * 0.5f;
	corners[5] = center - dir * size(0) * 0.5f + ortho_dir * size(1) * 0.5f + z_dir * size(2) * 0.5f;
	corners[6] = center - dir * size(0) * 0.5f - ortho_dir * size(1) * 0.5f + z_dir * size(2) * 0.5f;
	corners[7] = center + dir * size(0) * 0.5f - ortho_dir * size(1) * 0.5f + z_dir * size(2) * 0.5f;

    for (int i = 0; i < 8; ++i)
	 {
		geometry_msgs::Point pts;
		pts.x = corners[i](0);
		pts.y = corners[i](1);
		pts.z = corners[i](2);
		cub_points.push_back(pts);
	}
		marker.points.push_back(cub_points[0]);
		marker.points.push_back(cub_points[1]);
		marker.points.push_back(cub_points[1]);
		marker.points.push_back(cub_points[2]);
		marker.points.push_back(cub_points[2]);
		marker.points.push_back(cub_points[3]);
		marker.points.push_back(cub_points[3]);
		marker.points.push_back(cub_points[0]);
		// horizontal high points for lines
		marker.points.push_back(cub_points[4]);
		marker.points.push_back(cub_points[5]);
		marker.points.push_back(cub_points[5]);
		marker.points.push_back(cub_points[6]);
		marker.points.push_back(cub_points[6]);
		marker.points.push_back(cub_points[7]);
		marker.points.push_back(cub_points[7]);
		marker.points.push_back(cub_points[4]);
		// vertical points for lines
		marker.points.push_back(cub_points[0]);
		marker.points.push_back(cub_points[4]);
		marker.points.push_back(cub_points[1]);
		marker.points.push_back(cub_points[5]);
		marker.points.push_back(cub_points[2]);
		marker.points.push_back(cub_points[6]);
		marker.points.push_back(cub_points[3]);
		marker.points.push_back(cub_points[7]);
}
