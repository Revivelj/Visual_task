/***********************************************************************
Create by Revive 
***********************************************************************/

/**
 * 该例程将订阅/time_info话题，自定义消息类型talker_1::Time
 */
 
#include <ros/ros.h>
#include "talker_1/Time.h"

// 接收到订阅的消息后，会进入消息回调函数
void timeInfoCallback(const talker_1::Time::ConstPtr& msg)
{
   
    // 将接收到的消息打印出来
    ROS_INFO("[%d]:Current time is:  %d-%d-%d %d:%d:%d.", 
    msg->count,
    msg->year, 
    msg->month, 
    msg->day, 
    msg->hour,
    msg->minute, 
    msg->second
    ); 
}

int main(int argc, char **argv)
{
    
    // 初始化ROS节点
    ros::init(argc, argv, "time_subscriber");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Subscriber，订阅名为/time_info的topic，注册回调函数timeInfoCallback
    ros::Subscriber time_info_pub = n.subscribe("/time_info", 10, timeInfoCallback);
    
    // 循环等待回调函数
    ros::spin();

    return 0;
}
