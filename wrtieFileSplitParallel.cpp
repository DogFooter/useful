#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <thread>
#include <fstream>
#include <string>

void writeToFile(const std::vector<short>& data, size_t start, size_t end, int fileIndex) {
    std::string filename = "file_" + std::to_string(fileIndex + 1) + ".dat";
    FILE* file = fopen(filename.c_str(), "wb");

    if (file != nullptr) {
        fwrite(&data[start], sizeof(short), end - start, file);
        fclose(file);
    }
}

void writeDataParallel(std::vector<short>& data, size_t bytesPerFile) {
    const size_t shortsPerFile = bytesPerFile / sizeof(short);

    // Calculate number of files
    int numFiles = (data.size() + shortsPerFile - 1) / shortsPerFile;

    // Create and manage threads
    std::vector<std::thread> threads;

    for (int i = 0; i < numFiles; ++i) {
        size_t start = i * shortsPerFile;
        size_t end = std::min(start + shortsPerFile, data.size());

        threads.emplace_back(writeToFile, std::ref(data), start, end, i);

    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }
}

int main() {

    // Prepare your data
    const int dataSize = 1000000; // 1MB
    std::vector<short> data(dataSize);

    // Populate the vector with some values here...

    const size_t bytesPerFile = 30000; //3KB

    writeDataParallel(data, bytesPerFile);

}