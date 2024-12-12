/*
Name : Prem Gopal Chuniyan
Roll No : 75
TITLE: Queues are frequently used in computer programming, and a typical example is the 
creation of a job queue by an operating system. If the operating system does not use priorities, 
then the jobs are processed in the order they enter the system. Write C++ program for 
simulating job queue. Write functions to add job and delete job from queue. 
*/

#include <iostream>
#include <queue>
#include <string>

class JobQueue {
private:
    std::queue<std::string> jobs;

public:
    // Function to add a job to the queue
    void addJob(const std::string& job) {
        jobs.push(job);
        std::cout << "Job added: " << job << std::endl;
    }

    // Function to delete a job from the queue
    void deleteJob() {
        if (jobs.empty()) {
            std::cout << "No jobs to delete." << std::endl;
            return;
        }
        std::cout << "Job deleted: " << jobs.front() << std::endl;
        jobs.pop();
    }

    // Function to display the current jobs in the queue
    void displayJobs() const {
        if (jobs.empty()) {
            std::cout << "The job queue is empty." << std::endl;
            return;
        }
        std::cout << "Current jobs in the queue: ";
        std::queue<std::string> tempQueue = jobs; // Create a copy to display
        while (!tempQueue.empty()) {
            std::cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        std::cout << std::endl;
    }
};

int main() {
    JobQueue jobQueue;
    int choice;
    std::string job;
    do {
        std::cout << "\nJob Queue Menu:\n";
        std::cout << "1. Add Job\n";
        std::cout << "2. Delete Job\n";
        std::cout << "3. Display Jobs\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter job name: ";
                std::cin >> job;
                jobQueue.addJob(job);
                break;
            case 2:
                jobQueue.deleteJob();
                break;
            case 3:
                jobQueue.displayJobs();
                break;
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
        }
    } while (choice != 4);
    return 0;
}

