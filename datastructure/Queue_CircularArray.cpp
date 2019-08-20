/* Queue - Circular Array implementation in C++*/
/* modify to in C*/
#include<iostream>
using namespace std; 
#define MAX_SIZE 101  //maximum size of the array that will store Queue. 

typedef struct {
	int front, rear;
	int circle[MAX_SIZE];
}QUEUE;

QUEUE* creatQueue(){
	QUEUE* newQueue = (QUEUE*)malloc(sizeof(QUEUE));
	newQueue->rear = newQueue->front = -1;
	return newQueue;
}

bool isEmpty(QUEUE *queue){
	if(queue==NULL)return 0;
	return queue->front==-1 && queue->rear==-1;
}

bool isFull(QUEUE *queue){
	if(queue==NULL)return false;
	return ((queue->rear+1)%MAX_SIZE) == queue->front? 1:0;
}

void enqueue(QUEUE *queue,int val){
	if(isEmpty(queue))
		queue->front = queue->rear = 0;
	else if(isFull(queue));
	else
		queue->rear = (queue->rear+1)%MAX_SIZE;
	queue->circle[queue->rear] = val;
}

void dequeue(QUEUE *queue){
	if(isEmpty(queue));
	else if(queue->front == queue->rear)
		queue->front= queue->rear = -1;
	else 
		queue->front = (queue->front+1)%MAX_SIZE;
}

int front(QUEUE* queue){
	if(isEmpty(queue))printf("front fault");
	return queue->circle[queue->front];
}

void print(QUEUE*queue){
	if(isEmpty(queue))printf("print fault");
	int temp = queue->front;
	for(;temp != queue->rear ;){
		printf("%d ",queue->circle[temp]);
		temp = (temp+1)%MAX_SIZE;
	}
	printf("%d \n",queue->circle[temp]);
} 
int main()
{
	QUEUE* q = creatQueue();
	enqueue(q,2);print(q);
	enqueue(q,4);print(q);
	enqueue(q,6);print(q);
	dequeue(q);print(q);
	enqueue(q,8);print(q);
	return 0;
}
/*
class Queue
{
private:
	int A[MAX_SIZE];
	int front, rear; 
public:
	Queue()
	{
		front = -1; 
		rear = -1;
	}
	bool IsEmpty()
	{
		return (front == -1 && rear == -1); 
	}
	bool IsFull()
	{
		return (rear+1)%MAX_SIZE == front ? true : false;
	}
	void Enqueue(int x)
	{
		cout<<"Enqueuing "<<x<<" \n";
		if(IsFull())
		{
			cout<<"Error: Queue is Full\n";
			return;
		}
		if (IsEmpty())
		{ 
			front = rear = 0; 
		}
		else
		{
		    rear = (rear+1)%MAX_SIZE;
		}
		A[rear] = x;
	}
	void Dequeue()
	{
		cout<<"Dequeuing \n";
		if(IsEmpty())
		{
			cout<<"Error: Queue is Empty\n";
			return;
		}
		else if(front == rear ) 
		{
			rear = front = -1;
		}
		else
		{
			front = (front+1)%MAX_SIZE;
		}
	}
	int Front()
	{
		if(front == -1)
		{
			cout<<"Error: cannot return front from empty queue\n";
			return -1; 
		}
		return A[front];
	}
	void Print()
	{
		// Finding number of elements in queue  
		int count = (rear+MAX_SIZE-front)%MAX_SIZE + 1;
		cout<<"Queue       : ";
		for(int i = 0; i <count; i++)
		{
			int index = (front+i) % MAX_SIZE; // Index of element while travesing circularly from front
			cout<<A[index]<<" ";
		}
		cout<<"\n\n";
	}
};
int main()
{
   Queue Q; // creating an instance of Queue. 
   Q.Enqueue(2);  Q.Print();  
   Q.Enqueue(4);  Q.Print();  
   Q.Enqueue(6);  Q.Print();
   Q.Dequeue();	  Q.Print();
   Q.Enqueue(8);  Q.Print();
}
*/
