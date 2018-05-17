#include <stdio.h>
#include <signal.h>

static unsigned int	AlarmSecs;

void SigAlarmHandler(int signo){
	if(signal(SIGALRM, SigAlarmHandler) == SIG_ERR){	// SIGALRM 핸들러 등록. 안해줘도 되는 것 같다.
		perror("signal");
		exit(1);
	}

	alarm(AlarmSecs);	// AlarmSecs 후에 핸들러 함수 실행

	printf(".");		// stdout 버퍼에 . 문자열 삽입
	fflush(stdout);		// stdout 버퍼 비움

	return 0;
}

int SetPeriodicAlarm(unsigned int nsecs){
	if(signal(SIGALRM, SigAlarmHandler) == SIG_ERR){ 	// SIGALRM 핸들러 등록
		return -1;
	}
	
	AlarmSecs = nsecs;				// 전역변수 AlarmSecs에 nsecs 값 저장

	alarm(nsecs);					// nsecs 후에 SIGALRM 핸들러 실행

	return 0;
}

void main(){
	printf("Doing something every one seconds\n");
	SetPeriodicAlarm(1);
	for(;;)
		pause();	// 핸들러 함수 끝날때마다 풀리지만 for문에 의해 계속 pause
}
