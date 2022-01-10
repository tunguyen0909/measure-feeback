#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Int8.h>
#include <sstream>

ros::Time begin;
ros::Time end;
ros::Duration result;


void callBack(const std_msgs::Int8& msg);
 
int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::Int8>("chatter", 1000);
  
  ros::Subscriber sub = n.subscribe("feed_back", 1000, callBack);
  
 
  while(ros::ok())
  {
	  /*std_msgs::String msg;
	  std::stringstream ss;
	  ss << "hello world";
	  msg.data = ss.str();
	  ROS_INFO("%s", msg.data.c_str());
	  begin = ros::Time::now();
	  ros::Duration(0.1).sleep();		   
	  chatter_pub.publish(msg);
	  ros::spinOnce();*/
	  
	  std_msgs::Int8 msg;
	  msg.data = 17;
	  ROS_INFO("%d", msg.data);
	  begin = ros::Time::now();
	  ros::Duration(0.1).sleep();		   
	  chatter_pub.publish(msg);
	  ros::spinOnce();
  }
  return 0;
}

void callBack(const std_msgs::Int8& msg)
{
	if(msg.data == 2)
	{
		end = ros::Time::now();
		ROS_INFO("Oh no: [%d]",msg.data);
		result = end - begin;
		ROS_INFO("result: [%lf]",result.toSec());
	}
}



