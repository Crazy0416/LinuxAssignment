#include <stdio.h>
#include <unistd.h>

#define MAX_BUF 256

main(int argc, char *argv[]){
	char	buf[MAX_BUF];
	
	if(getcwd(buf, MAX_BUF) < 0){		// 현재 작업하는 디렉토리를 buf에 담는다.
		perror("getcwd");
		exit(1);
	}

	printf("%s\n", buf);
}
