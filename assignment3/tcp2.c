#include <stdio.h>

#define	MAX_BUF	256

main(int argc, char *argv[])
{
	FILE	*src, *dst;
	char	buf[MAX_BUF];

	if (argc != 3)  {		// 아규먼트 오류 처리
		fprintf(stderr, "Usage: %s source destination\n", argv[0]);
		exit(1);
	}

	if ((src = fopen(argv[1], "rt")) == NULL)  {	// argv[1] 파일을 읽기 형식으로 연 뒤 src에 FILE 포인터 저장
		perror("fopen");
		exit(1);
	}

	if ((dst = fopen(argv[2], "wt")) == NULL)  {	// argv[2] 파일을 쓰기 형식으로 연 뒤 dst에  FILE 포인터 저장
		perror("fopen");
		exit(1);
	}

	while ((fgets(buf, MAX_BUF, src)) > 0)  {	// src에서 문자열을 읽어온 뒤에
		fputs(buf, dst);			// dst에 입력
	}

	fclose(src);
	fclose(dst);
}
