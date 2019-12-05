#include <stdio.h>
#include "queue_array.h"
#define SIZE 5

int main(void) {
	queue* pQ = NULL;
	int i;
	pQ = createQ(SIZE);
	printf("������� ť�� ������� %d �̰�, �� �� �ִ� ��� ���� %d\n", SIZE, SIZE - 1);
	printf("ó�� \nfront:%d \t rear:%d\n", pQ->front, pQ->rear);
	for (i = 0; i < SIZE-1; i++) {		// SIZE-1 ���� : �� ĭ�� ����־����
		enqueue(pQ, i + 3);
		printf("%d�� ���ϴ�.\n", i + 3);
		printf("front:%d \t rear:%d\n", pQ->front, pQ->rear);
	}
	printf("�� �� �� �� ���� ������ �ϸ� -> isfullqueue? %d (T/F)\n", isfullqueue(pQ));
	enqueue(pQ, 5000);
	for (i = 0; i < SIZE-1; i++) {
		printf("%d�� �����ϴ�.\n", dequeue(pQ));
		printf("front:%d \t rear:%d\n", pQ->front, pQ->rear);
	}
	printf("�� �� �� �� ���� �������� �ϸ� -> isemptyqueue? %d (T/F)\n", isemptyqueue(pQ));
	dequeue(pQ);
	enqueue(pQ, 12345);
	printf("%d�� ���ϴ�.\n", 12345);
	enqueue(pQ, 77777);
	printf("%d�� ���ϴ�.\n", 77777);
	printf("clearqueue�ϱ� ���� front:%d \t rear:%d\n", pQ->front, pQ->rear);
	printf("clearqueue�ϱ� ���� dequeue(pQ) = %d\n", dequeue(pQ));
	printf("dequeue�ϰ� ���� front:%d \t rear:%d\n", pQ->front, pQ->rear);
	clearqueue(pQ);
	printf("clearqueue�ϰ� ���� front:%d \t rear:%d\n", pQ->front, pQ->rear);
	printf("clearqueue�ϰ� ���� dequeue(pQ) = %d\n", dequeue(pQ));
	printf("destroyqueue�ϱ� ���� pQ �� (��, ť�� �ּ�) = %p\n", pQ);
	destroyqueue(&pQ);
	printf("destroyqueue�ϱ� ���� pQ �� (��, ť�� �ּ�) = %p\n", pQ);
	return 0;
}