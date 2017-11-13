#include <stdio.h>
#include <unistd.h>
#include "record.h"

void
print_record(Record *rp)	// Record 객체 정보 표준 출력 stdout에 출력
{
    puts(rp->stud);
    puts(rp->num);
    puts(rp->dept);
}

main(int argc, char *argv[])
{
    FILE	*fp;
    Record	rec;

    if (argc != 2)  {			// 아규먼트 오류 처리
        fprintf(stderr, "Usage: %s file\n", argv[0]);	// 표준 오류에 출력
        exit(1);
    }

    if ((fp = fopen(argv[1], "r+b")) == NULL)  {	// argv[1] 파일 읽기쓰기 형식으로 열고 fp에 FILE 객체 포인터 저장
        perror("fopen");
        exit(1);
    }

    printf("-----Ordered Record List-----\n");

    while (fread(&rec, sizeof(&rec), 1, fp))  {	// rec 객체 크기만큼 fp에서 읽고 다 읽으면 종료.
        print_record(&rec);
    }
    rewind(fp);		// 파일 iterator를 처음으로 옮김
    getchar();		// 입력 받길 기다림

    printf("-----Shuffled Record List (3, 6, 2, 4, 1, 5)-----\n");

    fseek(fp, sizeof(rec)*2L, SEEK_SET);	// rec 2개 크기로 파일의 iterator를 옮김
    fread(&rec, sizeof(rec), 1, fp);	// 파일의 rec 크기 한개만큼 읽고 rec객체에 저장
    print_record(&rec);			// 출력

    fseek(fp, sizeof(rec)*5L, SEEK_SET);	// rec 5개 크기로 파일의 iterator를 옮김
    fread(&rec, sizeof(rec), 1, fp);	// 파일의 rec 크기 1개만큼 읽고 rec 객체에 저장
    print_record(&rec);			// 출력

    fseek(fp, sizeof(rec)*1L, SEEK_SET);	// rec 1개 크기로 파일의 iterator를 옮김
    fread(&rec, sizeof(rec), 1, fp);	// 파일의 rec 크기 1개만큼 읽고 rec 객체에 저장
    print_record(&rec);			// 출력

    fseek(fp, sizeof(rec)*3L, SEEK_SET);	// rec 3개 크기로 파일의 iterator를 옮김
    fread(&rec, sizeof(rec), 1, fp);	// 파일의 rec 크기 1개만큼 읽고 rec 객체에 저장
    print_record(&rec);			// 출력

    fseek(fp, sizeof(rec)*0L, SEEK_SET);	// 파일의 맨 처음으로 iterator를 옮김
    fread(&rec, sizeof(rec), 1, fp);	// 파일의 rec 크기 1개만큼 읽고 rec 객체에 저장
    print_record(&rec);			// 출력

    fseek(fp, sizeof(rec)*4L, SEEK_SET);	// rec 4개 크기로 파일의 iterator를 옮김
    fread(&rec, sizeof(rec), 1, fp);	// 파일의 rec 크기 1개만큼 읽고 rec 객체에 저장
    print_record(&rec);			// 출력
    getchar();

    printf("-----Updated Record List-----\n");

    fseek(fp, sizeof(rec)*2L, SEEK_SET);	// rec 2개 크기로 파일의 iterator를 옮김
    fread(&rec, sizeof(rec), 1, fp);	// 파일의 rec 크기 1개만큼 읽고 rec 객체에 저장
    strcpy(rec.dept, "Movie");		// rec.dept를  Movie로 변경
    fseek(fp, sizeof(rec)*2L, SEEK_SET);	// 다시 옮김
    fwrite(&rec, sizeof(rec), 1, fp);	// 바뀐 rec으로 저장

    fseek(fp, sizeof(rec)*5L, SEEK_SET);	// rec 5개 크기로 파일의 iterator를 옮김
    fread(&rec, sizeof(rec), 1, fp);	// 파일의 rec 크기 1개만큼 읽고 rec 객체에 저장
    strcpy(rec.dept, "Baseball");		// rec.dept를 Baseball로 변경
    fseek(fp, sizeof(rec)*5L, SEEK_SET);	// 다시 옮김
    fwrite(&rec, sizeof(rec), 1, fp);	// 바뀐 rec으로 저장

    rewind(fp);				// 파일 처음 위치로 iterator를 옮김
    while (fread(&rec, sizeof(rec), 1, fp))  {
        print_record(&rec);		// 파일끝까지 읽으면서 출력
    }

    fclose(fp);
}
