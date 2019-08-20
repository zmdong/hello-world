/*Queue - Linked List implementation*/
/*function : Enqueue Dequeue Front*/
#include<stdio.h>
#include<stdlib.h>
struct Queue{
	struct Node* front;
	struct Node* rear;
};
struct Node {
	int data;
	struct Node* next;
};
// Two glboal variables to store address of front and rear nodes. 


// To Enqueue an integer
void Enqueue(struct Queue *queue,int x) {
	struct Node* temp = 
		(struct Node*)malloc(sizeof(struct Node));
	temp->data =x; 
	temp->next = NULL;
	if(queue->front == NULL && queue->rear == NULL){
		queue->front = queue->rear = temp;
		return;
	}
	queue->rear->next = temp;
	queue->rear = temp;
}

// To Dequeue an integer.
void Dequeue(struct Queue *queue) {
	struct Node* temp = queue->front;
	if(queue->front == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	if(queue->front == queue->rear) {
		queue->front = queue->rear = NULL;
	}
	else {
		queue->front = queue->front->next;
	}
	free(temp);
}

int Front(struct Queue *queue) {
	if(queue->front == NULL) {
		printf("Queue is empty\n");
		return 0;
	}
	return queue->front->data;
}

void Print(struct Queue *queue) {
	struct Node* temp = queue->front;
	while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	/* Drive code to test the implementation. */
	// Printing elements in Queue after each Enqueue or Dequeue
	struct Queue queue = {0}; 
	Enqueue(&queue,2); Print(&queue); 
	Enqueue(&queue,4); Print(&queue);
	Enqueue(&queue,6); Print(&queue);
	Dequeue(&queue);  Print(&queue);
	Enqueue(&queue,8); Print(&queue);
	printf("%d ",Front(&queue));
}
