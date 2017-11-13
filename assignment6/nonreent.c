#include <stdio.h>
#include <signal.h>
#include <pwd.h>


void
MyAlarmHandler(int signo)
{
	struct passwd	*rootptr;
	signal(SIGALRM, MyAlarmHandler);		// SIGALRM 핸들러 함수 등록

	alarm(3);			//3초 뒤에 핸들러함수 실행

	printf("in signal handler\n");
	if ((rootptr = getpwnam("root")) == NULL)  {	// getpwnam 함수 실행하여 CS에 root 유저 정보 저장. 그런데 여기서 getpwnam 함수가 종료되지 않는다. 종료되지 않기 때문에 프로세스는 멈춰있는 것처럼보인다. strcmp 함수에 있는 exit(0);를 삭제하고 조건문을 ==으로 바꾸면 1초간 printf가 출력되고 멈춘다.
		perror("getpwnam");
		exit(1);
	}
	return;
}

main()
{
	struct passwd	*ptr;

	signal(SIGALRM, MyAlarmHandler);	// SIGALRM 핸들러 등록
	alarm(3);		// 3초 뒤에 SIGALRM 핸들러 함수 실행

	for ( ; ; )  {		// 무한루프
		if ((ptr = getpwnam("cjs")) == NULL)  { // CS인 passwd에 cjs유저 정보 저장
			perror("getpwnam");
			exit(1);
		}

		if (strcmp(ptr->pw_name, "cjs") != 0)  { // CS가 핸들러함수에 의해 데이터가 변경되었다면 printf 조건문 실행
			printf("return value corrupted!, pw_name = %s\n", ptr->pw_name);
			exit(0);
		}
	}
}
