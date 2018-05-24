//
// Created by kimminho on 18. 5. 17.
//

#include <sys/shm.h>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include "prodcons.h"
#include "semlib.h"

int main() {
    BoundedBufferType *pBuf;
    int                 shmid, data;
    int                 emptySemid, fullSemid, mutexSemid;

    if ((shmid = shmget(SHM_KEY, SHM_SIZE, SHM_MODE)) < 0)  {
        perror("shmget");
        exit(1);
    }
    if ((pBuf = (BoundedBufferType *)shmat(shmid, 0, 0)) == (void *) -1)  {
        perror("shmat");
        exit(1);
    }

    if ((emptySemid = semInit(EMPTY_SEM_KEY)) < 0)  {
        fprintf(stderr, "semInit failure\n");
        exit(1);
    }
    if ((fullSemid = semInit(FULL_SEM_KEY)) < 0)  {
        fprintf(stderr, "semInit failure\n");
        exit(1);
    }
    if ((mutexSemid = semInit(MUTEX_SEM_KEY)) < 0)  {
        fprintf(stderr, "semInit failure\n");
        exit(1);
    }

    if (semInitValue(emptySemid, MAX_BUF) < 0)  {
        fprintf(stderr, "semInitValue failure\n");
        exit(1);
    }
    if (semInitValue(fullSemid, 0) < 0)  {
        fprintf(stderr, "semInitValue failure\n");
        exit(1);
    }
    if (semInitValue(mutexSemid, 1) < 0)  {
        fprintf(stderr, "semInitValue failure\n");
        exit(1);
    }

    srand(0x9999);
    int cnt = 0;
    for (; cnt < NLOOPS ; cnt++)  {
        if(semWait(fullSemid) < 0) {
            fprintf(stderr, "semWait failure\n");
            exit(1);
        }
        if(semWait(mutexSemid) < 0) {
            fprintf(stderr, "semWait failure\n");
            exit(1);
        }

        printf("Consumer: Consuming an item.....\n");
        data = pBuf->buf[pBuf->out].data;
        pBuf->out = (pBuf->out + 1) % MAX_BUF;
        pBuf->counter--;

        if(semPost(mutexSemid) < 0) {
            fprintf(stderr, "semWait failure\n");
            exit(1);
        }
        if(semPost(emptySemid) < 0) {
            fprintf(stderr, "semWait failure\n");
            exit(1);
        }

        usleep((rand()%100)*10000);
    }
    printf("Consumer: Consumed %d items.....\n", cnt);
    printf("Consumer: %d items in buffer.....\n", pBuf->counter);
}