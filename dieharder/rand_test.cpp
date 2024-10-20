#include <iostream>
#include <fstream>
#include <random>

int main() {
    const int num_random_numbers = 10000000;

    std::ofstream file("mt_random_numbers.bin", std::ios::binary);
    
    if (!file) {
        std::cerr << "Error opening file for writing.\n";
        return 1;
    }

    std::random_device rd;
    std::mt19937 mt(rd());  

    std::uniform_int_distribution<unsigned int> dist(0, UINT32_MAX);

    for (int i = 0; i < num_random_numbers; i++) {
        unsigned int rand_num = dist(mt);
        file.write(reinterpret_cast<char*>(&rand_num), sizeof(rand_num));
    }

    file.close();

    std::cout << "Generated " << num_random_numbers << " random numbers and saved to mt_random_numbers.bin\n";
    
    return 0;
}

