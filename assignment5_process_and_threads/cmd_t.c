#include <stdio.h>
#include <pthread.h>

#define MAX_CMD		256

void DoCmd(char *cmd){			// cmd 명령어를 실행한다고 가정하는 함수. 함수 종료 직전 스레드를 종료시킨다.
	printf("Doing %s", cmd);
	sleep(1);
	printf("Done\n");

	pthread_exit(NULL);
}

main(){
	char		cmd[MAX_CMD];
	pthread_t	tid;

	while(1){
		printf("CMD> ");
		fgets(cmd, MAX_CMD, stdin);	// cmd에 stdin에 입력받은 문자열을 입력시킴
		if(cmd[0] == 'q')		// cmd[0] == 'q' 라면 반복 종료
			break;
		if(pthread_create(&tid, NULL, DoCmd, (char*) cmd)){	// DoCmd를 실행하는 스레드를 생성
			perror("pthread_create");
			exit(1);
		}
#if 1
		pthread_join(tid, NULL);		// DoCmd를 싱행하는 스레드가 끝나길 기다린다.
#endif
	}
	printf("end");
}
