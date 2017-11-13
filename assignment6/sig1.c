#include <stdio.h>
#include <signal.h>

void SigIntHandler(int signo) // ctrl + c 하면 함수 실행
{
	printf("Received a SIGINT signal\n");
	printf("Terminate this process\n");

	exit(0);
}

void main(){
	if(signal(SIGINT, SigIntHandler) == -1){ // SIGINT 핸들러 등록
		perror("singal");
		exit(1);
	}

	printf("Press ^C to quit\n");

	for( ; ; )
		pause();		// ^C 할때까지 대기
}
