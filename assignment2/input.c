#include <stdio.h>

main()
{
	char c, s[80];
	int i; long l;
	float f; double d;
	
	scanf("%c %s %d %ld %f %lf", &c, s, &i, &l, &f, &d);			// 키보드에서 입력받을 데이터 포맷을 정하는 포맷 지정자 
	printf("Output: %c %s %d %ld %.4f %.2lf\n", c, s, i, l, f, d); 		// 포맷을 지정한대로 모니터에 출력
	c = getchar();			// 표준 입력으로부터 아무 값이나 한개 읽어옴
	putchar(c);			// 표준 출력에 문자를 쓴다.

	gets(s);			// 표준 입력으로부터 문자열을 가져옴
	puts(s);			// 표준 출력에 문자열을 쓴다.
}

