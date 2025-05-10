#pragma once

#include <iostream>
#include <fstream>
#include <string>

namespace file_utils
{

    void printFileContent(const std::string filePath)
    {
        std::fstream file;
        file.open(filePath, std::ios::in); // read mode

        if (!file)
        {
            std::cout << "Invalid path or file doesn't exist!" << std::endl;
            return; // exit the function
        }

        std::string line;

        // getting each line got returns, assigns it to line
        // we used this function previously
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }

        file.close();
    }

    void clearFileContent(const std::string filePath)
    {
        std::fstream file;
        file.open(filePath, std::ios::out);

        if (!file)
        {
            std::cout << "Invalid path or file doesn't exist!" << std::endl;
            return; // exit the function
        }

        file.close();

    }

    
}