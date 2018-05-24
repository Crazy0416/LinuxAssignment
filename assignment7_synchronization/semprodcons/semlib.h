//
// Created by kimminho on 18. 5. 17.
//

#ifndef SEMPRODCONS_SEMLIB_H
#define SEMPRODCONS_SEMLIB_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int		semInit(key_t key);
int		semInitValue(int semid, int value);
int		semWait(int semid);
int		semTryWait(int semid);
int		semPost(int semid);
int		semGetValue(int semid);
int		semDestroy(int semid);

#endif //SEMPRODCONS_SEMLIB_H
