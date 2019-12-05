#include <stdio.h>
#include "queue_array.h"
#define SIZE 5

int main(void) {
	queue* pQ = NULL;
	int i;
	pQ = createQ(SIZE);
	printf("만들어질 큐의 사이즈는 %d 이고, 들어갈 수 있는 사람 수는 %d\n", SIZE, SIZE - 1);
	printf("처음 \nfront:%d \t rear:%d\n", pQ->front, pQ->rear);
	for (i = 0; i < SIZE-1; i++) {		// SIZE-1 이유 : 한 칸은 비어있어야함
		enqueue(pQ, i + 3);
		printf("%d가 들어갑니다.\n", i + 3);
		printf("front:%d \t rear:%d\n", pQ->front, pQ->rear);
	}
	printf("이 때 또 한 명이 들어가려고 하면 -> isfullqueue? %d (T/F)\n", isfullqueue(pQ));
	enqueue(pQ, 5000);
	for (i = 0; i < SIZE-1; i++) {
		printf("%d가 나갑니다.\n", dequeue(pQ));
		printf("front:%d \t rear:%d\n", pQ->front, pQ->rear);
	}
	printf("이 때 또 한 명이 나가려고 하면 -> isemptyqueue? %d (T/F)\n", isemptyqueue(pQ));
	dequeue(pQ);
	enqueue(pQ, 12345);
	printf("%d가 들어갑니다.\n", 12345);
	enqueue(pQ, 77777);
	printf("%d가 들어갑니다.\n", 77777);
	printf("clearqueue하기 전에 front:%d \t rear:%d\n", pQ->front, pQ->rear);
	printf("clearqueue하기 전에 dequeue(pQ) = %d\n", dequeue(pQ));
	printf("dequeue하고 나서 front:%d \t rear:%d\n", pQ->front, pQ->rear);
	clearqueue(pQ);
	printf("clearqueue하고 나서 front:%d \t rear:%d\n", pQ->front, pQ->rear);
	printf("clearqueue하고 나서 dequeue(pQ) = %d\n", dequeue(pQ));
	printf("destroyqueue하기 전에 pQ 값 (즉, 큐의 주소) = %p\n", pQ);
	destroyqueue(&pQ);
	printf("destroyqueue하기 전에 pQ 값 (즉, 큐의 주소) = %p\n", pQ);
	return 0;
}