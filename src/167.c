#include <stdlib.h>
#include <stdio.h>
#include "167.h"


int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int* rtn;
    int index1, index2;
    *returnSize = 0;
    
    

    index1 = 0;
    index2 = numbersSize -1;

    while(index1 <= index2){
        if(numbers[index1] + numbers[index2] == target) {
            
            rtn = (int*) malloc(2*sizeof(int));
            if(rtn == NULL) {
                *returnSize = -1;
                return NULL;
            }
            *returnSize = 2;
            rtn[0] = index1+1;
            rtn[1] = index2+1;
            return rtn;
        } else if (numbers[index1] + numbers[index2] > target){
            
            index2--;
        } else if (numbers[index1] + numbers[index2] < target){
            
            index1++;
        }
    }
    
    return NULL;
}
