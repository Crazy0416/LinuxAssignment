#include <stdio.h>
#include <signal.h>
#include <pthread.h>

// 매크로 등록
//#define THREAD_MAIN
//#define THREAD_1
#define THREAD_2

void SigIntHandler(int signo){
	printf("Received a SIGINT signal by thread %d\n", pthread_self());	// SIGNAL 받는 것은 main 스레드이므로 main 스레드id 출력
	printf("Terminate this process\n");
	exit(0);
}

void Thread1(void *dummy){	// THREAD_1이 있으면 핸들러 등록
#ifdef THREAD_1
	signal(SIGINT, SigIntHandler);
#endif
	while(1)
		;
}

void Thread2(void *dummy){	// THREAD_2가 있으면 핸들러 등록
#ifdef THREAD_2
	signal(SIGINT, SigIntHandler);
#endif
	while(1)
		;
}

void main(){
	pthread_t	tid1, tid2;
	// 스레드 생성
	if(pthread_create(&tid2, NULL, (void*)Thread1, NULL) < 0){
		perror("pthread_create");
		exit(1);
	}
	if (pthread_create(&tid2, NULL, (void *)Thread2, NULL) < 0)  {
		perror("pthread_create");
		exit(1);
	}
	printf("Create two threads: tid1=%d, tid2=%d\n", tid1, tid2);
	printf("Main thread: tid=%d\n", pthread_self());

#ifdef THREAD_MAIN		// THREAD_MAIN이 있다면 핸들러 등록
	signal(SIGINT, SigIntHandler);
#endif
	printf("Press ^C to quit\n");
	for(;;)
		pause();
}
