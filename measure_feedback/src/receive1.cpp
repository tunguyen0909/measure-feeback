#include "ros/ros.h"
#include <std_msgs/Int8.h>
#include "std_msgs/String.h"

ros::Publisher chatter_pub;
ros::Subscriber sub;

//std_msgs::String msg_fb;
//std::stringstream ss;
//void chatterCallback(const std_msgs::String::ConstPtr& msg);

std_msgs::Int8 msg_fb;

void chatterCallback(const std_msgs::Int8& msg);

int main(int argc, char **argv)
{
  /*ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  chatter_pub = n.advertise<std_msgs::String>("feed_back", 1000);
  sub = n.subscribe("chatter", 1000, chatterCallback);
  ss << "I heard";	
  msg_fb.data = ss.str();
  ros::spin();*/
  
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  chatter_pub = n.advertise<std_msgs::Int8>("feed_back", 1000);
  sub = n.subscribe("chatter", 1000, chatterCallback);
  msg_fb.data = 2;
  ros::spin();

  return 0;
}

void chatterCallback(const std_msgs::Int8& msg)
{
	if(msg.data == 17)
	{
		ROS_INFO("I heard: [%d]", msg.data);
		chatter_pub.publish(msg_fb);
	}
}

/*void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  	ROS_INFO("I heard: [%s]", msg->data.c_str());
  	chatter_pub.publish(msg_fb);
  	ros::spinOnce();
}*/
