//ROS头文件
#include <ros/ros.h>
//自定义msg产生的头文件
#include <helloworld_ws/hello.h>

int main(int argc, char **argv)
{
  //用于解析ROS参数，第三个参数为本节点名
  ros::init(argc, argv, "talker");

  //实例化句柄，初始化node
  ros::NodeHandle nh;

  //自定义hello msg
  helloworld_ws::hello msg;
  msg.num = 0;
  //const std::string::
  msg.message = "Hello World!";

  //创建publisher
  ros::Publisher pub = nh.advertise<helloworld_ws::hello>("hello_info", 1);

  //定义发布的频率 
  ros::Rate loop_rate(1);

  //循环发布msg
  while (ros::ok())
  {
    msg.num +=1;
    ROS_INFO("Talker Send message: %d, %s", msg.num, msg.message.c_str());//msg->message.c_str()
    //每秒发布一条msg
    pub.publish(msg);
    loop_rate.sleep();//根据前面的定义的loop_rate,设置1s的暂停
  }

  return 0;
}
