#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void signalHandler(int signo){
	return ;		// 부모프로세스의 pause 끝냄
}
void main(){
	int	pid;
	signal(SIGCHLD, signalHandler);	// 핸들러등록
	if((pid = fork()) < 0){
		perror("fork");
		exit(1);
	}
	else if(pid == 0){		// 자식프로세스
		sleep(1);		// 1초 대기
		printf("child die\n");
		exit(0);		// 1초 대기후 종료 SIGCHLD 발생
	}else{				// 부모프로세스
		pause();		// SIGCHLD 핸들러 종료 후 pause 끝
		printf("parent die\n");	// 출력 후 부모프로세스 종료
	}
}
