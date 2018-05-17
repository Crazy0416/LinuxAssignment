#include <stdio.h>
#include <signal.h>

void SigUsrHandler(int signo){
	if(signo == SIGUSR1)	{		// 유저가 등록한 SIGUSR1이 오면 실행
		printf("Received a SIGUSR1 signal\n");
	}
	else if(signo == SIGUSR2)	{	// 유저가 등록한 SIGUSR2이 오면 실행
		printf("Received a SIGUSR2 signal\n");
	}
	else {					// 다른 SIGNAL이 등록되지 않았으므로 이건 영원히 실행불가
		printf("Received a unknown signal\n");
		printf("Terminate this process\n");
		exit(0);
	}
}

void main(){
	if(signal(SIGUSR1, SigUsrHandler) == SIG_ERR){		// SIGUSR1 핸들러 등록
		perror("signal");
		exit(1);
	}
	if(signal(SIGUSR2, SigUsrHandler) == SIG_ERR){		// SIGUSR2 핸들러 등록
		perror("signal");
		exit(1);
	}

	for(;;)
		pause();			// 대기
}		
