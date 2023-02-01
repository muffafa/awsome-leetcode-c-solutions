#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

struct HashNode{
    int key;
    int value;
};

int main(){
    int nums[4] = {0,4,3,0};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 0;
    int* returnSize = malloc(sizeof(int)); // to debug segmantation fault 
    /*The segmentation fault is likely happening because of the use of an uninitialized pointer returnSize. In main, returnSize is assigned the value of 0, but 0 is not a valid address for a pointer, so dereferencing it in twoSum is causing the segmentation fault. To fix this, you can allocate memory for returnSize using malloc before passing it to twoSum */
    int* answer;
    answer = twoSum(nums, numsSize, target, returnSize);
    /*
    for( int i = 0 ; i < 2 ; i++ )
    {
        printf("%d is %d\n", i, answer[i]);
    }
    */
    return 0;
}

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

