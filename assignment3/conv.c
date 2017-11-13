#include <stdio.h>
#include <string.h>
#include "record.h"

main(int argc, char *argv[])
{
	FILE	*src, *dst;
	Record	rec;					// Record 구조체 생성

	if (argc != 3)  {						// 아규먼트 오류처리
		fprintf(stderr, "Usage: %s source dest\n", argv[0]);
		exit(1);
	}

	if ((src = fopen(argv[1], "rt")) == NULL)  {	//argv[1] 파일 읽기 형식으로 열고 src에 FILE 객체 포인터 저장 
		perror("fopen");
		exit(1);
	}
	if ((dst = fopen(argv[2], "wb")) == NULL)  {	//argv[2] 파일 쓰기 형식으로 열고 dst에 FILE 객체 포인터 저장
		perror("fopen");
		exit(1);
	}

	while (fgets(rec.stud, SMAX, src))  {		// src에서 rec.stud 크기만큼 데이터 받음 파일 다 읽으면 while 함수 종료
		*strchr(rec.stud, '\n') = '\0';		// rec.stud 문자열 끝에 \0 넣음
		fgets(rec.num, NMAX, src);		// src에서 rec.num 크기만큼 문자열 받음
		*strchr(rec.num, '\n') = '\0';
		fgets(rec.dept, DMAX, src);		// src에서 rec.dept 크기만큼 문자열 받음
		*strchr(rec.dept, '\n') = '\0';
		
		printf("%s / %s / %s %d %d %d\n", rec.stud, rec.num, rec.dept, sizeof(rec.stud), sizeof(rec.num), sizeof(rec.dept));		// rec 객체 출력
		fwrite(rec.stud, 1, sizeof(rec.stud), dst);	// dst 파일에 rec 정보 write
		fwrite(rec.num, 1, sizeof(rec.num), dst);
		fwrite(rec.dept, 1, sizeof(rec).dept, dst);
	}

	fclose(src);	// 파일
	fclose(dst);	// 닫기
}
