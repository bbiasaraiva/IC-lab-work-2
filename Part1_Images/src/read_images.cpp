#include "read_images.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

std::vector<uint16_t> read_raw16(std::string file_name) {

    // opens the file in the end, to count the total size
    std::ifstream file(file_name, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    int file_size = file.tellg();
    file.seekg(0, std::ios::beg);
    int total_pixels = file_size / sizeof(uint16_t);

    std::cout << "File size: " << file_size << " bytes\n";

    std::vector<uint16_t> pixels(total_pixels);

    if (!file.read(reinterpret_cast<char*>(pixels.data()), file_size)) {
        throw std::runtime_error("Failed to read from file");
    }

    file.close();

    return pixels;
}

std::vector<uint8_t> read_pgm8(std::string file_name) {

    // opens the file in the end, to count the total size
    std::ifstream file(file_name, std::ios::binary | std::ios::ate);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    int file_size = file.tellg();
    file.seekg(0, std::ios::beg);
    int total_pixels = file_size / sizeof(uint8_t);

    std::cout << "File size: " << file_size << " bytes\n";

    std::vector<uint8_t> pixels(total_pixels, 0);

    // TODO: extrair dados

    file.close();


    // Teste

    uint8_t buffer;
    std::FILE* f = std::fopen("../datasets/imgs-pgm8/barbara.pgm", "r");

    while (std::fread(&buffer, sizeof(uint8_t), 1, f)) {
        std::cout << buffer << "\n";
    }

    std::fclose(f);




    return pixels;

}