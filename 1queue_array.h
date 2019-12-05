	#pragma once
	#include <stdbool.h>
	#include <stdlib.h>

	typedef struct {					//배열 큐는 자료를 담을 arr / 큐의 크기 size(fixed) / 큐의 front,rear 위치를 나타내는 변수가 필요
		int* arr;
		int size;
		int front, rear;
	}queue;

	queue* createQ(int size);			//size 의 크기를 갖는 큐를 동적할당하여 가리키도록 한다. ( Array queue )
	void enqueue(queue* pQ, int item);	//int 자료형 하나를 큐에 넣는다. 맨 뒤(rear)에 선다.	
	int dequeue(queue* pQ);				//맨 앞에 있는 데이터가 큐에서 나온다. 맨 앞(front)이 나온다.
	int queuefront(queue* pQ);			//맨 앞에 있는 데이터를 확인만 한다.
	int queuerear(queue* pQ);			//맨 뒤에 있는 데이터를 확인만 한다.
	bool isfullqueue(queue* pQ);		//큐가 꽉 찼는지 확인한다. ( front , rear )
	bool isemptyqueue(queue* pQ);		//큐가 비었는지 확인한다.  ( front == rear )
	void clearqueue(queue* pQ);			//큐를 비운다.			 ( front == rear )
	void destroyqueue(queue** pQ);		//큐를 비우고, 큐 포인터까지 메모리 해제한다.