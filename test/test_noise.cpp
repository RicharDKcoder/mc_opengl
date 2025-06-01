#include "fast_noise_lite.hpp"
#include <iostream>

int main(int argc, const char** argv) {
    FastNoiseLite noise;
	noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);

	// Gather noise data
	int width = 2;
	int height = 2;
    float offset[width * height * 3];
    int index = 0;
    for (int x = -width / 2; x < width / 2; x++)
    {
        for (int z = -width / 2; z < height / 2; z++)
        {
            offset[index] = x;
            offset[index + 1] = noise.GetNoise((float)x, (float)z) * 10;
            offset[index + 2] = z;
            index += 3;
        }
    }
	for (size_t i = 0; i < width * height * 3; i++)
	{
		std::cout << offset[i] << "\t";
		if(i+1 % 3 == 0){
			std::cout << std::endl;
		}
	}
    return 0;
}