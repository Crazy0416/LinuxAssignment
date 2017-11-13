#include <stdio.h>

#define	MAX_BUF	1024

main(int argc, char *argv[])
{
	FILE	*src, *dst;
	char	buf[MAX_BUF];
	int		count;

	if (argc != 3)  {		// 아규먼트 오류 체크
		fprintf(stderr, "Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	if ((src = fopen(argv[1], "rb")) == NULL)  {	// argv[1] 파일을 읽기 형식으로 open 후 src에 FILE 포인터 저장
		perror("fopen");
		exit(1);
	}

	if ((dst = fopen(argv[2], "wb")) == NULL)  {	// argv[2] 파일을 쓰기 형식으로 open 후 dst 에 FILE 포인터 저장
		perror("fopen");
		exit(1);
	}

	while ((count = fread(buf, 1, MAX_BUF, src)) > 0)  {	// src 파일을 MAX_BUF 크기만큼 가져온다
		fwrite(buf, 1, count, dst);	// src에서 가져온 크기만큼 dst 파일에 입력
	}

	fclose(src);
	fclose(dst);
}
