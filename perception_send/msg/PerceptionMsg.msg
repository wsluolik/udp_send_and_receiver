# single perception, defined by ros message type

#timestamp
float64 timestamp # global timestamp in seconds.

# box info
geometry_msgs/Point location # obstacle position in global coordinate in meters.

geometry_msgs/Vector3 direction #obstacle normalized direction in global coordinate; when without tracking, it parallel to the length edge direction.

float32 yaw # yaw angle in global coordinate with radian unit, another way to depict "direction" if only consider in x-y plane, in global coordinate.

float32 length #length of obstacle

float32 width #width of obstacle

float32 height #height of obstacle

geometry_msgs/Point nearest_point # nearest point of the bounding box corner of the obstacle to lidar self in global coordinate in meters.

geometry_msgs/Point[] box_corners # corner points of the bounding box of the obstacle in global coordinate in meters.



# tracking info
bool is_tracking_success  #obstacle tracking state: tracked succeed or not.

int32 id  # obstacle tracker ID.

float32 association_score # the confidence for the obstacle when associated to a tracker, 0~1, the greater, the better.

float32 tracker_robustness # the robustness for a tracker that the obstacle belong to, 0~1, the greater, the better.

geometry_msgs/Point velocity # obstacle velocity in world coordinate.

geometry_msgs/Point acceleration # obstacle acceleration in world coordinate.

float32 angular_velocity # angular velocity with rad in world coordinate.

float64 tracking_time # the total life (including occlusion) for the obstacle been tracked since been first detected in seconds.

float64 visible_tracking_time # the life only visible for the obstacle been tracked since been first detected in seconds.

geometry_msgs/Vector3[] history_velocity # historical velocity for the obstacle when tracked in global coordinate, default is 15 frames.

geometry_msgs/Point[] trajectory # historical trajectory for the obstacle when tracked in global coordinate in meters, default is 15 frames.



# classification info
int32 type  # obstacle type, 0 mmeans unknown, 1 means pedestrain, 2 means bicycle, 3 means car, 4 means truck/bus.

float32 type_confidence  # the confidence for the classification, 0~1, the greater, the better.
bool is_background # is background or not. (optional, may not be used)

geometry_msgs/Point[] polygon_point #corner points of the convex hull of the obstacle in global coordinate in meters.

# geometry_msgs/Point[] cloud #original pointcloud of the obstacle in global coordinate in meters.
