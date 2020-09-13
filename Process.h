#ifndef PROCESS
#define PROCESS 

#include <string>
#include <iostream>

class Process {
public: 
    int id = -1;
    double burstTime, arrivalTime, start, end, remainingTime, totalWait, tempStart = -1;
    Process(int id, double burstTime, double arrivalTime, double start);
    Process(int id, double burstTime, double arrivalTime, double start,
            double end, double remainingTime);
    Process(int id, double burstTime, double arrivalTime, 
        double start, double end, double remainingTime, double tempStart);
    void display();

};

#endif