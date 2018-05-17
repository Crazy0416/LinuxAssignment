#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH	256

void JustDoIt(char *path){
	DIR		*dp;
	struct dirent	*dep;
	struct stat	statbuf;
	char		fullpath[MAX_PATH];

	if((dp = opendir(path)) == NULL){	// path 경로의 디렉토리를 열고 정보 구조체인 DIR 포인터를 반환
		perror("opendir");
		exit(0);
	}

	printf("\n%s:\n", path);
	while(dep = readdir(dp)) {		// opendir로 열었던 디렉토리 안의 파일과 디렉토리 검색
		if(strcmp(".", dep->d_name) == 0 || strcmp("..", dep->d_name) == 0)	// .과 .. 디렉토리는 skip
			continue;
		printf("%s\n", dep->d_name);
	}

	rewinddir(dp);		// 파일 처음으로 돌아감
	while(dep = readdir(dp)) {	// opendir로 열었던 디렉토리 안의 파일과 디렉토리 검색
		if(strcmp(".", dep->d_name) == 0 || strcmp("..", dep->d_name) == 0)	// .과 .. 디렉토리 skip
			continue;
		strcpy(fullpath, path);			// fullpath == path
		strcat(fullpath, "/");			// fullpath == path/
		strcat(fullpath, dep->d_name);		// fullpath == path/파일이름
		if(lstat(fullpath, &statbuf) < 0){	// fullpath의 파일 정보 가져옴
			perror("lstat");
			exit(1);
		}
		if(S_ISDIR(statbuf.st_mode)) {		// fullpath가 디렉토리라면
			JustDoIt(fullpath);		// 재귀함수
		}
	}
	closedir(dp);			// 열었던 디렉토리 닫음
}
main(){
	JustDoIt(".");			// 현재 디렉토리에서 JustDoIt 실행
}
