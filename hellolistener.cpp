//ROS头文件
#include <ros/ros.h>
//包含自定义msg产生的头文件
#include <helloworld_ws/hello.h>
//ROS标准msg头文件
#include <std_msgs/Float32.h>

void helloCallback(const helloworld_ws::hello::ConstPtr &msg)
{
    ROS_INFO("Listener Received msg: %d, %s", msg->num, msg->message.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("hello_info", 1, helloCallback);
  //ros::spin()用于调用所有可触发的回调函数。将进入循环，不会返回，类似于在循环>里反复调用ros::spinOnce()。
  ros::spin();
  return 0;
}

