#include <stdio.h>

#define	MAX_BUF	256

main(int argc, char *argv[])
{
	FILE	*fp;
	char	buf[MAX_BUF];
	int		line;

	if (argc != 2)  {		// 아규먼트 오류 처리
		printf("Usage: %s filename\n", argv[0]);
		exit(1);
	}

	if ((fp = fopen(argv[1], "rt")) == NULL)  {	// argv[1] 파일을 읽기모드로 열고 fp에 FILE 객체 포인터 저장
		perror("fopen");
		exit(1);
	}

	line = 1;
	while (fgets(buf, MAX_BUF, fp))  {	// fp 파일을 한 줄씩 읽기
		printf("%4d: %s", line++, buf);	// 읽은 라인의 라인넘버를 표시
	}

	fclose(fp);
}
