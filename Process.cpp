#include "Process.h"

Process::Process(int id, double burstTime, double arrivalTime, double start) {
    this->id = id;
    this->burstTime = burstTime; 
    this->arrivalTime = arrivalTime;
    this->start = start;
}

Process::Process(int id, double burstTime, double arrivalTime, 
        double start, double end, double remainingTime) {
    this->id = id;
    this->burstTime = burstTime; 
    this->arrivalTime = arrivalTime;
    this->start = start;
    this->end = end; 
    this->remainingTime = remainingTime;
}

Process::Process(int id, double burstTime, double arrivalTime, 
        double start, double end, double remainingTime, double tempStart) {
    this->id = id;
    this->burstTime = burstTime; 
    this->arrivalTime = arrivalTime;
    this->start = start;
    this->end = end; 
    this->remainingTime = remainingTime;
    this->tempStart = tempStart;
}
void Process::display() { 
    std::cout << id << " " << burstTime << " " << arrivalTime << " " << start << " " << end << " " << remainingTime <<  std::endl;
}