#include <stdio.h>
#include <stdlib.h>

void myexit1(){
	printf("first exit handler\n");
}

void myexit2(){
	printf("second exit handler\n");
}

main(){
	/* Add myexit2 to exit function */
	if(atexit(myexit2) != 0){	// 프로세스가 종료되기 전 myexit2를 실행
		perror("atexit");
		exit(1);
	}
	if(atexit(myexit1) != 0){	// 프로세스가 종료되기 전 myexit1을 실행 myexit2보다 먼저 실행
		perror("atexit");
		exit(1);
	}
	if(atexit(myexit1) != 0){	// 프로세스가 종료되기 전 myexit1을 실행, 방금의 myexit1보다 먼저 실행
		perror("atexit");
		exit(1);
	}
	printf("main is done\n");
}
