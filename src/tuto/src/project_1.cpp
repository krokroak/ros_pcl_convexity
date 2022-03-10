#include <iostream>
#include <pcl_ros/point_cloud.h>
#include <pcl/conversions.h>


using namespace std;


int main(int argc, char** argv)
{
    ros :: init(argc, argv, "kroke");

    ros :: spin();
    return 0;
}