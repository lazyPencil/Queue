#include "queue_array.h"

queue* createQ(int size) {
	queue* pQ = (queue*)malloc(sizeof(queue));
	if (pQ == NULL) return NULL;
	pQ->arr = (int*)malloc(sizeof(int) * size);
	if (pQ->arr == NULL) {
		free(pQ);
		return NULL;
	}
	pQ->front = pQ->rear = 0;
	pQ->size = size;
	return pQ;
}
void enqueue(queue* pQ, int item) {
	if (isfullqueue(pQ)) {
		printf("queue is full...\n");
		return;
	}
	else
	{
		pQ->rear = (pQ->rear + 1) % pQ->size;
		pQ->arr[pQ->rear] = item;
	}
}
int dequeue(queue* pQ) {
	int x;
	if (isemptyqueue(pQ)) {
		printf("queue is empty...\n");
		return -11111111;
	}
	else {
		pQ->front = (pQ->front + 1) % pQ->size;
		x = pQ->arr[pQ->front];
		return x;
	}
}
int queuefront(queue* pQ) {
	if (isemptyqueue(pQ))
		return -11111111;
	else
		return pQ->arr[pQ->front];
}
int queuerear(queue* pQ) {
	if (isemptyqueue(pQ))
		return -11111111;
	else
		return pQ->arr[pQ->rear];
}
bool isfullqueue(queue* pQ) {
	if ((pQ->front - pQ->rear == 1) || (pQ->rear - pQ->front == pQ->size - 1)) // r,f ¼øÀÏ ¶© ÀüÀÚ / f,r ¼øÀÏ ¶© ÈÄÀÚ
		return true;
	else
		return false;
}
bool isemptyqueue(queue* pQ) {
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}
void clearqueue(queue* pQ) {
	pQ->rear = pQ->front;
}
void destroyqueue(queue** pQ) {
	free((*pQ)->arr);
	free(*pQ);
	*pQ = NULL;
}