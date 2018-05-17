#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

main()
{
	int 	fd;
	char	ch = '\0';

	if ((fd = creat("file.hole", 0400)) < 0)  {	//chmod 400으로 file.hole을 생성
		perror("creat");
		exit(1);
	}

	if (lseek(fd, 1023, SEEK_SET) < 0)  {		// 파일 iterator를 1023으로 옮김 옮기면 남은 공간은 0으로 채워짐
		perror("lseek");
		exit(1);
	}
	write(fd, &ch, 1);				// 파일 1024위치에 \0 쓰기

	close(fd);
}
