#include <stdio.h>
#include <ctype.h>
#include "queue_array_bank.h"

int In(queue* pQ);
char* Out(queue* pQ);
void queueprint(queue* pQ);

int main(void) {
	int menu=3,error;
	char* errorchar = NULL;
	queue* pQ = NULL;

	pQ = createQ(SIZE);
	if (pQ == NULL) return -1;

	printf("* * *************** * *\n");
	printf("* * ���� ���� �ý��� * *\n");
	printf("* * *************** * *\n");
	do{
		if (menu == 0) {
			printf("Customer : ");
			error = In(pQ);
			if (error != 1) {
				//printf("�ݹ� In(pQ) �� ���� ��ȯ���� ���������� ����\n");
				printf("����! In(pQ) �� %d�� ��ȯ\n",error);
			}
			else {
				//printf("main�Լ�)%s\n",pQ->person[pQ->rear]);
			}
		}
		else if (menu == 1) {
			errorchar = Out(pQ);
			if (errorchar == NULL) {
				printf("����! Out(pQ) �� NULL�� ��ȯ\n");
			}
		}
		else if (menu == 2)
			break;
		else 
			printf("�ùٸ� �޴��� ������ �ּ���\n");
		if (isemptyqueue(pQ) != true) {
			printf("The current status of Queue : ");
			queueprint(pQ);
		}
		printf("In (0), out(1), exit (2) : ");
		error = scanf("%d", &menu);
		getchar();
		puts("");
		if (error != 1) menu = 3;
	} while (menu!=2);
	destroyqueue(&pQ);
	return 0;
}

int In(queue* pQ) {
	char* pName = (char*)malloc(sizeof(char) * (NAME+INDEX)); // +INDEX : '\0' + customer index
	int error,i=0;
	char idxchar[INDEX+1] = { 0, };

	if (pName == NULL) return -11111111;
	else {
		pName = fgets(pName, NAME + INDEX, stdin);
		while (pName[i] != '\n')
			i++;
		pName[i] = '\0';
		if (pQ->cnt >= MAXQ) {
			printf("���� �ʹ� �� �ε����� �Ұ��մϴ�.\n");
			return -11111111;
		}
		else {
			sprintf(idxchar, "%d", pQ->cnt + 1);
			//strcpy(pName + strlen(pName), idxchar);
			strcat(pName, idxchar);
			error = enqueue(pQ, pName);
		}
		return error;
	}
}

char* Out(queue* pQ) {
	char* newData[10] = { 0, };
	char idxchar[INDEX+1] = { 0, };
	char* pDel = NULL;
	int i=0,j,k;
	if ((pDel = dequeue(pQ)) == NULL) return NULL;
	else {
		while (newData[i++] = dequeue(pQ));
		i = 0;
		while (newData[i]) {
			//printf("newData[%d]=%s\n", i, newData[i]);
			for (j = 0; isalpha(newData[i][j]); j++) {
				//printf("isalpha(%c)=%d\n", newData[i][j], isalpha(newData[i][j]));
			}
			newData[i][j] = '\0';

			sprintf(idxchar, "%d", pQ->cnt + 1);
			strcpy(newData[i] + strlen(newData[i]), idxchar);
			enqueue(pQ, newData[i]);
			i++;
		}
		queueprint(pQ);
		return pDel;
	}
}
void queueprint(queue* pQ) {
	int t1, t2;
	t1 = pQ->front;
	t2 = pQ->rear;
	printf("( ");
	while (1) {
		if (queuefront(pQ) == NULL) break;
		printf("%s, ", queuefront(pQ));
		pQ->front = (pQ->front + 1) % pQ->size;
	}
	printf(")\n");
	pQ->front = t1;
	pQ->rear = t2;
}