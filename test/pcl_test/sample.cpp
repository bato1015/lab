#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <iostream>
using namespace std;

int main()
{
    // ポイントクラウド
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr p_cloud(new pcl::PointCloud<pcl::PointXYZRGBA>);
    p_cloud->width = 10;
    p_cloud->height = 10;
    p_cloud->points.resize(p_cloud->width * p_cloud->height);
    cout << "Size: " << p_cloud->width * p_cloud->height << std::endl;

    // あるポイントの座標
    pcl::PointXYZRGBA &point = p_cloud->points[0];
    point.x = 0.5;
    point.y = 0.5;
    point.z = 0.5;
    point.r = 0;
    point.g = 255;
    point.b = 0;
    point.a = 255;
    return 0;
}