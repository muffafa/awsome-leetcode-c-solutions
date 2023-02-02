# [Hash Table to solve the Two-Sum Problem on C language](https://leetcode.com/problems/two-sum/solutions/3129365/hash-table-to-solve-the-two-sum-problem-on-c-language/)

## Approach

The approach of using a hash table to solve the two-sum problem involves creating a hash table to store the elements of the input array and their indices. Then, for each element in the array, the code calculates the difference between the target and the current element. This difference represents the key that we want to look up in the hash table.

If the key is found in the hash table, it means that there exists an element in the array that, when added to the current element, results in the target. In this case, the code stores the indices of the current element and the found element in an answer array and returns the answer array.

If the key is not found in the hash table, the code inserts the current element and its index into the hash table. This way, if a subsequent element in the array results in the target when added to the current element, the hash table would have stored the current element and its index, making it possible to retrieve the indices of the two elements that add up to the target.

## Complexity

- Time complexity:

The time complexity of the two-sum problem solved using a hash table is $O(n)$, where nnn is the size of the input array. This is because, in the worst case, we would have to iterate through the entire array and insert each element into the hash table. However, look up operations are $O(1)$ on average, so the average-case time complexity is $O(n)$. This makes the hash table approach more efficient compared to other approaches such as sorting the array first and then using two pointers, which would have a time complexity of $O(nlogn)$.

- Space complexity:

The space complexity of the two-sum problem solved using a hash table is $O(n)$, where n is the size of the input array. This is because we need to create a hash table to store each element of the input array and its index, and the size of the hash table would be proportional to the size of the input array.

## Code

```c
struct HashNode{
    int key;
    int value;
};

int hashCode(int key, int size){
    //return key % size; // -3 mod 8 = -3
    return (key % size + size) % size; //to avoid negatif hash -3 mod 8 = 5
}

struct HashNode* search(struct HashNode* hashTable[], int size, int key){
    int hashIndex = hashCode(key, size);

    while(hashTable[hashIndex] != NULL){
        if(hashTable[hashIndex]->key == key){
            return hashTable[hashIndex];
        }
        ++hashIndex;
        hashIndex = hashIndex % size;
    }
    return NULL;
}

void insert(struct HashNode* hashTable[], int size, int key, int value){
    struct HashNode *item = (struct HashNode*)(malloc(sizeof(struct HashNode)));
    item->key = key;
    item->value = value;

    int hashIndex = hashCode(key, size);

    while(hashTable[hashIndex] != NULL){
        ++hashIndex;
        hashIndex = hashIndex % size;
    }

    hashTable[hashIndex] = item;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *answer=malloc(2* sizeof(int));

    struct HashNode* hashTable[numsSize];
    // to make empty hashTable
    for(int i=0; i< numsSize; i++){
        hashTable[i] = NULL;
    }
    /* or 
    #include <string.h> //to the top and 
    memset(hashTable, NULL, sizeof(hashTable));
    */
    struct HashNode *hashNode = (struct HashNode*)(malloc(sizeof(struct HashNode)));

    for(int i = 0; i <  numsSize; i++){
        int difference = target - nums[i];
        hashNode = search(hashTable, numsSize, difference);
        if(hashNode != NULL){
            answer[0] = hashNode->value;
            answer[1] = i;
            *returnSize = 2;
            printf("[%d,%d]\n", i,hashNode->value);
            return answer;
        }
        insert(hashTable, numsSize, nums[i], i);
    }
    *returnSize = 0;
    return 0;
}
```
