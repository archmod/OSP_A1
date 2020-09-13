#include "FileHandler.h"

// given a string returns a process
Process FileHandler::getProcess(std::string &line) {
    std::vector<std::string> tokens;
    std::istringstream iss(line);
    for(std::string line; iss >> line;) {
        tokens.push_back(line);
        
    }
    // std::cout << tokens[0] << " " << tokens[1] << " " << tokens[2] << std::endl;
    Process process(std::stoi(tokens[0]), std::stoi(tokens[1]), std::stoi(tokens[2]), -1);
    return process;
}

std::vector<Process> FileHandler::readToVector() {
    std::vector<Process> processes;
    std::ifstream inFile;
    inFile.open("processes-3"); 
    if(inFile.good()) {
        std::string line;
        while(!inFile.eof()) {
            std::getline(inFile, line);
            processes.push_back(getProcess(line));
        }
    }
    else {
        std::cout << "File read error" << std::endl;
    }
    // displayProcesses(processes);
    return processes;
}

void FileHandler::displayProcesses(std::vector<Process> &completed) {
    for(unsigned int i = 0; i < completed.size(); i++) {
        std::cout << "process: " << completed[i].id << ", " << completed[i].burstTime << ", " << completed[i].arrivalTime << ", " << completed[i].start << std::endl;
    }
}
