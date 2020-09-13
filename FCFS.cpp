#include "FileHandler.h"
#include "Process.h"

#include <iostream>

#define EXIT_SUCCESS 0

int main() { 
    FileHandler handler;
    std::vector<Process> processes = handler.readToVector();
    std::vector<Process> queue;
    std::vector<Process> executed;
    Process* currProcess = NULL;
    unsigned int pos = 0;
    int clock = 0; 
    while(pos != processes.size() || queue.size() != 0 || currProcess != NULL) {
        //check if there is a process that is currently on the CPU
        if(currProcess != NULL) 
        {
            // check if the current process is finished
            if(clock - currProcess->start == currProcess->burstTime)  {
                currProcess->end = clock;
                executed.push_back(*currProcess);
                currProcess = NULL;
            }
        }
        // check if there are any processes to be scheduled
        if(pos != processes.size()) {
            if(clock == processes[pos].arrivalTime) {
                queue.push_back(processes[pos]);
                pos++;
            }
        }
        // check if any process is ready to be scheduled to the CPU
        if(queue.size() != 0 && currProcess == NULL) {
            Process proc = Process(queue[0].id, queue[0].burstTime, queue[0].arrivalTime, clock);
            currProcess = &proc;
            queue.erase(queue.begin());
        }
        clock++;
    }
    handler.displayProcesses(executed);
    std::cout << "size of executed" << executed.size() << " || size of input is " << processes.size() << " || clock: " << clock << " || pos is: " << pos << std::endl;
}