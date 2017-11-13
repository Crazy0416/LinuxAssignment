#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	FILE *src;
	char charData;

	if (argc != 2){						// 아규먼트 오류처리
		fprintf(stderr, "Usage: %s one source\n", argv[0]);
		return -1;
	}
	if( (src = fopen(argv[1], "rb")) == NULL ) {		// 바이너리형식으로 읽음
		perror("fopen");
		return -1;
	}

	while((charData = fgetc(src)) != EOF)	{		// 파일 끝까지 char 한개씩 받음
		if(charData > 96 && charData < 123){		// charData 가 소문자라면 
			charData -= 32;				// 대문자로 변환
		}
		printf("%c", charData);				// 출력			
	}
	fclose(src);
	return 0;
}

// ./upper <파일 path>를 입력하면 파일 내용을 모두 대문자로 읽어서 콘솔창에 띄우게 된다.
