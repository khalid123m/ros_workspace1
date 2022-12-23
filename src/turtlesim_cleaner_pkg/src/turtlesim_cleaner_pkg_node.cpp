//------------------------------------------------------------Go to goal or point navigation code start----------------------------------------------------

//Alhamdulillah successful specific distance forward/backwards
/*#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include<iostream>
#include "turtlesim/Pose.h"  //very important to declare to use poseCallback() function
#include <math.h> 

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
turtlesim::Pose goal_pose;
goal_pose.x=1;
goal_pose.y=1;
goal_pose.theta=0;
go_to_goal(goal_pose,0.01);

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

void go_to_goal(turtlesim::Pose goal_pose,double distance_tolerance)
{

geometry_msgs::Twist vel_msg;

ros::NodeHandle node;
ros::Publisher velocity_publisher = node.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
ros::Rate loop_rate(100);
do{
vel_msg.linear.x=1.2*eucl_distance(t_pose.x,t_pose.y,goal_pose.x,goal_pose.y);
//vel_msg.linear.x=1.5*sqrt(pow((goal_pose.x-t_pose.x),2)+pow((goal_pose.y-t_pose.y),2));
//vel_msg.linear.x=1.5*eucl_distance(goal_pose.x,goal_pose.y,t_pose.x,t_pose.y);
vel_msg.linear.y=0;
vel_msg.linear.z=0;
vel_msg.angular.x=0;
vel_msg.angular.y=0;
//vel_msg.angular.z=4*find_angle(t_pose.x,t_pose.y,goal_pose.x,goal_pose.y);
vel_msg.angular.z=4*(atan2(goal_pose.y-t_pose.y,goal_pose.x-t_pose.x)-t_pose.theta);
//vel_msg.angular.z=4;
velocity_publisher.publish(vel_msg);
ros::spinOnce();
loop_rate.sleep();
}while(eucl_distance(t_pose.x,t_pose.y,goal_pose.x,goal_pose.y)>distance_tolerance);
//while((sqrt(pow((goal_pose.x-t_pose.x),2)+pow((goal_pose.y-t_pose.y),2))>distance_tolerance));
//while(eucl_distance(t_pose.x,t_pose.y,goal_pose.x,goal_pose.y)>distance_tolerance);
cout<<"goal reached";
vel_msg.linear.x=0;
vel_msg.angular.z=0;

velocity_publisher.publish(vel_msg);
}

--------------go to goal or point navigation code end ---------------------------------------------------------------
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




//-----------------code for leader-follower starts here------------------------------------------------------------



//code below for moving two robots as of now it is a leader follower on 2 turtlesim robots

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"
#include<iostream>
using namespace std;
turtlesim::Pose t_pose_leader;
turtlesim::Pose t_pose_follower;
turtlesim::Pose t_pose_follower2;
const double PI=3.14159265359;
// Topic messages callback
void poseCallback(const turtlesim::PoseConstPtr& msg_leader)
{
ROS_INFO("x: %.2f, y: %.2f", msg_leader->x, msg_leader->y);
t_pose_leader.x=msg_leader->x;
t_pose_leader.y=msg_leader->y;
t_pose_leader.theta=msg_leader->theta;

}

void poseCallback2(const turtlesim::PoseConstPtr& msg_follower)
{
ROS_INFO("x: %.2f, y: %.2f", msg_follower->x, msg_follower->y);
t_pose_follower.x=msg_follower->x;
t_pose_follower.y=msg_follower->y;
t_pose_follower.theta=msg_follower->theta;

}

void poseCallback3(const turtlesim::PoseConstPtr& msg_follower2)
{
ROS_INFO("x: %.2f, y: %.2f", msg_follower2->x, msg_follower2->y);
t_pose_follower2.x=msg_follower2->x;
t_pose_follower2.y=msg_follower2->y;
t_pose_follower2.theta=msg_follower2->theta;

}


//void follower_robot(double x1,double x2,double x3,double x4);
void follower_robot(double xf,double yf,double xl,double yl,double thetaf);
void follower_robot2(double xf,double yf,double xl,double yl,double thetaf);
double constrainAngle(double x);
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
// A publisher for the movement data for turtle3
ros::Publisher foll2 = node.advertise<geometry_msgs::Twist>("turtle3/cmd_vel", 10);
// A listener for pose
ros::Subscriber sub = node.subscribe("turtle1/pose", 10, poseCallback);
// Drive forward at a given speed. The robot points up the x-axis.
// The default constructor will set all commands to 
ros::Subscriber sub2 = node.subscribe("turtle2/pose", 10, poseCallback2);

ros::Subscriber sub3 = node.subscribe("turtle3/pose", 10, poseCallback3);
// Drive forward at a given speed. The robot points up the x-axis.
// The default constructor will set all commands to 
geometry_msgs::Twist msg;
geometry_msgs::Twist msg2;
geometry_msgs::Twist msg3;
//msg.linear.x = FORWARD_SPEED_MPS;
//msg2.angular.z=0.1;
//msg2.linear.x=1;rosservice call /spawn "x: 0.0
/*y: 0.0
theta: 0.0
name: ''" 
name: "turtle2"*/
// Loop at 10Hz, publishing movement commands until we shut down
ros::Rate rate(10);
//ROS_INFO("Starting to move forward");
while (ros::ok()) {
//pub.publish(msg);
//foll.publish(msg2);
msg.linear.x=2;
msg.angular.z=1;
pub.publish(msg);
follower_robot(t_pose_follower.x,t_pose_follower.y,t_pose_leader.x,t_pose_leader.y,t_pose_follower.theta);
follower_robot2(t_pose_follower2.x,t_pose_follower2.y,t_pose_follower.x,t_pose_follower.y,t_pose_follower2.theta);
//ros::spinOnce(); // Allow processing of incoming messages
//rate.sleep();
ros::spinOnce(); // Allow processing of incoming messages
rate.sleep();
//follower_robot();
}


}

//void follower_robot(double x1,double x2,double x3,double x4)
void follower_robot(double xf,double yf,double xl,double yl,double thetaf)
{

ros::NodeHandle node;

    ros::Publisher pub = node.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
    ros::Publisher foll = node.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10);
    
    geometry_msgs::Twist msg;
geometry_msgs::Twist msg2;
   double T=0.05;
    double sum=0;
    double alpha=0.5;
    double d_offset=0;
    double R=1;
    //double k_v=0.3;
    double k_v=0.7;
    double ki=0.01;
    //double kg=0.5;
    double kg=0.5;
    double L=0.381;
    double r=0.0925;

double    error=sqrt(pow((xl-xf),2)+pow((yl-yf),2))+d_offset;
    //sampling time 
    
    sum=sum+T*error;
   double v=k_v*error+ki;
   double theta_prime=atan2(yl-yf,xl-xf);
   theta_prime=constrainAngle(theta_prime);
   double steering_angle=kg*(theta_prime-thetaf);
   
   double w= (v/L)*tan(steering_angle);
ros::Rate rate(10);

msg2.linear.x=v;
msg2.angular.z=w;

foll.publish(msg2); 
cout<<"this is leader robot position\n"<<t_pose_follower.y;
}


//void follower_robot(double x1,double x2,double x3,double x4)
void follower_robot2(double xf,double yf,double xl,double yl,double thetaf)
{

ros::NodeHandle node;

    ros::Publisher pub = node.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
    ros::Publisher foll = node.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10);
    ros::Publisher foll2 = node.advertise<geometry_msgs::Twist>("turtle3/cmd_vel", 10);
    geometry_msgs::Twist msg;
geometry_msgs::Twist msg3;

   double T=0.05;
    double sum=0;
    double alpha=0.5;
    double d_offset=0;
    double R=1;
    double k_v=0.8;
    double ki=0.01;
    double kg=0.5;
    double L=0.381;
    double r=0.0925;

double    error=sqrt(pow((xl-xf),2)+pow((yl-yf),2))+d_offset;
    //sampling time 
    
    sum=sum+T*error;
   double v=k_v*error+ki;
   double theta_prime=atan2(yl-yf,xl-xf);
   theta_prime=constrainAngle(theta_prime);
   double steering_angle=kg*(theta_prime-thetaf);
   
   double w= (v/L)*tan(steering_angle);
ros::Rate rate(10);

msg3.linear.x=v;
msg3.angular.z=w;

foll2.publish(msg3); 
cout<<"this is leader robot position\n"<<t_pose_follower.y;
}








double constrainAngle(double x){
    x = fmod(x + PI,2*PI);
    if (x < 0)
        x += 2*PI;
    return x - PI;
}


//------------------------------------------code for leader-follower ends here--------------------------------------------------














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