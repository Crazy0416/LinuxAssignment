#include <stdio.h>
#include <pthread.h>

void PrintMsg(char *msg){		// 문자열 출력하는 함수. 함수 종료직전 스레드를 종료한다.
	printf("%s", msg);
	pthread_exit(NULL);
}

main(){
	pthread_t	tid1, tid2;
	char		*msg1 = "Hello, ";
	char		*msg2 = "World!\n";

	if(pthread_create(&tid1, NULL, (void*)PrintMsg, (void*)msg1) < 0){	// PrintMsg를 스레드 등록 후 tid1에 스레드 객체 리턴
		perror("pthread_create");
		exit(1);
	}
	if(pthread_create(&tid2, NULL, (void*)PrintMsg, (void*)msg2) < 0){	// PrintMsg를 스레드 등록 후 tid2에 스레드 객체 리턴
		perror("pthread_create");
		exit(1);
	}
	
	printf("Thread created: tid= %d, %d\n", tid1, tid2);

	if(pthread_join(tid1, NULL) < 0) {	// tid1 스레드가 끝나길 기다린다.
		perror("pthread_join");
		exit(1);
	}
	if(pthread_join(tid2, NULL) < 0){	// tid2 스레드가 끝나길 기다린다.
		perror("pthread_join");
		exit(1);
	}

	printf("Thread terminated: tid = %d %d", tid1, tid2);
}
