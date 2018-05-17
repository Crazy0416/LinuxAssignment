#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char	*EnvInit[] = {"USER=unknown", "PATH=/tmp", NULL};

main(){
	pid_t	pid;
	if((pid = fork()) < 0){		// fork 함수 실행 및 오류 처리
		perror("fork");
		exit(1);
	}
	else if(pid == 0) {		// 자식 프로세스인 경우
		if(execle("/home/cjs/lsp/process/env", "env", "myarg1", "MYARG2", NULL, EnvInit) < 0) {			// path에 있는 프로그램을 env, myarg1, MTARG2, NULL argument와 EnvInit 환경변수 를 가지고 실행. 외부 프로세스가 실행되면 이 자식 프로세스는 종료
			perror("execle");
			exit(1);
		}
	}
	if(waitpid(pid, NULL, 0) < 0){	// 부모 프로세스는 자식 프로세스가 끝날때까지 기다린다. 위의 env가 종료되면 다음 명령어를 수행한다.
		perror("waitpid");
		exit(1);
	}
	// 현재 부모프로세스 존재, 자식프로세스는 execle를 마치고 종료됨
	if((pid = fork()) < 0){		// fork 함수 실행 및 오류처리
		perror("fork");
		exit(1);
	}
	else if(pid == 0){		// 자식프로세스인 경우
		if(execlp("env", "env", NULL) < 0){	// 환경변수 path에 있는 등록된 디렉토리 안의  env 파일 실행 뒤 프로세스 종료
			perror("execlp");
			exit(1);
		}
	}
}
