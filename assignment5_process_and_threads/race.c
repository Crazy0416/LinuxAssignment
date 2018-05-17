#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void CharAtaTime(char *str){
	char	*ptr;
	int	c, i;
	
	setbuf(stdout, NULL);		// stdout 스트림에 NULL 할당
	for(ptr = str; c = *ptr++;){	// ptr을 한글자씩 c에 대입
		for(i = 0; i < 999999; i++)	// 연산 지연
			;
		putc(c, stdout);		// stdout에 c 출력
	}
}

main()
{
	pid_t	pid;
	if((pid = fork()) < 0){		// fork 실행 및 오류 처리
		perror("fork");
		exit(1);
	}
	else if(pid == 0){		// 자식 프로세스이면 한글자씩 문자 출력
		CharAtaTime("output from a child\n");
	}
	else{				// 부모 프로세스이면 한글자씩 문자 출력
		CharAtaTime("output from a parent\n");
	}
}
