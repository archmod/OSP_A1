#include "Process.h"
#include "FileHandler.h"

#include <iostream>
#include <vector>
#include <string>

#define EXIT_SUCCESS    0
#define QUANTUM         2
#define CTT             0.1

int main() { 
    FileHandler handler = FileHandler();
    std::vector<Process> processes = handler.readToVector();
    std::vector<Process> queue;
    std::vector<Process> completed;

    unsigned int pos = 0;
    double clock = 0;
    Process* currProcess = NULL;

    while(pos != processes.size() || currProcess != NULL; queue.size() != 0) {
        // check if the CPU is in use
        if(currProcess != NULL) {
            currProcess->remainingTime -= 1;
            // Check if it has been on the processor for the given quantum
            if(remainingTime == 0) {
                 
            }
            else if(clock - currProcess->tempStart == QUANTUM) {
                executed.push_back(*currProcess);
                currProcess = NULL;
            }
        }
        // check if there is a process to be added to the queue
        if(processes[pos].arrivalTime == clock) {
            queue.push_back(processes[pos]);
            pos++;
        }
        // check if a context switch needs to take place 
        if(currProcess != null && queue.size() != 0 && currProcess->tempStart - clock == QUANTUM) {
            // move the process back onto the queue 
            // context switch calculation time 
            clock += CTT; 
            queue.push_back(*currProcess);
            Process proc;
            if(queue[0].start == -1 ) {
                proc = Process(queue[0].id, queue[0].burstTime, queue[0].arrivalTime, clock);
            }
            else {
                proc = Process(queue[0].id, queue[0].burstTime, queue[0].arrivalTime, queue[0].start, -1, queue[0].remainingTime, clock);
            }
            //remove the Process from the front
            currProcess = &proc;
            queue.erase(queue.begin());
        }
        clock++;
    }
    std::cout << CTT << std::endl;
    return EXIT_SUCCESS;
}