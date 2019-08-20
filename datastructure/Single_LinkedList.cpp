#include <iostream>
using namespace std;
struct LinkedList{
    int data;
    struct LinkedList *next;
 };
typedef struct LinkedList *node;
node createNode(){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // allocate memory using malloc()
    temp->next = NULL;// make next point to NULL
    return temp;//return the new node
}
node addNode(node head, int value){
    node temp,p;// declare two nodes temp and p
    temp = createNode();//createNode will return a new node with data = value and next pointing to NULL.
    temp->data = value; // add element's value to data part of node
    if(head == NULL){
        head = temp;     //when linked list is empty
    }
    else{
        p  = head;//assign head to p 
        while(p->next != NULL){
            p = p->next;//traverse the list until p is the last node.The last node always points to NULL.
        }
        p->next = temp;//Point the previous last node to the new node created.
    }
    return head;
}
void prependNode(node *head, int value)
{
    node temp= createNode();
	temp->next = *head;
	temp->data = value; 
    *head = temp;
}
void printlist(node node){
	printf("%d\n",node->data);
	if(node->next!=NULL)printlist(node->next);
}
int main(){
	node list = addNode(0,2);
	addNode(list,3);
	addNode(list,4);
	addNode(list,5);
	prependNode(&list,1);
	prependNode(&list,0);
	prependNode(&list,-1);
	printlist(list);
	return 0;
}
