#include <stdio.h>
#include <signal.h>

void SigAlarmHandler(int signo){
	return ;
}

unsigned int mysleep(unsigned int nsecs){
	if(signal(SIGALRM ,SigAlarmHandler) == -1){  // SIGALRM 핸들러 등록
		return nsecs;
	}
	alarm(nsecs);	// nsecs 뒤에 핸들러 함수 실행
	pause();	// 함수 실행까지 대기
	return alarm(0);	// 0초간 대기할 수 없으니 바로 종료
}

void main(){
	printf("Wait for 5 seconds...\n");

	mysleep(5);
}
