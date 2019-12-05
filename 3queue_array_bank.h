#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define SIZE 10
#define NAME 40
#define INDEX 4
#define MAXQ 9999

typedef struct {
	char** person;
	int size;
	int front, rear;
	int cnt;
}queue;

queue* createQ(int size);
int enqueue(queue* pQ, char* name);
char* dequeue(queue* pQ);
char* queuefront(queue* pQ);
char* queuerear(queue* pQ);
bool isfullqueue(queue* pQ);
bool isemptyqueue(queue* pQ);
void clearqueue(queue* pQ);
void destroyqueue(queue** ppQ);