#include <stdio.h>
#include <unistd.h>

#define	MAX_BUF	1024

long
filesize(FILE *fp)
{
	long	cur, size;

	cur = ftell(fp);		// 현재 파일 위치를 cur에 저장
	fseek(fp, 0L, SEEK_END);	// 파일 끝으로 이동
	size = ftell(fp);		// size에 파일 크기 저장
	fseek(fp, cur, SEEK_SET);	// 파일 원래 위치로 이동
	return(size);			// 파일 크기 리턴
}

main(int argc, char *argv[])
{
	FILE	*src, *dst1, *dst2;
	char	buf[MAX_BUF];
	int		count, size;

	if (argc != 4)  {		// 아규먼트 오류 처리
		fprintf(stderr, "Usage: %s source dest1 dest2\n", argv[0]);
		exit(1);
	}

	if ((src = fopen(argv[1], "rb")) == NULL)  {	// argv[1] 파일을 읽기형식으로 연 뒤에 src에 FILE 포인터 저장
		perror("fopen");
		exit(1);
	}
	if ((dst1 = fopen(argv[2], "wb")) == NULL)  {	// argv[2] 파일을 쓰기 형식으로 연 뒤에 dst1에 FILE 포인터 저장
		perror("fopen");
		exit(1);
	}
	if ((dst2 = fopen(argv[3], "wb")) == NULL)  {	// argv[3] 파일을 쓰기 형식으로 연 뒤에 dst2 에 FILE 포인터 저장
		perror("fopen");
		exit(1);
	}

	size = filesize(src) / 2;	// size에 파일 절반 크기를 저장

	while (size > 0)  {		// 파일 절반을 읽을때까지 반복
		count = (size > MAX_BUF) ?  MAX_BUF : size;	// size가 MAX_BUF 크기보다 작아지면 count 에 size 저장 그 외에는 MAX_BUF 크기만큼 count에 저장
		fread(buf, 1, count, src); 	// count 크기만큼 src 에서 데이터 읽기
		fwrite(buf, 1, count, dst1);	// count 크기만큼 dst1에 데이터 쓰기
		size -= count;			// size -= count
	}

	while ((count = fread(buf, 1, MAX_BUF, src)) > 0)  {	// src 파일의 나머지를 다 읽을 때까지
		fwrite(buf, 1, count, dst2);	// dst에 읽은 데이터 쓰기
	}

	fclose(src);
	fclose(dst1);
	fclose(dst2);
}
