#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void CharAtaTime(char *str){
	char	*ptr;
	int	c, i;

	setbuf(stdout, NULL);			// stdout 스트림에 NULL 할당
	for (ptr = str ; c = *ptr++ ; )  {	// ptr의 문자 한개씩 c에 할당
		for(i = 0 ; i < 999999 ; i++)	// 연산 지연
			;
		putc(c, stdout);		// stdout에 c 출력 
	}
}

main()
{
	pid_t	pid;


	if ((pid = fork()) < 0)  {			// fork 실행 및 오류 처리
		perror("fork");
		exit(1);
	}
	else if (pid == 0)  {
		CharAtaTime("output from child\n");	// 자식 프로세스 일 경우 문자열 하나씩 출력
	} 
	else  {
		wait(NULL);				// 부모 프로세스 인 경우 자식 프로세스가 끝날 때 까지 기다림
		CharAtaTime("output from parent\n");	// 자식 프로세스가 끝난 것을 확인 후 문자열 하나씩 출력
	}
}
