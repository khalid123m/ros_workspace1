//Alhamdulillah successful specific distance forward/backwards
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include<iostream>
#include "turtlesim/Pose.h"  //very important to declare to use poseCallback() function


turtlesim::Pose t_pose;//v. IMP to declare and it is case sensitive
void poseCallback(const turtlesim::PoseConstPtr& pose_message)
{
//ROS_INFO("x: %.2f, y: %.2f", msg->x, msg->y);
t_pose.x=pose_message->x;
t_pose.y=pose_message->y;
t_pose.theta=pose_message->theta;

}

ros::Subscriber pose_subsciber;
 ros::Publisher veloctiy_publisher;
 
using namespace std;
//ros::Publisher velocity_publisher;

void move(double speed, double distance, bool isForward);
void rotate(double angular_velocity, double angle, bool isclockwise);
double eucl_distance(double x1, double y1, double x2,double y2);
double find_angle(double x1, double y1, double x2,double y2); 
void go_to_goal(turtlesim::Pose goal_pose,double distance_tolerance);
 const double x_min=0;
 const double y_min=0;
 const double x_max=11.0;
 const double y_max=11.0;

 const double PI=3.14159265359;
int main(int argc, char **argv)
{


// Initialize the node
ros::init(argc, argv, "move_turtle");
ros::NodeHandle node;
// A publisher for the movement data
ros::Publisher velocity_publisher = node.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
ros::Subscriber sub = node.subscribe("turtle1/pose", 10, poseCallback);
// Drive forward at a given speed. The robot points up the x-axis.
// The default constructor will set all commands to 0
geometry_msgs::Twist vel_msg;
 



double speed;
double distance;
bool isForward;


double angular_velocity;
double angle;
bool isclockwise;

 //double x_goal=10;
 //double y_goal=4;


//input values for linear movement for a specific distance in a specific direction
/*cout<<"enter linear speed";
cin>>speed;
cout<<"enter distance vlaue";
cin>>distance;
cout<<"input direction 1 or 0 only";
cin>>isForward;

cout<<"enter angular velocity";
cin>>angular_velocity;
cout<<"enter angle in degrees";
cin>>angle;

cout<<"input rotation direction 1 or 0 only";
cin>>isclockwise;
*/
turtlesim::Pose goal_pose;
goal_pose.x=1;
goal_pose.y=1;
goal_pose.theta=0;
go_to_goal(goal_pose,0.01);
//move(speed,distance,isForward); 
//rotate(angular_velocity,angle,isclockwise); 
}



// function defined below for each activity such as move, rotate ... etc
void move(double speed, double distance, bool isForward)
{
geometry_msgs::Twist vel_msg;
ros::NodeHandle node;
ros::Publisher velocity_publisher = node.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
if(isForward)
vel_msg.linear.x=abs(speed);
 
else
vel_msg.linear.x=-abs(speed);
 
//ros::Time t0=ros::Time::now();
double current_distance=0.0;
ros::Rate loop_rate(100);
double t0=ros::Time::now().toSec();
do{
  velocity_publisher.publish(vel_msg);
   double t3=ros::Time::now().toSec();
   current_distance=speed*(t3-t0);
   ros::spinOnce();
   loop_rate.sleep();
}while (current_distance<distance);
vel_msg.linear.x=0;
 velocity_publisher.publish(vel_msg);
 
 
}

void rotate(double angular_velocity, double angle, bool isclockwise)
{
geometry_msgs::Twist vel_msg;
ros::NodeHandle node;
ros::Publisher velocity_publisher = node.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
angle=angle*PI/180;
angular_velocity=angular_velocity*PI/180;
vel_msg.linear.x=0;
vel_msg.linear.y=0;
vel_msg.linear.z=0;
vel_msg.angular.x=0;
vel_msg.angular.y=0;
if(isclockwise)
vel_msg.angular.z=abs(angular_velocity);
 
else
vel_msg.angular.z=-abs(angular_velocity);
 
//ros::Time t0=ros::Time::now();
double current_angle=0.0;
ros::Rate loop_rate(100);
double t0=ros::Time::now().toSec();
do{
  velocity_publisher.publish(vel_msg);
   double t3=ros::Time::now().toSec();
   current_angle=angular_velocity*(t3-t0);
   ros::spinOnce();
   loop_rate.sleep();
}while (current_angle<angle);
vel_msg.linear.z=0;
 velocity_publisher.publish(vel_msg);
 
 
}

 
double eucl_distance(double x1, double y1, double x2,double y2){

double d=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
return d;
}
 
double find_angle(double x1, double y1, double x2,double y2) 
{

double angle_g=atan2(y2-y1,x2-x1);
return angle_g;

}

void go_to_goal()
//turtlesim::Pose goal_pose,double distance_tolerance
{

geometry_msgs::Twist vel_msg;
///ros::init(argc, argv, "move_turtle");
//ros::NodeHandle node;
//ros::NodeHandle node;
//ros::Publisher velocity_publisher = node.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
ros::Rate loop_rate(100);

//vel_msg.linear.x=1.5*eucl_distance(t_pose.x,t_pose.y,goal_pose.x,goal_pose.y);
vel_msg.linear.x=1.5;
vel_msg.linear.y=0;
vel_msg.linear.z=0;
vel_msg.angular.x=0;
vel_msg.angular.y=0;
//vel_msg.angular.z=4*find_angle(t_pose.x,t_pose.y,goal_pose.x,goal_pose.y);
vel_msg.angular.z=4;
veloctiy_publisher.publish(vel_msg);
ros::spinOnce();
loop_rate.sleep();

//while(eucl_distance(t_pose.x,t_pose.y,goal_pose.x,goal_pose.y)>distance_tolerance);
//cout<<"goal reached";
//vel_msg.linear.x=0;
//vel_msg.angular.z=0;

//veloctiy_publisher.publish(vel_msg);
}
 
 
/*while(ros::Time::now() - start_time < timeout) {
   while(ros::Time::now() - start_time < t1){
 cout<<"first loop\n";
 vel_msg.linear.x=1;
 vel_msg.angular.z=0.5;
 ros::Rate rate(10);
ROS_INFO("***********right-turn********");
velocity_publisher.publish(vel_msg);}
 while(ros::Time::now() - start_time < t2){
   cout<<"second loop\n";
vel_msg.linear.x=1;
 vel_msg.angular.z=-0.5;
 ros::Rate rate(10);
ROS_INFO("***********left-turn***********");
velocity_publisher.publish(vel_msg);
 
/*while (ros::ok()) {
velocity_publisher.publish(vel_msg);
rate.sleep();
 }
}
 
cout<<"third loop\n";
vel_msg.linear.x=1;
 vel_msg.angular.z=-0;
// ros::Rate rate(10);
ROS_INFO("***********straight***********");
velocity_publisher.publish(vel_msg);
 
}
vel_msg.linear.x=0;
vel_msg.angular.z=-0;
velocity_publisher.publish(vel_msg);
}
 
*/
 
 
 






























//Alhamdulillah successful moveit
/*
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include<iostream>
using namespace std;
//ros::Publisher velocity_publisher;
//void move(double speed, double distance, bool isForward);

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

double speed;
double distance;
bool isForward;

ros::Time start_time = ros::Time::now();
ros::Duration timeout(6.0); // Timeout of 2 seconds
ros::Duration t1(2.0); 
ros::Duration t2(4.0);




cout<<"enter linear speed";
cin>>speed;
cout<<"enter distance vlaue";
cin>>distance;
cout<<"enter angular vel";
cout<<"input direction 1 or 0 only";
cin>>isForward;
//double t0;
//double t3;
//double current_distance=0;
//move(speed,distance,isForward);
//velocity_publisher.publish(vel_msg);
if(isForward)
vel_msg.linear.x=abs(speed);

else
vel_msg.linear.x=-abs(speed);

//ros::Time t0=ros::Time::now();
double current_distance=0.0;
ros::Rate loop_rate(100);
double t0=ros::Time::now().toSec();
do{
    velocity_publisher.publish(vel_msg);
    double t3=ros::Time::now().toSec();
    current_distance=speed*(t3-t0);;
    loop_rate.sleep();
}while (current_distance<distance);
vel_msg.linear.x=0;
velocity_publisher.publish(vel_msg);


}

*/






//code below for moving two robots
/*

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
// Topic messages callback
void poseCallback(const turtlesim::PoseConstPtr& msg)
{
ROS_INFO("x: %.2f, y: %.2f", msg->x, msg->y);
}
int main(int argc, char **argv)
{
const double FORWARD_SPEED_MPS = 0.5;
// Initialize the node
ros::init(argc, argv, "move_turtle");
ros::NodeHandle node;
// A publisher for the movement data
ros::Publisher pub = node.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
// A publisher for the movement data for turtle2
ros::Publisher foll = node.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10);
// A listener for pose
ros::Subscriber sub = node.subscribe("turtle1/pose", 10, poseCallback);
// Drive forward at a given speed. The robot points up the x-axis.
// The default constructor will set all commands to 
ros::Subscriber sub2 = node.subscribe("turtle2/pose", 10, poseCallback);
// Drive forward at a given speed. The robot points up the x-axis.
// The default constructor will set all commands to 

geometry_msgs::Twist msg;
geometry_msgs::Twist msg2;
msg.linear.x = FORWARD_SPEED_MPS;
msg2.angular.z=0.1;
msg2.linear.x=-1;
// Loop at 10Hz, publishing movement commands until we shut down
ros::Rate rate(10);
ROS_INFO("Starting to move forward");
while (ros::ok()) {
pub.publish(msg);
foll.publish(msg2);
ros::spinOnce(); // Allow processing of incoming messages
rate.sleep();
}
}
*/















/*void move(double speed, double distance, bool isForward)
{
geometry_msgs::Twist vel_msg;
if(isForward)
vel_msg.linear.x=abs(speed);

else
vel_msg.linear.x=-abs(speed);

//ros::Time t0=ros::Time::now();
double current_distance=0.0;
ros::Rate loop_rate(100);
double t0=ros::Time::now().toSec();
do{
    velocity_publisher.publish(vel_msg);
    double t3=ros::Time::now().toSec();
    current_distance=speed*(t3-t0);;
    loop_rate.sleep();
}while (current_distance<distance);
vel_msg.linear.x=0;
velocity_publisher.publish(vel_msg);


}
*/






/*while(ros::Time::now() - start_time < timeout) {
    while(ros::Time::now() - start_time < t1){
  cout<<"first loop\n";
  vel_msg.linear.x=1;
  vel_msg.angular.z=0.5;
  ros::Rate rate(10);
ROS_INFO("***********right-turn********");
velocity_publisher.publish(vel_msg);}
  while(ros::Time::now() - start_time < t2){
    cout<<"second loop\n";
vel_msg.linear.x=1;
  vel_msg.angular.z=-0.5;
  ros::Rate rate(10);
ROS_INFO("***********left-turn***********");
velocity_publisher.publish(vel_msg);

/*while (ros::ok()) {
velocity_publisher.publish(vel_msg);
rate.sleep();
  }
}

cout<<"third loop\n";
vel_msg.linear.x=1;
  vel_msg.angular.z=-0;
 // ros::Rate rate(10);
ROS_INFO("***********straight***********");
velocity_publisher.publish(vel_msg);

}
vel_msg.linear.x=0;
vel_msg.angular.z=-0;
velocity_publisher.publish(vel_msg);
}

*/

