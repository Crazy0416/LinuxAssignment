#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

main(int argc, char *argv[]){
	if(argc != 2){		// argument 오류
		fprintf(stderr, "Usage: %s dirname\n", argv[0]);
		exit(1);
	}

	if(mkdir(argv[1], 0755) < 0){	// argv[1]의 디렉토리를 생성. 권한은 chmod 755와 같다.
		perror("mkdir");
		exit(1);
	}
}
