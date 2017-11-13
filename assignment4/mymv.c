#include <stdio.h>

main(int argc, char *argv[]){
	if(argc != 3){		// argument 오류 처리
		fprintf(stderr, "Usage: %s old new\n", argv[0]);
		exit(1);
	}

	if(rename(argv[1], argv[2])){	// argv[1] 파일을 argv[2] 이름으로 바꾼다.
		perror("rename");
		exit(1);
	}
}
