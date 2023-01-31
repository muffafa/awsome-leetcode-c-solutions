#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main(){
    int nums[5] = {2,4,6,7,9};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int target = 9;
    int* returnSize;
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

//it is wrong because you can not return local array you have must to allocate it
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    for(int i = 0; i <  numsSize - 1; i++){
        for(int j = i +1; j < numsSize;j++){
            //printf(" %d, %d \n", i, j);
            if(nums[i] + nums[j] == target){
                *returnSize = 2;
                int answer[2] = {i,j};
                printf("[%d,%d]\n", i,j);
                return answer;
            } 
        }
    }
    *returnSize = 0;
    return 0;
}

