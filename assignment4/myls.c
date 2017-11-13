#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

main(){
	DIR		*dp;
	struct dirent	*dep;

	if((dp = opendir(".")) == NULL){	// 현재 디렉토리 열고 정보 구조체인 DIR 포인터를 반환
		perror("opendir");
		exit(0);
	}

	while(dep = readdir(dp)){		// opendir()로 연 디렉토리에 대해 그 안에 있는 모든  파일과 디렉토리 정보를 구함
		printf("%s\n", dep->d_name);	// 이름 출력
	}
	closedir(dp); 			// 열었던 dir 닫기
}
