
/**
 * 该例程将发布/time_info话题，自定义消息类型talker_1::Time
 */
 
#include <ros/ros.h>
#include "talker_1/Time.h"
#include <ctime>
#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "time_publisher");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Publisher，发布名为/time_info的topic，消息类型为talker_1::Time，队列长度10
    ros::Publisher time_info_pub = n.advertise<talker_1::Time>("/time_info", 10);

    // 设置循环的频率
    ros::Rate loop_rate(1);

    time_t time_seconds=time(0);
    struct tm now_time;
   char chtime[128];
    
    talker_1::Time time_msg;
    time_msg.count = -1;
    while (ros::ok())
    {
        // 初始化Ros_learn::Time类型的消息
    	
    	
    	time(&time_seconds);
    	localtime_r(&time_seconds, &now_time);
    	
	
	time_msg.year = now_time.tm_year + 1900;
        time_msg.month = now_time.tm_mon + 1;
        time_msg.day = now_time.tm_mday;
        time_msg.hour = now_time.tm_hour;
        time_msg.minute = now_time.tm_min;
        time_msg.second = now_time.tm_sec;
        time_msg.count++;

        //将时间合成字符串
       sprintf(chtime,"%d-%d-%d %d:%d:%d.%02d ",
       time_msg.year,
       time_msg.month,
       time_msg.day,
       time_msg.hour,
       time_msg.minute,
       time_msg.second,
       (int)(time_seconds/1000)
       );
        
       
        // 发布消息
		time_info_pub.publish(time_msg);

       	ROS_INFO("[%d]:Current time is: %s",time_msg.count,chtime);

        // 按照循环频率延时
        loop_rate.sleep();
        
    }

    return 0;
}
