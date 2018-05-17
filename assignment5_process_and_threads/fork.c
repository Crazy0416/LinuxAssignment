#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int 		Var = 6;
char	Buf[] = "a write to stdout\n";

main(){
	int 		var;
	pid_t 		pid;

	var = 88;
	write(STDOUT_FILENO, Buf, sizeof(Buf)-1);	// stdout에 Buf 출력
	printf("Before fork\n");
	
	if((pid = fork()) < 0){			// fork 생성 및 오류 처리
		perror("fork");
		exit(1);
	}
	else if(pid == 0){		// 자식일 때 var==88, Var==6을 각각 ++ 한다.
		/*child*/
		Var++;
		var++;
	}
	else {				// 부모일 때 2초 idle 상태
		/*parent*/
		sleep(2);
	}
		
	printf("pid = %d, Var = %d, var = %d\n", getpid(), Var, var); // 부모에서 자식이 fork가 되면 메모리가 복사되기 때문에 전역변수, 지역변수 모두 복사된다.	=> 서로 다른 메모리 공간을 가진다.
}
