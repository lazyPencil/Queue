#pragma once
#include <stdbool.h> // bool
#include <stdlib.h> // malloc, free
#include <string.h> // strcpy
#include <stdio.h>

typedef struct queue {						//Linked list queue. �ڷḦ ��� data + ť���� �������ִ� link
	char* data;
	struct queue* link;
} queue;
typedef struct {							//Linked list head. ť���� �� = count / ���� ť = front / ���� ť = rear
	int count;
	queue* front, * rear;
} head;

head* createQ(void);						//head* �Ҵ�. enqueue���� ���� �Ҵ�. queue*�� ����Ű�� front,rear / ��ũ����Ʈ �� = count
void enqueue(head* pQ, char* element);		//char* ���Ҹ� �޵��� �� queue ���� �Ҵ�. rear�� ť->link�� NULL���� �� ť��. ���� rear�� �� ť��
char* dequeue(head* pQ);					//front�� ť�� link�� ����Ŵ. ���� ť�� �޸� ����.
char* queuefront(head* pQ);					//front�� ť->data�� ���
char* queuerear(head* pQ);					//rear �� ť->data�� ���
bool isfullqueue(head* pQ);					//�����Ҵ��� �غ��� not NULL�̸� not FULL / ���ʿ��� �Լ���� ����
bool isemptyqueue(head* pQ);				//�޷��ִ� ����Ʈ�� ������ EMPTY
void clearqueue(head* pQ);					//�޷��ִ� ����Ʈ�� ���� ������ front�� ť �޸� ���� �� ť->link�� front �ű��
void destroyqueue(head** ppQ);				//head* �ڽű��� �޸� ����