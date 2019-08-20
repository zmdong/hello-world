struct ListNode {
	 int val;
	 struct ListNode *next;
};
#include <iostream>
using namespace std;
typedef struct ListNode LISTNODE;
LISTNODE*addListNode(LISTNODE *preNode , int node){
    if(preNode == NULL || preNode->next != NULL)return NULL;
    LISTNODE* listNode = preNode->next= (LISTNODE*)malloc(sizeof(LISTNODE));
    listNode->val = node;
    listNode->next = NULL;
    return listNode;
}
int peek(LISTNODE*listNode){
    if(listNode == NULL)return 0;
    return listNode->val;
}
LISTNODE* nextNode (LISTNODE* listNode){
    if(listNode == NULL)return NULL;
    return listNode->next;
}
int listlen(LISTNODE*node){
    if(node == NULL)return 0;
    int cnt=1;
    while(node->next!=NULL){
        cnt++;
        node = node->next;
    }
    return cnt;
}
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL)return l2;
    if(l2==NULL)return l1;
    LISTNODE* const list =(LISTNODE*)malloc(sizeof(LISTNODE));
    LISTNODE* head = list;
    int len1,len2,c1=0,c2=0,temp1,temp2;
    len1 = listlen(l1);
    len2 = listlen(l2);
    temp1 = peek(l1);
    temp2 = peek(l2);
    while(1){
        if(c1<len1 && c2<len2){
            if(temp1<=temp2){
                head = addListNode(head,temp1);
                l1 = nextNode(l1);
                temp1 = peek(l1);
                c1++;
            }
            else{
                head = addListNode(head,temp2);
                l2 = nextNode(l2);
                temp2 = peek(l2);
                c2++;
            }
        }
        else if(c1 == len1){
            while(c2 == len2){
                head = addListNode(head,temp2);
                l2 = nextNode(l2);
                temp2 = peek(l2);
                c2++;
            }
            break;
        }
        else{
            while(c1 == len1){
                head = addListNode(head,temp1);
                l1 = nextNode(l1);
                temp1 = peek(l1);
                c1++;
            }
        }
    }
    
    return list;
}

int main(){
	LISTNODE *l1 =(LISTNODE*)malloc(sizeof(LISTNODE));
	LISTNODE *l2 =(LISTNODE*)malloc(sizeof(LISTNODE));
	l1->next = NULL;
	LISTNODE *list1=l1,*list2=l2;
	list1 = addListNode(list1,1);
	list1 = addListNode(list1,2);
	list1 = addListNode(list1,4);
	return 0;
}
