#include <stdio.h>
#include <unistd.h>

main(int argc, char *argv[]){
	if(argc != 3) {		// argument 오류 처리
		fprintf(stderr, "Usage: %s source destinaion\n", argv[0]);
		exit(1);
	}

	if(link(argv[1], argv[2]) < 0){	// argv[1] 파일의 링크를 argv[2] path에 생성
		perror("link");
		exit(1);
	}
}
