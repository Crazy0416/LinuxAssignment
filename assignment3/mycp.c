#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define	MAX_BUF	1024

main(int argc, char *argv[])
{
	int 	fd1, fd2, count;
	char	buf[MAX_BUF];

	if (argc != 3)  {		// 아규먼트 오류 처리
		printf("Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	if ((fd1 = open(argv[1], O_RDONLY)) < 0)  {	// argv[1]파일을 읽기 전용으로 열고 fd1 에 파일 디스크럽터 리턴
		perror("open");
		exit(1);
	}

	if ((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)  {	// argv[2] 파일을 쓰기, 기존 내용 삭제한 뒤 (없으면 새로 생성) chmod 644로 접근 권한 수정하고 fd2에 파일 디스크럽터 리턴
		perror("open");	
		exit(1);
	}

	while ((count = read(fd1, buf, MAX_BUF)) > 0)  {	// fd1 파일을 읽은 만큼
		write(fd2, buf, count);				// fd2에 입력
	}

	close(fd1);
	close(fd2);
}
