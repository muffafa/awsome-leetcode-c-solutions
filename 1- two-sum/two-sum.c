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

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *answer=malloc(2* sizeof(int));
    for(int i = 0; i <  numsSize - 1; i++){
        for(int j = i +1; j < numsSize;j++){
            //printf(" %d, %d \n", i, j);
            if(nums[i] + nums[j] == target){
                *returnSize = 2;
                answer[0] = i;
                answer[1] = j;
                printf("[%d,%d]\n", i,j);
                return answer;
            } 
        }
    }
    *returnSize = 0;
    return 0;
}

