#include <stdio.h>

#define	MAX_BUF	1024

main(int argc, char *argv[])
{
	FILE	*src1, *src2, *dst;
	char	buf[MAX_BUF];
	int		count;

	if (argc != 4)  {		// 아규먼트 오류 출력
		fprintf(stderr, "Usage: %s source1 source2 dest\n", argv[0]);
		exit(1);
	}

	if ((src1 = fopen(argv[1], "rb")) == NULL)  {	// argv[1] 파일을 읽기 형식으로 열고 src1에 FILE 객체 포인터를 저장
		perror("fopen");
		exit(1);
	}
	if ((src2 = fopen(argv[2], "rb")) == NULL)  {	// argv[2] 파일을 읽기 형식으로 열고 src2에 FILE 객체 포인터를 저장
		perror("fopen");
		exit(1);
	}
	if ((dst = fopen(argv[3], "wb")) == NULL)  {	// argv[3] 파일을 쓰기 형식으로 열고 dst 
		perror("fopen");
		exit(1);
	}

	while ((count = fread(buf, 1, MAX_BUF, src1)) > 0)  {	// src1 문자열을 읽은 만큼 	
		fwrite(buf, 1, count, dst);			// dst에 입력
	}

	while ((count = fread(buf, 1, MAX_BUF, src2)) > 0)  {	// src2 문자열을 읽은 만큼
		fwrite(buf, 1, count, dst);			// dst에 입력
	}

	fclose(src1);
	fclose(src2);
	fclose(dst);	//  모두 종료
}
