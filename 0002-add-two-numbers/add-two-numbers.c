#include<stdio.h>
#include<stdlib.h> //to use malloc

struct ListNode {
    int val;
    struct ListNode *next;
};

int getValueOfListNode(struct ListNode* listNode);
struct ListNode* getListNodeOfValue(int num);
//int getReverseOfValue(int num);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

int main(){
    struct ListNode *l1 = getListNodeOfValue(342);
    struct ListNode *l2 = getListNodeOfValue(465);
    struct ListNode *result = addTwoNumbers(l1,l2);
    printf("value of %d + %d is: %d", getValueOfListNode(l1), getValueOfListNode(l2), getValueOfListNode(result));
    return 0;
}

int getValueOfListNode(struct ListNode* listNode){
    int num = 0;
    int digitVal = 1;
    struct ListNode* p = listNode;
    while (p != NULL)
    {
        num += p->val * digitVal;
        p = p->next;
        digitVal *=10;   
    }
    return num;
}

struct ListNode* getListNodeOfValue(int num){
    struct ListNode *head = (struct ListNode*)(malloc(sizeof(struct ListNode)));
    head ->next = NULL;
    head ->val = 0;
    struct ListNode *p = head;
    

    while(num != 0){
        p ->val = num % 10; //342 => 2 
        num /= 10; //num = 34
        struct ListNode *node = (struct ListNode*)(malloc(sizeof(struct ListNode)));
        node->next = NULL;
        node->val = 0;
        p->next = node;
        p = p ->next;
    }
    p = NULL;
    return head;
}

/*
int getReverseOfValue(int num){
    int sum, remainder, revNum = 0;
    while (num != 0)
    {
        remainder = num % 10;
        revNum = revNum * 10 + remainder;
        num = num / 10;
    }
    return revNum;
}
*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int num = getValueOfListNode(l1) + getValueOfListNode(l2);
    
    return getListNodeOfValue(num);
}

