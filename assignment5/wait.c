#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

main(){
	pid_t	pid;
	int	status;

	if((pid = fork()) < 0){		// fork 실행 및 오류 처리
		perror("fork");
		exit(1);
	}

	else if(pid == 0){		// 자식 프로세스일때
		printf("I am a child\n");
		sleep(2);
	}
	else {
		wait(&status);		// 자식 프로세스가 종료될 때까지 부모 프로세스는 idle 상태. 자식 프로세스가 종료되면 다음 명령어들 실행
		printf("A child killed with %d status\n", status);
	}
}

