#include "queue_linked_bank.h"

head* createQ(void) {
	head* ptr = (head*)malloc(sizeof(head));
	if (ptr == NULL) return NULL;
	ptr->count = 0;							// �ʱⰪ ����
	ptr->front = NULL;
	ptr->rear = NULL;
	return ptr;
}
char* enqueue(head * pQ, char* element) { // element�� �����Ҵ����� �� �� (���� ���ؼ�)�̹Ƿ� ���߿� ���������־�� ��!!
	queue* ptr = NULL;
	queue* pTemp = NULL;						//pQ->front �� ���� �ּ� ������ ����
	if (isfullqueue(pQ)) {
		printf("enqueue�� �ʿ��� �޸𸮰� ���̻� �������� �ʽ��ϴ�\n");
		return NULL;
	}
	else {
		ptr = (queue*)malloc(sizeof(queue));
		if (ptr == NULL) return NULL;
		ptr->link = NULL;
		//strcpy(ptr->data, element);			//ptr->data �� �������̹Ƿ�.
		ptr->data = element;
		pQ->rear = ptr;							// ���� ����. ���� ���縦 �� ���� ����
		if (isemptyqueue(pQ)) pQ->front = ptr;	// ù ����Ʈ�� ���� ���� NULL�� front�� �ٲ����
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
		if (pQ->count == 1) pQ->rear = NULL;	// ������ ����Ʈ�� ���� ���� not NULL�� rear�� �ٲ����
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
	//if (pQ->front == pQ->rear) / ù �����Ͱ� ������ �� count = 1���� front = rear
	if(pQ->count == 0)
		return true;
	else
		return false;
}
void clearqueue(head * pQ) {		// enqueue���� �Ҵ���� �޸� ����(queue ����ü)�� ������ ã�ư��鼭 ����
	queue* temp = NULL;
	while (pQ->count != 0) {
		temp = pQ->front;
		free(temp->data);
		pQ->front = (pQ->front)->link;
		if (pQ->count == 1) pQ->rear = NULL; // �������� front�� �˾Ƽ� NULL�� ����Ű�µ� rear�� ���� ����Ű�� ����� ��
		free(temp);
		pQ->count--;
	}
}
void destroyqueue(head * *ppQ) {	// ppQ : pQ�� �ּ� , *ppQ : pQ�� ����Ű�� ����ü�� �ּ� , **ppQ : ����ü ����ü (ex: **ppQ.data)
	clearqueue(*ppQ);
	free(*ppQ);					// ó���� pQ�� �Ҵ���� �޸� ����(head ����ü)�� ���� 
	*ppQ = NULL;				// pQ�� ���� NULL�� ����Ų��.
}