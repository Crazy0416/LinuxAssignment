#include <iostream>
#include <sys/shm.h>
#include <unistd.h>
#include "prodcons.h"

int main() {
    BoundedBufferType   *pBuf;
    int                 shmid, data;

    if((shmid = shmget(SHM_KEY, SHM_SIZE, SHM_MODE)) < 0) {
        perror("shmget");
        exit(1);
    }
    if((pBuf = (BoundedBufferType*)shmat(shmid, 0, 0)) == (void*)-1) {
        perror("shmat");
        exit(1);
    }

    srand(0x9999);

    int i = 0;
    for(; i < NLOOPS; i++) {
        if(pBuf->counter == 0) {
            std::cout << "Consumer: Buffer empty. Waiting..." << std::endl;
            while(pBuf->counter == 0)
                ;
        }

        std::cout << "Consumer: Consuming an item...." << std::endl;
        data = pBuf->buf[pBuf->out].data;
        pBuf->out = (pBuf->out + 1) % MAX_BUF;
        pBuf->counter--;

        usleep((rand() % 100) * 10000);
    }

    std::cout << "Consumer: Consumed " << i << " items....\n";
    std::cout << "Consumer: " << pBuf->counter << " item in buffer....\n";

    return 0;
}