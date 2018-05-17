#include <stdio.h>

#define	MAX_CMD		256

void DoCmd(char *cmd){		 	// cmd 명령어를 실행하는 함수로 가정. 1초동안 프로세스를 1초 wait 시킨다.
	printf("Doing %s", cmd);
	sleep(1);
	printf("Done\n");
}

main(){
	char	cmd[MAX_CMD];
	int		pid;
	while(1){
		printf("CMD> ");
		fgets(cmd, MAX_CMD, stdin);	// cmd 문자열에 입력한 문자열 입력 받음
		if(cmd[0] == 'q')		// cmd[0] == 'q' 면 반복 종료
			break;
		if((pid = fork()) < 0){		// fork 실행 및 오류 처리
			perror("fork");
			exit(1);
		}
		else if(pid == 0){		// 자식 프로세스라면
			DoCmd(cmd);		// DoCmd 함수 실행 후
			exit(0);		// 곧바로 종료
		}
#if 1
		else{				// 부모 프로세스라면
			wait(NULL);		// 자식 프로세스가 프로세스를 끝내길 기다린 뒤 while 반복
		}
#endif
	}
}

