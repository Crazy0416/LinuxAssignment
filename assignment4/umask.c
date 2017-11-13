#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

main(){
	umask(0);	// -------- 파일이나 디렉토리를 생성할때 권한을 지정
	if(creat("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH ) < 0){
		perror("creat");	//bar : rw-rw-rw-
		exit(1);
	}
	
	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH); // ---rw-rw-
	if(creat("foo", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) < 0){
		perror("creat");	// foo : rw-------
		exit(1);
	}
}
