#include <stdio.h>

main(){
	char c = 'a', s[] = "hello";
	int i = 100; long l = 99999;
	float f = 3.14; double d = 99.999;
	int *p = &i;

	printf("Output : %c %s %d %#X %ld %.4f %.2lf %p\n", c, s, i, i, l, f, d, p);	// 형식지정자에 따라 데이터를 출력
	putchar(c);		// 표준 출력에 문자 하나 쓴다.
	puts(s);		// 표준 출력에 문자열을 쓴다.
}
