#include <stdio.h>
#include <pthread.h>

struct AB{		// SumAtoB에 들어갈 데이터 struct
	int a;
	int b;
	int result;
};

int SumAtoB(void* AB){
	int 	i;
	struct AB *data = AB;		// void 형 데이터 struct AB 형으로 형변환
	data->result = 0;

	for(i = data->a; i < data->b; i++){	// a부터 b까지 합 구함
		data->result += i;
	}
	pthread_exit(NULL);		// 스레드 종료
}

main(){
	pthread_t tid1, tid2;
	struct AB a_struct, b_struct;
	a_struct.a = 0;
	a_struct.b = 51;
	b_struct.a = 51;
	b_struct.b = 101;
	
	if(pthread_create(&tid1, NULL, SumAtoB, &a_struct) < 0){	// 스레드1 생성
		perror("pthread_create");
		exit(1);
	}
	if(pthread_create(&tid2, NULL, SumAtoB, &b_struct) < 0){	// 스레드2 생성
		perror("pthread_create");
		exit(1);
	}
	if(pthread_join(tid1, NULL) < 0){			// 스레드1 종료 기다림
		perror("pthread_join");
		exit(1);
	}
	if(pthread_join(tid2, NULL) < 0){			// 스레드2 종료 기다림
		perror("pthread_join");
		exit(1);
	}

	printf("Sum of 1~100 : %d\n", a_struct.result + b_struct.result);	// 총합 출력
}
