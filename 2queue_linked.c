#include "queue_linked.h"

head* createQ(void) {
	head* ptr = (head*)malloc(sizeof(head));
	if (ptr == NULL) return NULL;
	ptr->count = 0;							// �ʱⰪ ����
	ptr->front = NULL;
	ptr->rear = NULL;
	return ptr;
}
void enqueue(head* pQ, char* element) {
	queue* ptr = NULL;
	queue* temp = NULL; 
	if (isfullqueue(pQ)) {
		printf("enqueue�� �ʿ��� �޸𸮰� ���̻� �������� �ʽ��ϴ�\n");
		return;
	}
	else {
		ptr = (queue*)malloc(sizeof(queue));
		if (ptr == NULL) return;
		ptr->link = NULL;
		//strcpy(ptr->data, element); ptr->data �� �迭�� �ƴϴ�.
		ptr->data = element;
		pQ->rear = ptr;
		if (isemptyqueue(pQ)) pQ->front = ptr;	// ù ����Ʈ�� ���� ���� NULL�� front�� �ٲ����
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
		if (pQ->count == 1) pQ->rear = NULL;	// ������ ����Ʈ�� ���� ���� not NULL�� rear�� �ٲ����
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
void clearqueue(head* pQ){		// enqueue���� �Ҵ���� �޸� ����(queue ����ü)�� ������ ã�ư��鼭 ����
	queue* temp = NULL;
	while (pQ->count != 0) {
		temp = pQ->front;
		pQ->front = pQ->front->link;
		if (pQ->count == 1) pQ->rear = NULL;
		free(temp);
		pQ->count--;
	}
}
void destroyqueue(head** ppQ){	// ppQ : pQ�� �ּ� , *ppQ : pQ�� ����Ű�� ����ü�� �ּ� , **ppQ : ����ü ����ü (ex: **ppQ.data)
	clearqueue(*ppQ);
	free(*ppQ);					// ó���� pQ�� �Ҵ���� �޸� ����(head ����ü)�� ���� 
	*ppQ = NULL;				// pQ�� ���� NULL�� ����Ų��.
}