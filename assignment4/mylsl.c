#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

main(int argc, char *argv[]){
	struct stat	statbuf;
	struct dirent	*dep;
	DIR		*dp;
	struct passwd	*my_passwd;
	struct group	*my_group;	
	char 		path[100];
	if(argc != 1){				// argument 오류처리
		fprintf(stderr, "U:%s must use one argv", argv[0]);
		exit(1);
	}
	if((dp = opendir(".")) == NULL){	// 현재 디렉토리 열고 디렉토리 정보 구조체 DIR 포인터를 반환
		perror("opendir");
		exit(1);
	}
	while(dep = readdir(dp)){		// dp 디렉토리의 파일, 디렉토리를 읽기
		strcpy(path, "./");
		strcat(path, dep->d_name);
		if(stat(path, &statbuf) < 0)	// 파일 정보 statbuf에 저장
			printf("stat err");
		my_group = getgrgid(statbuf.st_gid);
		my_passwd = getpwuid(statbuf.st_uid);	// file Owner와 Group 이름을 가지고 있는 객체
		
		// permission 정보
		printf((S_ISDIR(statbuf.st_mode))  ? "d" : "-");
  	 	printf((statbuf.st_mode & S_IRUSR) ? "r" : "-");
    		printf((statbuf.st_mode & S_IWUSR) ? "w" : "-");
    		printf((statbuf.st_mode & S_IXUSR) ? "x" : "-");
   		printf((statbuf.st_mode & S_IRGRP) ? "r" : "-");
    		printf((statbuf.st_mode & S_IWGRP) ? "w" : "-");
    		printf((statbuf.st_mode & S_IXGRP) ? "x" : "-");
    		printf((statbuf.st_mode & S_IROTH) ? "r" : "-");
    		printf((statbuf.st_mode & S_IWOTH) ? "w" : "-");
    		printf((statbuf.st_mode & S_IXOTH) ? "x  " : "-  ");
		
		printf("%2d", statbuf.st_nlink);		// file 링크 수
		printf("%8s ", my_passwd->pw_name);		// owner 이름
		printf("%8s ", my_group->gr_name);		// owner가 속한 group 이름
		printf("%8d ", statbuf.st_size);		// file size
		printf("%d ", statbuf.st_mtime);		// 최종 수정 일
		printf("%9s", dep->d_name);			// file 이름
		printf("\n");
		
	}

	closedir(dp);
}
