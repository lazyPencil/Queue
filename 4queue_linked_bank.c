#include "queue_linked_bank.h"

head* createQ(void) {
	head* ptr = (head*)malloc(sizeof(head));
	if (ptr == NULL) return NULL;
	ptr->count = 0;							// 초기값 설정
	ptr->front = NULL;
	ptr->rear = NULL;
	return ptr;
}
char* enqueue(head * pQ, char* element) { // element도 동적할당으로 온 값 (내가 원해서)이므로 나중에 해제시켜주어야 함!!
	queue* ptr = NULL;
	queue* pTemp = NULL;						//pQ->front 의 원래 주소 보존을 위해
	if (isfullqueue(pQ)) {
		printf("enqueue에 필요한 메모리가 더이상 남아있지 않습니다\n");
		return NULL;
	}
	else {
		ptr = (queue*)malloc(sizeof(queue));
		if (ptr == NULL) return NULL;
		ptr->link = NULL;
		//strcpy(ptr->data, element);			//ptr->data 는 포인터이므로.
		ptr->data = element;
		pQ->rear = ptr;							// 얕은 복사. 깊은 복사를 할 이유 없음
		if (isemptyqueue(pQ)) pQ->front = ptr;	// 첫 리스트를 만들 때는 NULL인 front를 바꿔줘야
		else {
			pTemp = pQ->front;
			while (pTemp->link != NULL)
				pTemp = pTemp->link;
			pTemp->link = ptr;
		}
		//printf("pQ->front->data=%s \t pQ->rear->data=%s\n", pQ->front->data, pQ->rear->data);
		pQ->count++;
		return ptr->data;
	}
}
char* dequeue(head * pQ) {
	char* x = NULL;
	queue* temp = NULL;
	if (isemptyqueue(pQ)) return NULL;
	else {
		temp = pQ->front;
		x = pQ->front->data;
		pQ->front = pQ->front->link;
		if (pQ->count == 1) pQ->rear = NULL;	// 마지막 리스트를 지울 때는 not NULL인 rear를 바꿔줘야
		free(temp);
		pQ->count--;
		return x;
	}
}
char* queuefront(head * pQ) {
	if (isemptyqueue(pQ))
		return NULL;
	else
		return pQ->front->data;
}
char* queuerear(head * pQ) {
	if (isemptyqueue(pQ))
		return NULL;
	else
		return pQ->rear->data;
}
bool isfullqueue(head * pQ) {
	queue* ptr = (queue*)malloc(sizeof(queue));
	if (ptr == NULL)
		return true;
	else
		return false;
}
bool isemptyqueue(head * pQ) {
	//if (pQ->front == pQ->rear) / 첫 데이터가 들어왔을 때 count = 1지만 front = rear
	if(pQ->count == 0)
		return true;
	else
		return false;
}
void clearqueue(head * pQ) {		// enqueue마다 할당받은 메모리 영역(queue 구조체)을 끝까지 찾아가면서 해제
	queue* temp = NULL;
	while (pQ->count != 0) {
		temp = pQ->front;
		free(temp->data);
		pQ->front = (pQ->front)->link;
		if (pQ->count == 1) pQ->rear = NULL; // 마지막에 front는 알아서 NULL을 가리키는데 rear는 직접 가리키게 해줘야 함
		free(temp);
		pQ->count--;
	}
}
void destroyqueue(head * *ppQ) {	// ppQ : pQ의 주소 , *ppQ : pQ가 가리키는 구조체의 주소 , **ppQ : 구조체 그자체 (ex: **ppQ.data)
	clearqueue(*ppQ);
	free(*ppQ);					// 처음에 pQ에 할당받은 메모리 영역(head 구조체)을 해제 
	*ppQ = NULL;				// pQ는 이제 NULL을 가리킨다.
}