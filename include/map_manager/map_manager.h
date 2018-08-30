#include <ros/ros.h>

#include <map_manager/SetMap.h>

class MapManager
{
	public:
	MapManager();
	ros::NodeHandle nh_;

	private:
	ros::NodeHandle pnh_;

    std::string set_map_srv_name_;  

    ros::ServiceServer set_map_srv_;

    bool setMapCallback(map_manager::SetMap::Request& request,
                        map_manager::SetMap::Response& response);
    
};
