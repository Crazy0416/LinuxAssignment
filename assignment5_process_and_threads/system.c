#include <stdio.h>
#include <stdlib.h>

main(){
	int	status;
	if((status = system("date")) < 0){ 		// date 커맨드 실행 뒤 명령어 끝난 후 명령어의 리턴 코드가 반환된다.
		perror("system");
		exit(1);
	}
	printf("exit status = %d\n", status);
	
	if((status = system("nosuchcommand")) < 0){	// nosuchcommand 커멘드 실행. 없으므로 오류를 반환한다.
		perror("system");	
		exit(1);
	}
	printf("exit status = %d\n", status);

	if((status = system("who; exit 44")) < 0){	// who; exit 44 커멘드 실행 뒤 명령어 끝난 후 명령어의 리턴 코드 반환
		perror("System");
		exit(1);
	}
	printf("exit status = %d\n", status);
}
