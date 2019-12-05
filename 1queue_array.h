	#pragma once
	#include <stdbool.h>
	#include <stdlib.h>

	typedef struct {					//�迭 ť�� �ڷḦ ���� arr / ť�� ũ�� size(fixed) / ť�� front,rear ��ġ�� ��Ÿ���� ������ �ʿ�
		int* arr;
		int size;
		int front, rear;
	}queue;

	queue* createQ(int size);			//size �� ũ�⸦ ���� ť�� �����Ҵ��Ͽ� ����Ű���� �Ѵ�. ( Array queue )
	void enqueue(queue* pQ, int item);	//int �ڷ��� �ϳ��� ť�� �ִ´�. �� ��(rear)�� ����.	
	int dequeue(queue* pQ);				//�� �տ� �ִ� �����Ͱ� ť���� ���´�. �� ��(front)�� ���´�.
	int queuefront(queue* pQ);			//�� �տ� �ִ� �����͸� Ȯ�θ� �Ѵ�.
	int queuerear(queue* pQ);			//�� �ڿ� �ִ� �����͸� Ȯ�θ� �Ѵ�.
	bool isfullqueue(queue* pQ);		//ť�� �� á���� Ȯ���Ѵ�. ( front , rear )
	bool isemptyqueue(queue* pQ);		//ť�� ������� Ȯ���Ѵ�.  ( front == rear )
	void clearqueue(queue* pQ);			//ť�� ����.			 ( front == rear )
	void destroyqueue(queue** pQ);		//ť�� ����, ť �����ͱ��� �޸� �����Ѵ�.