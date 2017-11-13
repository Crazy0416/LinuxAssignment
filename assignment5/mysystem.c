#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define CMD_MAX		256

int mysysteml(char *cmd){			// execl 사용하는 함수
	char cmd_path[CMD_MAX] = "/bin/";
	strcat(cmd_path, cmd);
	return execl(cmd_path, cmd_path, NULL);
}

int mysystemv(char **cmd){			// execv 사용하는 함수
	char cmd_path[CMD_MAX] = "/bin/";
	strcat(cmd_path, cmd[0]);
	return execv(cmd_path, cmd);	
}

main(){
	pid_t		pid;
	char cmd[CMD_MAX];
	char* cmdArr[10];
	char* cmd_ptr;
	int status = 0;
	int i = 0;

	while(1){
		printf("CMD> ");
		gets(cmd);
		if(strcmp(cmd, "q") == 0){	// 프로세스 종료 조건
			break;
		}
		if((pid = fork()) < 0){		// fork 함수 실행 및 오류 처리
			perror("fork");
			exit(1);
		}
		if(pid == 0){
#if 0		// execl 함수 실행
			status = mysysteml(cmd);
#else		// execv 함수 실행
			cmd_ptr = strtok(cmd, " ");
			while(cmd_ptr != NULL){		// 공백을 기준으로 문자열 나눔
				cmdArr[i] = cmd_ptr;	// char 배열에 저장
				cmd_ptr = strtok(NULL, " ");
				i++;
			}
			cmdArr[i] = NULL;
			i = 0;
			status = mysystemv(cmdArr);	// char 배열을 인수로 넘김
#endif
			if (status == -1)
				exit(-1);		// exec 함수들이 오류로 인해 종료 될 경우?
		}
		else{
			wait(&status);			// 자식 프로세스 종료 wait
			if(status == -1){
				perror("자식 프로세스 비정상 종료");
			}
		}
	}
}
