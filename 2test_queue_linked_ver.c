#include <stdio.h>
#include "queue_linked.h"

int main(void) {
	head* pQ = NULL;
	int i;
	char* example[5] = { "Jack", "Tom", "Sara", "Tommy", "Tomson" };
	pQ = createQ();
	if (pQ == NULL) return -1;
	printf("createQ()����, 5���� ����� ���Դٰ� �����ϴ�.\n");
	printf("ó������)\npQ->front addr=%p pQ->rear addr=%p\n", pQ->front, pQ->rear);
	if (queuefront(pQ) == NULL)
		printf("queuefront(pQ)�� ����׿�..\n");
	else
		printf("queuefront(pQ)=%s\n", queuefront(pQ));
	for (i = 0; i < 5; i++) {
		printf("%-10s�� ���ɴϴ�.\t", example[i%5]);
		enqueue(pQ, example[i%5]);
		if (queuefront(pQ) == NULL) printf("queuefront(pQ)�� ����׿�..\t");
		else printf("queuefront(pQ)=%s\t", queuefront(pQ));
		if (queuerear(pQ) == NULL)	printf("queuerear(pQ)�� ����׿�..\n");
		else printf("queuerear(pQ)=%s\n", queuerear(pQ));
	}
	/*i = 0;		// ���ѷ����� �������Ҵµ� 3���� ���� �� �־ �������� ����
	while(isfullqueue(pQ)!=true) {
		printf("%-10s�� ���ɴϴ�.\t", example[i % 5]);
		enqueue(pQ, example[i % 5]);
		i++;
		printf("��� �� : %d\n", i);
	}*/
	printf("isfullqueue(pQ) = %d\n", isfullqueue(pQ)); // linked list ���̹Ƿ� �� �޸𸮰� �ٴڳ� ������ ��밡��
	for (i = 0; i < 4; i++) {
		printf("%-10s�� �����ϴ�.\t", dequeue(pQ));
		if (queuefront(pQ) == NULL)	printf("queuefront(pQ)�� ����׿�..\t");
		else	printf("queuefront(pQ)=%s\t", queuefront(pQ));
		if (queuerear(pQ) == NULL)	printf("queuerear(pQ)�� ����׿�..\n");
		else	printf("queuerear(pQ)=%s\n", queuerear(pQ));
	}
	printf("%-10s�� �����ϴ�.\t", dequeue(pQ));
	if (queuefront(pQ) == NULL)	printf("queuefront(pQ)�� ����׿�..\t");
	else printf("queuefront(pQ)=%s\t", queuefront(pQ));
	if (queuerear(pQ) == NULL)	printf("queuerear(pQ)�� ����׿�..\n");
	else	printf("queuerear(pQ)=%s\n", queuerear(pQ));
	printf("\n%-10s�� ���ɴϴ�.\n", example[0]);
	enqueue(pQ, example[0]);
	printf("Ŭ��������)isemptyqueue(pQ) = %d\n", isemptyqueue(pQ));
	clearqueue(pQ);
	printf("Ŭ��������)isemptyqueue(pQ) = %d\n", isemptyqueue(pQ));
	
	destroyqueue(&pQ);
	printf("destroy result) pQ addr = %p \t pQ value = %p\n", &pQ, pQ);
	//printf("%d\n", pQ->count);  pQ�� �޸𸮸� ���������Ƿ� �������.
	return 0;
}