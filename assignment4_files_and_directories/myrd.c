#include <stdio.h>
#include <unistd.h>

main(int argc, char *argv[]){
	if(argc != 2) {		// argument 오류 처리
		fprintf(stderr, "Usage: %s dirname\n", argv[0]);
		exit(1);
	}

	if(rmdir(argv[1]) < 0){		// argv[1] 디렉토리 삭제. 디렉토리 안에 파일이 존재하면 지울 수 없다.
		perror("rmdir");
		exit(1);
	}
}
