#include<stdio.h>
#include<stdlib.h> //to use malloc

// i command some lines and functions becuse they dont work with high numers (maximum value of int or anytype can be failed)

struct ListNode {
    int val;
    struct ListNode *next;
};

//int getValueOfListNode(struct ListNode* listNode);
struct ListNode* getListNodeOfValue(int num);
//int getReverseOfValue(int num);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
void printValueOfListNode(struct ListNode* listNode);

int main(){
    struct ListNode *l1 = getListNodeOfValue(342);
    struct ListNode *l2 = getListNodeOfValue(465);
    struct ListNode *result = addTwoNumbers(l1,l2);
    //printf("value of %d + %d is: %d", getValueOfListNode(l1), getValueOfListNode(l2), getValueOfListNode(result));
    printValueOfListNode(result);
    return 0;
}


// int getValueOfListNode(struct ListNode* listNode){
//     int num = 0;
//     int digitVal = 1;
//     struct ListNode* p = listNode;
//     while (p != NULL)
//     {
//         num += p->val * digitVal;
//         p = p->next;
//         digitVal *=10;   
//     }
//     return num;
// }

struct ListNode* getListNodeOfValue(int num){
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

//it prints in reverse order because behavior of data structure
void printValueOfListNode(struct ListNode* listNode){
    while (listNode != NULL)
    {
        printf("%d", listNode->val);
        listNode = listNode->next;
    }
    printf("\n");
}

// an algorithm to take a reverse of a number
// int getReverseOfValue(int num){
//     int sum, remainder, revNum = 0;
//     while (num != 0)
//     {
//         remainder = num % 10;
//         revNum = revNum * 10 + remainder;
//         num = num / 10;
//     }
//     return revNum;
// }


// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
//     int num = getValueOfListNode(l1) + getValueOfListNode(l2);
//     return getListNodeOfValue(num);
// }

// this cause long runtime and it can be optimazable
// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
//     int carry = 0;
//     struct ListNode *dummyHead = (struct ListNode*) malloc(sizeof(struct ListNode));
//     dummyHead->val = 0;
//     dummyHead->next = NULL;
//     struct ListNode *p = dummyHead;

//     while (l1 != NULL || l2 != NULL || carry != 0)
//     {
//         int x, y = 0;

//         if(l1 != NULL){
//             x = l1->val;
//         }

//         if(l2 != NULL){
//             y = l2->val;
//         }

//         struct ListNode *node = (struct ListNode*) malloc(sizeof(struct ListNode));
//         int sum = x + y + carry;
//         carry = sum / 10;
//         node->val = sum % 10;
//         node->next = NULL;
//         p->next = node;
//         p = p->next;

//         if(l1 != NULL){
//             l1 = l1->next;
//         }
//         if(l2 != NULL){
//             l2 = l2->next;
//         }
//     }
//     return dummyHead ->next;
// }

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummyHead = {0, NULL};
    struct ListNode *p = &dummyHead;
    int carry = 0;

    while (l1 || l2 || carry) {
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = x + y + carry;
        carry = sum / 10;

        struct ListNode *node = malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = NULL;
        p->next = node;
        p = p->next;

        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    return dummyHead.next;
}
