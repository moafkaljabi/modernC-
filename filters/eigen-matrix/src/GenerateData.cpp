#include "../include/GenerateData.h"

GenerateData::GenerateData(const std::string& filename, int duration, int sampleRate)
: filename(filename), duration(duration), sampleRate(sampleRate){}

float GenerateData::generateRandom(float min,float max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());

    std::uniform_real_distribution <float> dist(min,max);
    return dist(gen);
}


void GenerateData::generate()
{
    std::ofstream file(filename);


    if (!file.is_open())
    {
        std::cerr << "Error opening file!\n";
        return; 
    }

    // Write CSV header 
    file << "timestamp,accel_X,accel_Y,accel_Z,gyro_x,gyro_y,gyro_z\n";


    auto startTime = std::chrono::system_clock::now();

    for(int i=0; i < sampleRate * duration; i++)
    {
        auto now = std::chrono::system_clock::now();
        auto timestamp = std::chrono::duration_cast<std::chrono::microseconds>(now - startTime).count();


        // Generate Data 
        float accel_X = generateRandom(-1.0f, 1.0f);
        float accel_Y = generateRandom(-1.0f, 1.0f);
        float accel_Z = generateRandom(9.7f, 9.9f);
        
        float gyro_X = generateRandom(-0.1f, 0.1f);
        float gyro_Y = generateRandom(-0.1f, 0.1f);
        float gyro_Z = generateRandom(-0.1f, 0.1f);


        // Write data to the CSV file
        file << timestamp << "," << accel_X << "," << accel_Y << "," << accel_Z << ","
             << gyro_X << "," << gyro_Y << "," << gyro_Z << "\n";

             std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate real-time delay

    }

    file.close();
    std::cout << "Date saved to file:" << filename << std::endl;


}
