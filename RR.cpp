#include "Process.h"
#include "FileHandler.h"

#include <iostream>
#include <vector>
#include <string>

#define EXIT_SUCCESS    0
#define QUANTUM         2
#define CTT             0.1

int main()
{
    FileHandler handler = FileHandler();
    std::vector<Process> processes = handler.readToVector();
    std::vector<Process> queue;
    std::vector<Process> completed;

    unsigned int pos = 0;
    double clock = 0;
    Process *currProcess = NULL;
    
    while (pos != processes.size() || currProcess != NULL || queue.size() != 0)
    {
        // check if the CPU is in use
        if (currProcess != NULL)
        {
            // Check if it has been on the processor for the given quantum
            if (currProcess->remainingTime == 0 || currProcess->remainingTime <= 0)
            {
                currProcess->end = clock;
                completed.push_back(*currProcess);
                currProcess = NULL;
            }
            else if (clock - currProcess->tempStart == QUANTUM)
            {
                currProcess = NULL;
            }
            else
            {
                currProcess->remainingTime--;
            }
        }
        // check if there is a process to be added to the queue
        if (processes[pos].arrivalTime == clock)
        {
            queue.push_back(processes[pos]);
            pos++;
        }
        if (currProcess == NULL && queue.size() != 0)
        {
            std::cout << " swap process " << std::endl;
            // process has not started
            if (queue[0].start == -1)
            {
                std::cout << "Allocating process" << std::endl;
                Process proc = Process(queue[0].id, queue[0].burstTime, queue[0].arrivalTime, clock);
                proc.tempStart = clock;
                currProcess = &proc;
                queue.erase(queue.begin());
            }
            else
            {
                Process proc = Process(queue[0].id, queue[0].burstTime, queue[0].arrivalTime, queue[0].start);
                proc.tempStart = clock;
                currProcess = &proc;
                queue.erase(queue.begin());
            }
        }
        // check if a context switch needs to take place
        if (currProcess != NULL)
        {
            std::cout << currProcess->tempStart << " tempStart" << std::endl;
            if (queue.size() != 0 && currProcess->tempStart - clock == QUANTUM)
            {
                // move the process back onto the queue
                // context switch calculation time
                std::cout << "Context switch taken place " << std::endl;
                clock += CTT;
                queue.push_back(*currProcess);
                if (queue[0].start == -1)
                {
                    Process proc = Process(queue[0].id, queue[0].burstTime, queue[0].arrivalTime, clock);
                    currProcess = &proc;
                }
                else
                {
                    Process proc = Process(queue[0].id, queue[0].burstTime, queue[0].arrivalTime, queue[0].start, -1, queue[0].remainingTime, clock);
                    currProcess = &proc;
                }
                //remove the Process from the front
                queue.erase(queue.begin());
            }
        }
        // std::cout << "ID " << currProcess->id << " remaining time" << currProcess->remainingTime << " "
        //           << "clock: " << clock << " || pos: " << pos << " || completed size: " << completed.size() << " || queue size : " << queue.size() << std::endl;
        clock++;
    }
    // handler.displayProcesses(completed);
    return EXIT_SUCCESS;
}