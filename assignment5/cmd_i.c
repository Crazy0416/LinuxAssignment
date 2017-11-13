#include <stdio.h>

#define MAX_CMD		256


void DoCmd(char *cmd){			// 어떤 cmd 커맨드를 작동시킨다고 가정하는 함수	1초 wait하고 함수 종료
	printf("Doing %s", cmd);
	sleep(1);
	printf("Done\n");
}

main(){
	char 	cmd[MAX_CMD];
	
	while(1){
		printf("CMD> ");
		fgets(cmd, MAX_CMD, stdin);	// stdin에 입력한 문자열을 cmd 변수로 받는다.
		if(cmd[0] == 'q')		// cmd[0]=='q'면 반복 종료
			break;
		DoCmd(cmd);
	}
}
