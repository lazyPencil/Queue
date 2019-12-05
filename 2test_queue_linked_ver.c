#include <stdio.h>
#include "queue_linked.h"

int main(void) {
	head* pQ = NULL;
	int i;
	char* example[5] = { "Jack", "Tom", "Sara", "Tommy", "Tomson" };
	pQ = createQ();
	if (pQ == NULL) return -1;
	printf("createQ()성공, 5명의 사람이 들어왔다가 나갑니다.\n");
	printf("처음상태)\npQ->front addr=%p pQ->rear addr=%p\n", pQ->front, pQ->rear);
	if (queuefront(pQ) == NULL)
		printf("queuefront(pQ)가 비었네요..\n");
	else
		printf("queuefront(pQ)=%s\n", queuefront(pQ));
	for (i = 0; i < 5; i++) {
		printf("%-10s이 들어옵니다.\t", example[i%5]);
		enqueue(pQ, example[i%5]);
		if (queuefront(pQ) == NULL) printf("queuefront(pQ)가 비었네요..\t");
		else printf("queuefront(pQ)=%s\t", queuefront(pQ));
		if (queuerear(pQ) == NULL)	printf("queuerear(pQ)가 비었네요..\n");
		else printf("queuerear(pQ)=%s\n", queuerear(pQ));
	}
	/*i = 0;		// 무한루프로 돌려보았는데 3만명도 들어올 수 있어서 무서워서 껐음
	while(isfullqueue(pQ)!=true) {
		printf("%-10s이 들어옵니다.\t", example[i % 5]);
		enqueue(pQ, example[i % 5]);
		i++;
		printf("사람 수 : %d\n", i);
	}*/
	printf("isfullqueue(pQ) = %d\n", isfullqueue(pQ)); // linked list 형이므로 힙 메모리가 바닥날 때까지 사용가능
	for (i = 0; i < 4; i++) {
		printf("%-10s이 나갑니다.\t", dequeue(pQ));
		if (queuefront(pQ) == NULL)	printf("queuefront(pQ)가 비었네요..\t");
		else	printf("queuefront(pQ)=%s\t", queuefront(pQ));
		if (queuerear(pQ) == NULL)	printf("queuerear(pQ)가 비었네요..\n");
		else	printf("queuerear(pQ)=%s\n", queuerear(pQ));
	}
	printf("%-10s이 나갑니다.\t", dequeue(pQ));
	if (queuefront(pQ) == NULL)	printf("queuefront(pQ)가 비었네요..\t");
	else printf("queuefront(pQ)=%s\t", queuefront(pQ));
	if (queuerear(pQ) == NULL)	printf("queuerear(pQ)가 비었네요..\n");
	else	printf("queuerear(pQ)=%s\n", queuerear(pQ));
	printf("\n%-10s이 들어옵니다.\n", example[0]);
	enqueue(pQ, example[0]);
	printf("클리어이전)isemptyqueue(pQ) = %d\n", isemptyqueue(pQ));
	clearqueue(pQ);
	printf("클리어이후)isemptyqueue(pQ) = %d\n", isemptyqueue(pQ));
	
	destroyqueue(&pQ);
	printf("destroy result) pQ addr = %p \t pQ value = %p\n", &pQ, pQ);
	//printf("%d\n", pQ->count);  pQ의 메모리를 해제했으므로 에러뜬다.
	return 0;
}