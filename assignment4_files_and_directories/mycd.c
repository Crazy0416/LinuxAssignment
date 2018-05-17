#include <stdio.h>
#include <unistd.h>

main(int argc, char *argv[]){
	if(argc != 2) {			// argument 오류 처리
		fprintf(stderr, "Usage: %s dirname\n", argv[0]);
		exit(1);
	}
	
	if(chdir(argv[1]) < 0){		// argv[1]로 현재 작업 디렉토리 변경
		perror("chdir");
		exit(1);
	}
}
