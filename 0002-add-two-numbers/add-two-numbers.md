# [A Linked List Approach to Adding Large Numbers in C Language](https://leetcode.com/problems/add-two-numbers/solutions/3134366/a-linked-list-approach-to-adding-large-numbers-in-c-language/)

## Approach
<!-- Describe your approach to solving the problem. -->
The algorithm adds two numbers represented by linked lists where each node in the linked list contains a single digit. It uses a dummy head to store the result linked list and adds the digits one by one while considering any carry from the previous addition. If either of the input linked lists has no more nodes, the algorithm considers its value as 0. The algorithm continues until both linked lists are traversed and the carry is 0. Finally, it returns the next node of the dummy head as the result linked list.

## Complexity

- Time complexity:
<!-- Add your time complexity here, e.g. $O(n)$ -->
The time complexity of this algorithm is $O(max(m, n))$, where $m$ is the number of nodes in the first linked list and $n$ is the number of nodes in the second linked list. This is because the algorithm performs an operation on each node of the linked lists only once and the number of nodes in the result linked list is at most $max(m, n) + 1$, so the algorithm takes linear time with respect to the number of nodes.

- Space complexity:
<!-- Add your space complexity here, e.g. $O(n)$ -->
The space complexity of this algorithm is $O(max(m, n))$, where $m$ is the number of nodes in the first linked list and $n$ is the number of nodes in the second linked list. This is because the algorithm creates a new node in the result linked list for each digit of the sum and the number of nodes in the result linked list is at most $max(m, n) + 1$. Therefore, the algorithm uses linear space with respect to the number of nodes. Additionally, the algorithm uses a constant amount of space for variables such as carry and pointers.

## Code

``` c
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
```
