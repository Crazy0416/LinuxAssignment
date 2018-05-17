#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

main(){
	struct stat	statbuf;
	if(stat("bar", &statbuf) < 0){	// bar 파일의 파일 정보를 statbuf에 저장
		perror("stat");
		exit(1);
	}

	if(chmod("bar", (statbuf.st_mode & ~S_IWGRP) | S_ISUID) < 0){	// bar 파일의 파일 권한을 원래 있던 모드에서 S_IWGRP를 끄고 S_ISUID를 킨다.
		perror("chmod");
		exit(1);
	}

	/* S_IRUSR, S_IWUSR, S_IRGRP, S_IROTH : ON */
	if(chmod("foo", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)){	// foo 파일의 파일 권한을 S_IRUSR, S_IWUSR, S_IRGRP, S_IROTH 로 바꾼다.
		perror("chmod");
		exit(1);
	}
}	
