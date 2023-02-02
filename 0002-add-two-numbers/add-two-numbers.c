#include<stdio.h>
#include<stdlib.h> //to use malloc

struct ListNode {
    unsigned int val;
    struct ListNode *next;
};

unsigned int getValueOfListNode(struct ListNode* listNode);
struct ListNode* getListNodeOfValue(unsigned int num);
//unsigned int getReverseOfValue(unsigned int num);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);

unsigned int main(){
    struct ListNode *l1 = getListNodeOfValue(342);
    struct ListNode *l2 = getListNodeOfValue(465);
    struct ListNode *result = addTwoNumbers(l1,l2);
    printf("value of %d + %d is: %d", getValueOfListNode(l1), getValueOfListNode(l2), getValueOfListNode(result));
    return 0;
}

unsigned int getValueOfListNode(struct ListNode* listNode){
    unsigned int num = 0;
    unsigned int digitVal = 1;
    struct ListNode* p = listNode;
    while (p != NULL)
    {
        num += p->val * digitVal;
        p = p->next;
        digitVal *=10;   
    }
    return num;
}

struct ListNode* getListNodeOfValue(unsigned int num){
    struct ListNode *head = (struct ListNode*)(malloc(sizeof(struct ListNode)));
    head ->next = NULL;
    head ->val = num % 10;
    struct ListNode *p = head;
    num /= 10;
    

    while(num != 0){
        struct ListNode *node = (struct ListNode*) malloc(sizeof(struct ListNode));
        node->val = num % 10;
        node->next = NULL;
        p->next = node;
        p = node;
        num /= 10;
    }
    return head;
}

/*
unsigned int getReverseOfValue(unsigned int num){
    unsigned int sum, remainder, revNum = 0;
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
    unsigned int num = getValueOfListNode(l1) + getValueOfListNode(l2);
    
    return getListNodeOfValue(num);
}

