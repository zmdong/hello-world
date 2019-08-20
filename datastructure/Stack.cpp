#include <iostream>
using namespace std;
#define STACKSIZE 65535
typedef char STACKTYPE;
typedef struct{
	int maxsize;
	int cnt;
	STACKTYPE* pHead;
	
}STACK;
STACK *newstack(int capacity){
	if(capacity<=0)return NULL;
	STACK* pReturn = (STACK*) malloc(sizeof(STACK));
	pReturn->maxsize = STACKSIZE;
	pReturn->cnt = -1;
	pReturn->pHead = (STACKTYPE*)malloc(sizeof(STACKTYPE)*capacity);
	return pReturn;
}
void freestack(STACK *sp){
	if(sp != NULL)free(sp->pHead);
}
int size(STACK *sp){
	if(sp != NULL )return sp->cnt+1;
	else return -1;
}
int isEmpty(STACK *sp){
	if(sp != NULL)return (sp->cnt+1 == 0)?1:0;
	else return -1;
}
int isFull(STACK *sp){
	if(sp != NULL)return (sp->cnt+1 == sp->maxsize)?1:0;
	else return -1;
}
STACKTYPE stackpop(STACK *sp){
	if(sp!=NULL);
	if(isEmpty(sp));//exit
	else return sp->pHead[sp->cnt--];
	
}
STACKTYPE stackpeep(STACK *sp){
	if(sp!=NULL)return (sp->cnt+1>0)?sp->pHead[sp->cnt]:0;
	else;
}
void stackpush(STACK *sp,STACKTYPE x){
	if(sp!=NULL);
	if(isFull(sp));//exit
	else sp->pHead[++sp->cnt] = x;
}
int main(){
	STACK *pStack1 = newstack(10);
	printf("%d\n",stackpeep(pStack1));
	stackpush(pStack1,1);
	printf("%d\n",stackpeep(pStack1));
	stackpush(pStack1,2);
	printf("%d\n",stackpeep(pStack1));
	stackpush(pStack1,3);
	printf("%d\n",stackpeep(pStack1));
	printf("size : %d\n",size(pStack1));
	stackpop(pStack1);
	printf("%d\n",stackpeep(pStack1));
	stackpop(pStack1);
	printf("%d\n",stackpeep(pStack1));
	printf("size : %d\n",size(pStack1));
	stackpop(pStack1);
	printf("%d\n",stackpeep(pStack1));
	printf("size : %d\n",size(pStack1));
	return 0;
}
