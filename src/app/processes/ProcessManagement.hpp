#ifndef PROCESS_MANAGEMENT_HPP
#define PROCESS_MANAGEMENT_HPP


#include <queue>
#include <mutex>
#include <memory>
#include <atomic>
#include <semaphore.h>

#include "Task.hpp"


#define SHAREDMEM_CAPACITY 1000

class ProcessManagement {
    sem_t* itemsSemaphore;
    sem_t* emptySlotsSemaphore;

public:
    ProcessManagement();
    ~ProcessManagement();
    bool submitToQueue(std::unique_ptr<Task> task);
    void executeTask();

private:
    struct SharedMemory {
        // Use this Shared Memory as a queue.
        std::atomic<int> size;
        char tasks[SHAREDMEM_CAPACITY][256]; // 1000 (SHAREDMEM_CAPACITY) tasks, each task is 256 bytes long.
        int front;
        int rear;

        void printSharedMemory() {
            std::cout << "Shared Memory Size: " << size << std::endl;
            std::cout << "Front: " << front << std::endl;
            std::cout << "Rear: " << rear << std::endl;

            // std::cout << "Task Queue: " << std::endl;
            // for(int i=front; i<rear; i++) {
            //     std::cout << taskQueue[i] << " ";
            // }
            // std::cout << std::endl;
        }
    };

    SharedMemory* sharedMem; // Shared Memory Pointer
    int shmFd; // Shared Memory(shm) File Descriptor(fd)
    const char* SHM_NAME = "/taskQueue"; // Shared Memory(SHM) Name

    std::mutex queueLock;
};


#endif // PROCESS_MANAGEMENT_HPP
