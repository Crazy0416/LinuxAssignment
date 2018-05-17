#include <stdio.h>

int strlen_p(char *str)
{
	int	len = 0;

	while (*str++)  {	// '\0'값을 만날때까지 
		len++;		// len 값을 추가함
	}
	return len;
}

int strlen_a(char str[])
{
	int i;

	for (i = 0 ; str[i] != '\0' ; i++)	// '\0'값을 만날때까지 i를 증가시킴
		;
	return i;
}

void strcpy_p(char *dst, char *src)
{
	while (*src)  {
		*dst++ = *src++;	// src의 문자열 끝까지 한글자씩 dst에 추가
	}
	*dst = *src;			// 마지막 '\0'를 while문에서 추가 못했으므로 추가
}

void strcpy_a(char dst[], char src[])
{
	int i;

	for (i = 0 ; src[i] != '\0' ; i++)	// src의 문자열 끝까지
		dst[i] = src[i];		// 한글자씩 dst에 추가
	dst[i] = src[i];			// 마지막 '\0'를 for문에서 추가 못했으므로 추가
}

void strcat_p(char *dst, char *src)
{
	while (*dst++)				// dst 뒤에 src를 추가해야하므로 포인터를 문자열 마지막까지 옮김
		;
	dst--;					// '\0'를 포함하면 안되므로 한칸 뒤로 이동
	while (*src)  {
		*dst++ = *src++;		// dst에 src를 한글자씩 추가
	}
	*dst = *src;				// 마지막에 '\0'를 문자열에 추가
}

void strcat_a(char dst[], char src[])
{
	int i, j;

	for (i = 0 ; dst[i] != '\0' ; i++)	// dst 뒤에 src를 추가해야하므로 포인터를 문자열 마지막까지 옮김
		;
	for (j = 0 ; src[j] != '\0' ; j++)	// dst에 src를 한글자씩 추가
		dst[i+j] = src[j];
	dst[i+j] = src[j];			// 마지막에 '\0'를 문자열에 추가
}

int strcmp_p(char *dst, char *src){
	while(*dst != '\0' && *src != '\0'){	// 둘 중에 먼저 끝나는 문자열이 있으면 반복문 종료
		if(*dst != *src)		// 같은 위치에 있는 문자가 다를 경우 반복문 종료
			break;
		dst++; src++;
	}
	return (*dst - *src);			// 반복문 종료 후 그 위치의 문자 아스키 코드 값을 뺀 값을 리턴
}

int strcmp_a(char dst[], char src[]){
	int i, j;
	for(i = 0, j = 0; dst[i] != '\0' && src[j] != '\0'; i++, j++){	// 둘 중에 먼저 끝나는 문자열이 있으면 반복문 종료
		if(dst[i] != src[j])					// 같은 위치에 있는 문자가 다를 경우 반복문 종료
			break;
	}
	return (dst[i] - src[j]);					// 반복문 종료 후 그 위치의 문자 아스키 코드 값으 뺀 값을 리턴
}

main()
{
	int		len1, len2;
	char	str1[20], str2[20];

	len1 = strlen_p("Hello");
	len2 = strlen_a("Hello");
	printf("strlen: p=%d, a=%d\n", len1, len2);

	strcpy_p(str1, "Hello");
	strcpy_a(str2, "Hello");
	printf("strcpy: p=%s, a=%s\n", str1, str2);

	strcat_p(str1, ", World!");
	strcat_a(str2, ", World!");
	printf("strcat: p=%s, a=%s\n\n", str1, str2);

	printf("abcd abcd return a=%d\n", strcmp_a("abcd", "abcd"));
	printf("abcd abc : return a=%d\n", strcmp_a("abcd", "abc"));
	printf("abcd abcdef : return a=%d\n", strcmp_a("abcd", "abcdef"));
	printf("abcd adef : return a=%d\n\n", strcmp_a("abcd", "adef"));

	printf("abcd abcd return p=%d\n", strcmp_p("abcd", "abcd"));
        printf("abcd abc : return p=%d\n", strcmp_p("abcd", "abc"));
        printf("abcd abcdef : return p=%d\n", strcmp_p("abcd", "abcdef"));
        printf("abcd adef : return p=%d\n", strcmp_p("abcd", "adef"));
}
