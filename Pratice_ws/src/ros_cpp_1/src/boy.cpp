#include <ros/ros.h>
#include "ros_cpp_1/person.h"

int main(int argc,char** argv){


    ros::init(argc, argv, "boy_speaker");
    //1,argc is the number of the paramer.参数个数
    //2,argv is the content of the paramer 参数值 这里的参数和ros的参数服务器不一样，这里的参数是c++语言，对一个可执行文件的参数
    //3.ros node name 节点名,疑问：能不能在一个可执行程序里面定义多个节点，上次中车的项目要用到熬了一晚上也用c++没写出来，
    //就在准备放弃睡觉的时候，复制粘贴改了改几行py代码，很神奇的跑起来了。。。。
    ros::NodeHandle nh;
    //nodehandle is the main deal with ros publisher发布话题，subscriber接受话题都需要nodehandle对相应的类进行初始化，c++里面成为构造函数。
    //同样的还有创建话题的server，提供服务，创建服务的client 调用服务。 查询参数的值，给特定的参数赋值

    ros_cpp_1::person person_msg;//消息的定义方式

    person_msg.age=1;

    person_msg.state="working";


    ros::Publisher pub =nh.advertise<ros_cpp_1::person>("talk_session",1);// 话题发布者对象的初始化，<>里面写消息的类型，（）里面是话题名和消息队列的最大长度
    //队列是先进先出的数据结构，如果之前发布的数据已经将队列填满，这时候新来一条消息插到队列尾部，那么对头的旧的消息就会出对。通常设置队列的长度为一个较小的值

    ros::Rate looprate=(1.0);//消息的发布频率

    while (ros::ok())//rosmaster 没有关闭时ros::ok()为true,反之为false
    {

        person_msg.now_time = ros::Time::now(); //ros::Time::now();
        //这里可以对消息进行相关的处理
        pub.publish(person_msg);//以定义的频率发布消息

        looprate.sleep();//根据之前设定的频率，进行相应的延时
    }
    

        return 0;
    
}