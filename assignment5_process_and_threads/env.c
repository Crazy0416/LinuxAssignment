#include <stdio.h>

main(int argc, char *argv[], char *envp[])
{
	int			i;
	char		**p;
	extern char	**environ;

	printf("List command-line arguments\n");
	for (i = 0 ; i < argc ; i++)  {		// argument 출력
		printf("%s\n", argv[i]);
	}

	printf("\n");
	printf("List environment variables from environ variable\n");
#if 1
	for (i = 0 ; environ[i] != NULL ; i++)  {
		printf("%s\n", environ[i]);		// 외부변수(환경 변수) 출력
	}
#else
	for (p = environ ; *p != NULL ; p++)  {
		printf("%s\n", *p);
	}
#endif

	printf("\n");
	printf("List environment variables from envp variable\n");
#if 1
	for (i = 0 ; envp[i] != NULL ; i++)  {
		printf("%s\n", envp[i]);		// argument로 넘겨받은 환경 변수 출력
	}
#else
	for (p = envp ; *p != NULL ; p++)  {
		printf("%s\n", *p);
	}
#endif
}
