#include <stdlib.h>
#include <stdio.h>
#include "13_3sum.h"

// didn't handle the malloc failed case well..
// should use goto for that..

int compare(const void *a, const void *b)
{
      int c = *(int *)a;
      int d = *(int *)b;
      if(c < d) {return -1;}            
      else if (c == d) {return 0;}      
      else return 1;                   
}

int** find_pairs(int* numbers, int numbersSize, int target, int* returnSize){
    int* rtn;
    int index1, index2;
    int** results = NULL;
    *returnSize = 0;
    index1 = 0;
    index2 = numbersSize -1;
    
    // for(int i=0; i<numbersSize; i++){
    //     printf("%d ", numbers[i]);
    // }
    // printf("||%d, %d, %d. %d\n", numbersSize, target, index1, index2);
    while(index1 < index2){
        if(numbers[index1] + numbers[index2] == target) {
            // printf("found: %d, %d, %d\n", target, numbers[index1], numbers[index2]);
            // if (*returnSize == 0) {
            //     results = (int**) malloc(sizeof(int*));
            // } else {
            results = (int**) realloc(results, ((*returnSize)+1) *sizeof(int*));
            // }
            if(results == NULL) {
                *returnSize = -1;
                return NULL;
            }


            rtn = (int*) malloc(3*sizeof(int));
            if(rtn == NULL) {
                *returnSize = -1;
                return NULL;
            }
            
            
            rtn[0] = -target;
            rtn[1] = numbers[index1];
            rtn[2] = numbers[index2];
            index1+=1;
            index2-=1;
            results[*returnSize] = rtn;
            // printf("item %d: %p\n", *returnSize, rtn);
            // printf("%p: %d\n", rtn, rtn[0]);
            // printf("%p: %d\n", rtn+1, rtn[1]);
            // printf("%p: %d\n", rtn+2, rtn[2]);
            // if(index1-1 > 0) while (numbers[index1] == numbers[index1-1]) index1++;
            for(int i=0; i<numbersSize-1 ; i++){
                if (i<index1 && numbers[i] == numbers[i+1] ) {
                    if(numbers[i] == numbers[index2]  ) index1 = i+2;
                }
            }
            for(int i=numbersSize-1; i>0 ; i--){
                if (i>index2 && numbers[i] == numbers[i-1] ) {
                    if(numbers[i] == numbers[index2]  ) index2 = i-2;
                }
            }
                // while (numbers[index2] == numbers[index2+1]) 
                //     index2--;
             
            // printf("sss: %d, %p, %d\n", *returnSize, rtn, rtn[0]);
            *returnSize += 1;

        } else if ( numbers[index1] + numbers[index2] > target ){
            index2--;
        } else if (numbers[index1] + numbers[index2] < target ){
            index1++;
        }
    }
    
    return results;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int rtnSize;
    int** rtn;
    int** results;
    *returnSize = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    for(int i=0; (i+2)<numsSize; i++) {
        //skip duplicates
        // printf("i: %d\n", i );
        if(i != 0 && nums[i] == nums[i-1]) {
            continue;
        }

        rtn = find_pairs(nums+i+1, numsSize-i-1, -nums[i], &rtnSize);
        if(rtnSize == -1) {
            *returnSize = -1;
            return NULL;
        }
        //allocate results pointer storage
        if (rtnSize > 0) {
            // printf("info: %d, %d, %p\n", rtnSize, *rtn[0], *rtn);
            if (*returnSize == 0) {
                results = (int**) malloc(rtnSize*sizeof(int*));
                // printf("eee %d\n", rtnSize*sizeof(int*));
            } else {
                results = (int**) realloc(results, (rtnSize+(*returnSize)) *sizeof(int*));
                // printf("eee %d\n", (rtnSize+(*returnSize)) *sizeof(int*));
            }
            
            if(results == NULL) {
                *returnSize = -1;
                return NULL;
            }
            
            // /copy the results pointers
            for(int i=0; i<rtnSize; i++) {
                // printf("%d, %d, %d\n",i, *returnSize, (*returnSize)+rtnSize);
                results[(*returnSize)+i] = rtn[i];
                // printf("%d, %p, %p\n",i, results[i], rtn[i]);
                
            }
            *returnSize += rtnSize;
            free(rtn);
        }
    }
    int* temp = (int*)malloc(sizeof(int) * (*returnSize));
    // printf("%p, %p, %p\n", temp, *returnColumnSizes, nums);
    if(*returnSize) {
        *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
        for(int i = 0; i < *returnSize; i++) (*returnColumnSizes)[i]=3;
    }
    
    return results;
}


// int main(void)
// {
//     int** columnSize;
//     // int nums[6] = {3,0,-2,-1,1,2};
//         int nums[8] = {-5,-5,2,0,-2,-3,2,-4};
//     int rtnSize, **rtn;
//     int *array, *sizeArray;
//     // printf("test %p: \n", columnSize);
//     columnSize = (int**) malloc(sizeof(int*));
//     // printf("test %p, %p: \n", columnSize, *columnSize);
//     // *columnSize = nums;
    
//     // printf("%p??%d\n",*columnSize, (*columnSize)[2]);
//     // printf("test %p, %p: \n", columnSize, *columnSize);
//     rtn = threeSum(nums, 8, &rtnSize, columnSize);
//     // printf("%d\n", (*rtn)[0]);
//     // printf("test %p, %p: \n", columnSize, *columnSize);
//     // printf("%d\n",(*columnSize)[0]);
// }