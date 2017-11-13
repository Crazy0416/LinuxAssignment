#include <stdio.h>

main(int argc, char *argv[])
{
	FILE	*src, *dst;
	int		ch;

	if (argc != 3)  {	// 아규먼트 오류 처리
		fprintf(stderr, "Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	if ((src = fopen(argv[1], "rt")) == NULL)  {	// argv[1] 파일을 읽기 형식으로 연 뒤 src에 FILE 포인터 저장
		perror("fopen");
		exit(1);
	}

	if ((dst = fopen(argv[2], "wt")) == NULL)  {	// argv[2] 파일을 쓰기 형식으로 연 뒤 dst에 FILE 포인터 저장
		perror("fopen");
		exit(1);
	}

	while ((ch = fgetc(src)) != EOF)  {	// src 파일이 끝날때 까지 문자 하나씩 받아온
		fputc(ch, dst);			// 뒤에 dst 에 저장
	}

	fclose(src);
	fclose(dst);
}
