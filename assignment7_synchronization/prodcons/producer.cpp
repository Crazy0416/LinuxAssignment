#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "prodcons.h"

int main() {
    BoundedBufferType 	*pBuf;
    int			shmid, data;

    if((shmid = shmget(SHM_KEY, SHM_SIZE, SHM_MODE)) < 0 ) {
        perror("shmget");
        exit(1);
    }
    if ((pBuf = (BoundedBufferType*)shmat(shmid, 0, 0)) == (void*)-1) {
        perror("shmat");
        exit(1);
    }

    srand(0x8888);

    int i = 0;

    for(; i < NLOOPS; i++) {
        if(pBuf->counter == MAX_BUF) {
            std::cout << "Producer: Buffer full. Waiting...." << std::endl;
            while(pBuf->counter == MAX_BUF)
                ;
        }

        std::cout << "Producer: Producing an item...." << std::endl;
        data = (rand() % 100)*10000;
        pBuf->buf[pBuf->in].data = data;
        pBuf->in = (pBuf->in + 1) % MAX_BUF;
        pBuf->counter++;
        std::cout << "Producer: counter " << pBuf->counter << std::endl;

        usleep(data);
    }

    std::cout << "Producer: Produced " << i << " items...." << std::endl;

    sleep(2);

    std::cout <<"Producer: " << pBuf->counter << " items in buffer....." << std::endl;

    if (shmctl(shmid, IPC_RMID, 0) < 0)  {
        perror("shmctl");
        exit(1);
    }
    return 0;
}
