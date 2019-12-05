#include <stdio.h>
#include <string.h>
#define NAME 30
#define SEQ 2
#define MAXQUEUE 99
#include "queue_linked_bank.h"

void queueprint(head* pQ);
char* In(head* pQ);
char* Out(head* pQ);

int main(void) {
	int menu, error;
	char* errorchar = NULL;
	head* pQ = NULL;

	pQ = createQ();
	if (pQ == NULL) return -1;

	printf("* * *************** * *\n");
	printf("* * ���� ���� �ý��� * *\n");
	printf("* * *************** * *\n");
	do {
		printf("In (0), out(1), exit (2) : ");
		error = scanf("%d", &menu);
		getchar();
		puts("");
		if (error != 1) {
			printf("0, 1, 2 �߿� ��� �ּ���.\n");
			menu = 3;
		}
		if (menu == 0) {
			errorchar = In(pQ);
			if (errorchar == NULL)
				printf("�ݹ� In(pQ) �� ���� ��ȯ���� ���������� ����\n");
			else 
			{
				//printf("errorchar=%s\n", errorchar);
			}
				
		}
		else if (menu == 1) {
			errorchar = Out(pQ);
			if (errorchar == NULL)
				printf("�ݹ� Out(pQ) �� ���� ��ȯ���� ���������� ����\n");
			else
			{
				//printf("errorchar=%s\n", errorchar);
			}
				
		}
		else if (menu == 2)
			break;
		else {
		}
		printf("The current status of Queue : ");
		queueprint(pQ);
		
	} while (menu != 2);

	destroyqueue(&pQ);
	return 0;
}

void queueprint(head* pQ){
	queue* t1=NULL, *t2=NULL;
	t1 = pQ->front;	// ���� ��ġ �̸� ����
	t2 = pQ->rear;
	printf("( ");
	while (1) {
		if (pQ->front == NULL) break;
		printf("%s, ", queuefront(pQ));
		pQ->front = pQ->front->link;
	}
	printf(")\n");
	pQ->front = t1;	// ���� ��ġ�� restore
	pQ->rear = t2;
}
char* In(head* pQ) {
	int error;
	char customer[NAME + 1 + SEQ] = { 0, };
	char idx[SEQ+1] = { 0, };
	char* pStr = NULL;

	printf("Customer : ");
	error = scanf("%s", customer);
	if (error != 1) return NULL;

	if (pQ->count >= MAXQUEUE) return NULL;
	else {
		sprintf(idx, "%d", pQ->count + 1);
		strcat(customer, idx);
		pStr = (char*)calloc(strlen(customer) + 1,sizeof(char));		//�޸� �Ҵ� : ������ ������ ����ִٴ� ����, ������ �ؾ������ ����
		if (pStr == NULL) return pStr;
		else {
			strcpy(pStr, customer);									// customer �� In�Լ� �� ���������� ���̴�!!
			pStr = enqueue(pQ, pStr);
			//pStr = enqueue(pQ, customer);							// pStr�� �Ű������� ������ ū �ϳ���!
			//printf("enqueue�� ��ȯ�� %s\n", pStr);
			return pStr;
		}
	}
}
char* Out(head* pQ) {
	char* newData[MAXQUEUE] = { 0, };
	char* store = NULL;
	char* pDel = NULL;
	int i, j;
	char idx[SEQ + 1] = { 0, };
	if ((pDel = dequeue(pQ)) == NULL) return pDel;
	else {
		for (i = 0; store = dequeue(pQ); i++)
			/*newData[i] = (char*)malloc(sizeof(char) * (NAME + 1 + SEQ));
			if (newData[i] = NULL) {
				for (j = i - 1; j >= 0; j--)
					free(newData[j]);
				return newData[i];
			}
			//strcpy(newData[i], store);*/
			newData[i] = store;
		i = 0;
		while (newData[i]) {
			for (j = 0; isalpha(newData[i][j]); j++); // ���� ��ġ�� ���� \0�� ����ֱ�
			newData[i][j] = '\0';
			sprintf(idx, "%d", pQ->count + 1);
			//strcpy(newData[i] + strlen(newData[i]), idx);
			strcat(newData[i], idx);
			enqueue(pQ, newData[i]);
			i++;
		}
		return pDel;
	}
}