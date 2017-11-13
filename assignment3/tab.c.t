#include <stdio.h>

enum { FALSE, TRUE };

void
conv(char *fname)
{
    FILE	*src, *dst;
    char	fdest[40];
    int	ch, first;

    if ((src = fopen(fname, "rt")) == NULL)  {	// fname 파일을 읽기 형식으로 open 한 뒤 FILE 포인터를 src에 저장
        perror("fopen");
        return;
    }

    strcpy(fdest, fname);		// fdest에 fname 복사
    strcat(fdest, ".t");		// fdest에 ".t" 추가
    if ((dst = fopen(fdest, "wt")) == NULL)  {	//fdest+".t" 파일을 쓰기 형식으로 연 뒤 FILE  포인터를 dst에 저장
        perror("fopen");
        return;
    }

    first = TRUE;
    while ((ch = fgetc(src)) != EOF)  {	// src 파일 끝까지 char형 문자 하나씩 가져옴
        if (first && ch == '\t')  {	// ch문자열이 탭이고 줄의 첫 번째 글자라면
            fputc(' ', dst);
            fputc(' ', dst);
            fputc(' ', dst);
            fputc(' ', dst);	// 공백 4개 추가
        }
        else  {				// 그 외라면
            fputc(ch, dst);		// 그냥 dst에 그대로 추가
            if (first)		// 만약 줄의 첫번째라면 first = false;
                first = FALSE;
            if (ch == '\n')		// 만약 줄이 넘어가게 된다면 first = true
                first = TRUE;
        }
    }

    fclose(src);
    fclose(dst);
}

main(int argc, char *argv[])
{
    while (--argc)  {
        conv(argv[argc]);
    }
}
