#include <map_manager/map_manager.h>


MapManager::MapManager():
  pnh_("~")
{
    pnh_.param<std::string>("set_map_name",set_map_srv_name_,"set_map");

    set_map_srv_ = pnh_.advertiseService(set_map_srv_name_, &MapManager::setMapCallback, this);
}

bool MapManager::setMapCallback(map_manager::SetMap::Request& request,
                                map_manager::SetMap::Response& response){
    ROS_ERROR(request.name.c_str());
    response.ret = true;
    return true;

}


int main(int argc, char** argv)
{
	ros::init(argc, argv, "map_manager");
	MapManager map_manager;

	ros::Rate r(50.0);

	while( ros::ok() ){
		ros::spinOnce();
		r.sleep();
    }
}
