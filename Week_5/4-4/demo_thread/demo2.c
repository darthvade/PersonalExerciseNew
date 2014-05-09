#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *ThreadFunc(void *pArg) {
	int iArg = (int)pArg;
	sleep(1);
	if(iArg < 3) {
		return (void *)(iArg*2);
	} else {
		pthread_exit((void *)(iArg*2));
	}
}

int main() {
	pthread_t th_id;
	int iRet = 0;
	pthread_create(&th_id, NULL, ThreadFunc, (void *)2);
	pthread_join(th_id, (void **)&iRet);
	printf("The first child thread ret is: %d\n", iRet);
	pthread_create(&th_id, NULL, ThreadFunc, (void *)4);
	pthread_join(th_id, (void **)&iRet);
	printf("The second child thread ret is: %d\n", iRet);
	return 0;
}
