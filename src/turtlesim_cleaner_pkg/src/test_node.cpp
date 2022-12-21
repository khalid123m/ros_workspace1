//Alhamdulillah successful moveit
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include<iostream>
using namespace std;
int main(int argc, char **argv)
{
 double FORWARD_SPEED_MPS;
 double angular_speed;
 int i;
// Initialize the node
ros::init(argc, argv, "move_turtle");
ros::NodeHandle node;
// A publisher for the movement data
ros::Publisher velocity_publisher = node.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
// Drive forward at a given speed. The robot points up the x-axis.
// The default constructor will set all commands to 0
geometry_msgs::Twist vel_msg;
/*cout<<"input linear velocity";
cin>>FORWARD_SPEED_MPS;
cout<<"input angular velocity";
cin>>angular_speed;
msg.linear.x = FORWARD_SPEED_MPS;
msg.angular.z=angular_speed;*/
double speed;
double distance;
bool isForward;
cout<<"enter linear speed";
cin>>speed;
//cout<<"enter distance vlaue";
//cin>>distance;
//cout<<"enter angular vel";
cout<<'input direction 1 or 0only';
cin>>isForward;

double t0=ros::Time::now().toSec();
if(isForward)
vel_msg.linear.x=abs(speed);

else
vel_msg.linear.x=-abs(speed);
cout<<t0;
ros::Time start_time = ros::Time::now();
ros::Duration timeout(2.0); // Timeout of 2 seconds
while(ros::Time::now() - start_time < timeout) {
  cout<<"looping";
  cout<<ros::Time::now() - start_time;
}

// Loop at 10Hz, publishing movement commands until we shut down
ros::Rate rate(10);
ROS_INFO("Starting to move forward");
while (ros::ok()) {
velocity_publisher.publish(vel_msg);
rate.sleep();
}
}




