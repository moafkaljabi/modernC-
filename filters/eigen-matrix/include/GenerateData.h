/*

This class is used to genetate simulated IMU data

*/

#pragma once

#include "iostream"
#include "istream"
#include "fstream"
#include "chrono"
#include "random"
#include "thread"

class GenerateData {

public:
    GenerateData(const std::string& filename, int duration, int sampleRate);
    void generate();

//    ~GenerateData();

private: 
    std::string filename;
    int duration;
    int sampleRate;

private:
    float generateRandom(float min, float x);

};


