#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX		256

int main(){
	char cmd[STR_MAX];
	char *sArr[10] = {NULL, };
	char* ptr;
	int i = 0;
	
	gets(cmd);
	printf("%s", cmd);
	ptr = strtok(cmd, " ");
	while(ptr != NULL){
		sArr[i] = ptr;
		printf("%s\n", sArr[i]);
		i++;
		ptr = strtok(NULL, " ");
		//printf("%s\n", sArr[i]);
	}
	return 0;
}
