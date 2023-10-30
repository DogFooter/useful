#pragma once

#include <iostream>
#include <fstream>

int printFileSize(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary | std::ios::ate);

    if (!file) {
        std::cout << "파일을 열 수 없습니다." << std::endl;
        return;
    }

    std::streampos fileSize = file.tellg();
    file.close();

    return static_cast<int>(fileSize);
}