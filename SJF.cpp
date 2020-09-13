#include "Process.h"
#include "FileHandler.h"
#include <iostream>
#include <string>
#include <vector> 

#define EXIT_SUCCESS 0
#define EMPTY        0

int main() {
    FileHandler handler = FileHandler();

    std::vector<Process> processes = handler.readToVector();
    std::vector<Process> queue;
    std::vector<Process> completed;

    int clock = 0;
    unsigned int pos = 0;
    Process* currProcess = NULL;
    while(pos != processes.size() || currProcess != NULL || queue.size() != 0) {

        // check if there is currently a process on the CPU 
            // check if it is completed 
        if(currProcess != NULL) {
            if(clock - currProcess->start == currProcess-> burstTime) {
                currProcess->end = clock;
                completed.push_back(*currProcess);
                currProcess = NULL;
            }
        }
        // check if there are any processes to be added to the queue
        if(pos != processes.size()) {
            if(processes[pos].arrivalTime == clock) {
                queue.push_back(processes[pos]);
                pos++;
            }
        }
        // if processor is not busy schedule the next process if it exists
            // select the process with the lowest burstTime and set that is the current process

        if(currProcess == NULL && queue.size() != 0) {
            double bt = queue[0].burstTime;
            int shortestIndex = 0;
            for(unsigned int i = 0; i < queue.size(); i++) {
                // find the job with the shortest burstTime 
                if(queue[i].burstTime < bt) {
                    bt = queue[i].burstTime;
                    shortestIndex = i;
                }
            }
            Process proc = Process(queue[shortestIndex].id, queue[shortestIndex].burstTime, queue[shortestIndex].arrivalTime, clock);
            currProcess = &proc;
            queue.erase(queue.begin() + shortestIndex);
        }
        clock++;
    }
    handler.displayProcesses(completed);
    std::cout << completed.size() << " || queue " << queue.size() << " || processes " << processes.size() << " || pos " << pos << " || clock " << clock << std::endl;  
    return EXIT_SUCCESS;
}