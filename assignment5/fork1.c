#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

main(){
	int		pid;

	if((pid = fork()) == -1){	// fork 생성 및 오류 처리
		perror("fork");
		exit(1);
	}
	else if(pid == 0){		// 자식 프로세스는 이 명령어를 실행
		/* child */
		printf("I am %d. My parent is %d.\n", getpid(), getppid());
	}
	else{				// 부모 프로세스는 이 명령어를 실행, 
		/* parent */
		printf("I am %d, My child is %d.\n", getpid(), pid);
	}
}
