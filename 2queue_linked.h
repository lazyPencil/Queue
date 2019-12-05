#pragma once
#include <stdbool.h> // bool
#include <stdlib.h> // malloc, free
#include <string.h> // strcpy
#include <stdio.h>

typedef struct queue {						//Linked list queue. 자료를 담는 data + 큐끼리 줄지어주는 link
	char* data;
	struct queue* link;
} queue;
typedef struct {							//Linked list head. 큐들의 수 = count / 선입 큐 = front / 후입 큐 = rear
	int count;
	queue* front, * rear;
} head;

head* createQ(void);						//head* 할당. enqueue마다 동적 할당. queue*를 가리키는 front,rear / 링크리스트 수 = count
void enqueue(head* pQ, char* element);		//char* 원소를 받도록 새 queue 동적 할당. rear의 큐->link는 NULL에서 새 큐로. 이제 rear는 새 큐로
char* dequeue(head* pQ);					//front는 큐의 link를 가리킴. 원래 큐는 메모리 해제.
char* queuefront(head* pQ);					//front의 큐->data를 출력
char* queuerear(head* pQ);					//rear 의 큐->data를 출력
bool isfullqueue(head* pQ);					//동적할당을 해보고 not NULL이면 not FULL / 불필요한 함수라고 생각
bool isemptyqueue(head* pQ);				//달려있는 리스트가 없으면 EMPTY
void clearqueue(head* pQ);					//달려있는 리스트가 없을 때까지 front의 큐 메모리 해제 및 큐->link로 front 옮기기
void destroyqueue(head** ppQ);				//head* 자신까지 메모리 해제