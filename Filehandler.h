#ifndef FILE_READER
#define FILE_READER

#include "Process.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

class FileHandler { 
    public: 
    
    const std::string FILENAME = "processes-3";
    std::vector<Process> readToVector();
    void writeToFile(std::vector<Process> &processes, std::string fileName);
    void displayProcesses(std::vector<Process> &completed);
    Process getProcess(std::string &line);
};

#endif // FILE_READER