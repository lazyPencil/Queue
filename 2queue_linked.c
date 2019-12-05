#include "queue_linked.h"

head* createQ(void) {
	head* ptr = (head*)malloc(sizeof(head));
	if (ptr == NULL) return NULL;
	ptr->count = 0;							// 초기값 설정
	ptr->front = NULL;
	ptr->rear = NULL;
	return ptr;
}
void enqueue(head* pQ, char* element) {
	queue* ptr = NULL;
	queue* temp = NULL; 
	if (isfullqueue(pQ)) {
		printf("enqueue에 필요한 메모리가 더이상 남아있지 않습니다\n");
		return;
	}
	else {
		ptr = (queue*)malloc(sizeof(queue));
		if (ptr == NULL) return;
		ptr->link = NULL;
		//strcpy(ptr->data, element); ptr->data 는 배열이 아니다.
		ptr->data = element;
		pQ->rear = ptr;
		if (isemptyqueue(pQ)) pQ->front = ptr;	// 첫 리스트를 만들 때는 NULL인 front를 바꿔줘야
		else {
			temp = pQ->front;
			while (temp->link != NULL)
				temp = temp->link;
			temp->link = ptr;
		}
		pQ->count++;
	}
}
char* dequeue(head* pQ) {
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
char* queuefront(head* pQ) {
	if (isemptyqueue(pQ))
		return NULL;
	else
		return pQ->front->data;
}
char* queuerear(head* pQ) {
	if (isemptyqueue(pQ))
		return NULL;
	else
		return pQ->rear->data;
}
bool isfullqueue(head* pQ) {
	queue* ptr = (queue*)malloc(sizeof(queue));
	if (ptr == NULL)
		return true;
	else
		return false;
}
bool isemptyqueue(head* pQ){
	if (pQ->count == 0)
		return true;
	else
		return false;
}
void clearqueue(head* pQ){		// enqueue마다 할당받은 메모리 영역(queue 구조체)을 끝까지 찾아가면서 해제
	queue* temp = NULL;
	while (pQ->count != 0) {
		temp = pQ->front;
		pQ->front = pQ->front->link;
		if (pQ->count == 1) pQ->rear = NULL;
		free(temp);
		pQ->count--;
	}
}
void destroyqueue(head** ppQ){	// ppQ : pQ의 주소 , *ppQ : pQ가 가리키는 구조체의 주소 , **ppQ : 구조체 그자체 (ex: **ppQ.data)
	clearqueue(*ppQ);
	free(*ppQ);					// 처음에 pQ에 할당받은 메모리 영역(head 구조체)을 해제 
	*ppQ = NULL;				// pQ는 이제 NULL을 가리킨다.
}