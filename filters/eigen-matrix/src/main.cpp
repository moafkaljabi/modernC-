#include <iostream>
#include <eigen3/Eigen/Dense>

#include "../include/GenerateData.h"

int main()
{
    GenerateData generateData("IMU_data.csv",5,10);

    generateData.generate();
}   