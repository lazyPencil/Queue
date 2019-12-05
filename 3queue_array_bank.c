#include "queue_array_bank.h"

queue* createQ(int size) {
	int i,j;
	queue* pQ = (queue*)malloc(sizeof(queue));
	if (pQ == NULL) return NULL;
	pQ->person = (char**)malloc(sizeof(char*) * size);
	if (pQ->person == NULL) {
		free(pQ);
		return NULL;
	}
	char test[10][100] = { "aaaa","bbbb","c","d","e","f","z","Q","PPP","KING" };
	for (i = 0; i < size; i++) {
		(pQ->person)[i] = (char*)calloc(NAME + 1 + INDEX, sizeof(char));
		if (pQ->person[i] == NULL) {
			for (j = i - 1; j >= 0; j--)
				free(pQ->person[j]);
			free(pQ->person);
			free(pQ);
			return NULL;
		}
	}
	pQ->front = pQ->rear = 0;
	pQ->size = size;
	pQ->cnt = 0;
	return pQ;
}

int enqueue(queue* pQ, char* name) {
	char* x = NULL;
	int y, idx = 0;
	if (isfullqueue(pQ)) { // case y=1
		printf("queue is full...\n");
		return -11;
	}
	else
	{
		pQ->rear = (pQ->rear + 1) % pQ->size;
		pQ->person[pQ->rear] = name;
		printf("pQ->person[%d]=%s\n", pQ->rear, pQ->person[pQ->rear]);
		pQ->cnt++;
		return 1;
	}
}
char* dequeue(queue * pQ) {
	char* x =NULL;
	if (isemptyqueue(pQ)) {
		printf("queue is empty...\n");
		return NULL;
	}
	else {
		pQ->front = (pQ->front + 1) % pQ->size;
		x = pQ->person[pQ->front];
		pQ->person[pQ->front] = NULL;
		pQ->cnt--;
		return x;
	}
}
char* queuefront(queue * pQ) {
	if (isemptyqueue(pQ))
		return NULL;
	else
		return pQ->person[(pQ->front+1)%pQ->size];
}
char* queuerear(queue * pQ) {
	if (isemptyqueue(pQ))
		return NULL;
	else
		return pQ->person[pQ->rear];
}
bool isfullqueue(queue * pQ) {
	if ((pQ->front - pQ->rear == 1) || ((pQ->rear - pQ->front)==pQ->size-1))
		return true;
	else
		return false;
}
bool isemptyqueue(queue * pQ) {
	if (pQ->front == pQ->rear)
		return true;
	else
		return false;
}
void clearqueue(queue * pQ) {
	pQ->rear = pQ->front;
}
void destroyqueue(queue **ppQ) {
	int i;
	for (i = 0; i < (*ppQ)->size; i++) {
		free((*ppQ)->person[i]);
	}
	free((*ppQ)->person);
	free(*ppQ);
	*ppQ = NULL;
}