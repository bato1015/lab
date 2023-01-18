#include <iostream>
#include <Eigen/Core>
#include<cmath>
//deg→rad
double r(int n){
    return n*3.1415/180;
}

Eigen::Matrix4d body_angle;
Eigen::Matrix4d boom_angle;
Eigen::Matrix4d arm_angle;

int body=40,boom=0,arm=0;
double crower=1.5,boom_l=6.66,arm_l=2.99;

void cal_dainyuu(){
    body_angle<<cos(r(body)),0,sin(r(body)),0,
                0,1,0,0,
                -sin(r(body)),0,cos(r(body)),0,
                0,0,0,1;

    boom_angle<<1,0,0,0,
                0,cos(r(boom)),-sin(r(boom)),crower,
                0,sin(r(boom)),cos(r(boom)),0,
                0,0,0,1;

    arm_angle<< 1,0,0,0,
                0,cos(r(arm)),-sin(r(arm)),boom_l,
                0,sin(r(arm)),cos(r(arm)),0,
                0,0,0,1;
}


int main( ) {
    cal_dainyuu();

    std::cout<<body_angle<<"\n"<<boom_angle<<"\n"<<arm_angle;
    return ( 0 );
}