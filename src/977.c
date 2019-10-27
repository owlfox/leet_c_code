#include <stdlib.h>
#include <stdio.h>
#include "977.h"
int* sortedSquares(int* A, int ASize, int* returnSize){
    int* rtn;
    int index1, index2, rtnIndex;
    int j = 0;
    *returnSize = 0;
    rtnIndex = 0;

    rtn = (int*) malloc(ASize*sizeof(int));
    if(rtn == NULL) {
        *returnSize = -1;
        return NULL;
    }
    
    
    //all minus
    if(A[ASize - 1] < 0) {
        index1 = ASize-1;
        index2 = ASize;
    } else if (A[0] > 0){
        index1 = -1;
        index2 = 0;
    } else {
        for(int i=0; i<ASize; i++){
            if(A[i] >= 0) {
                index2 = i;
                index1 = i-1;
                break;
            }
        }
    }
    
    

    
    
    while(!(index1 == -1 && index2 == ASize)){
        
        //left done
        if(index1 == -1 ) {
            rtnIndex = index2;
            ++index2;
            
        //right done
        } else if (index2 == ASize) {
            rtnIndex = index1;
            --index1;
            
        } else {
            if((-A[index1]) <= A[index2]) {
                rtnIndex = index1;
                --index1;
                
            } else {
                rtnIndex = index2;
                ++index2;
                
            }
        }
        rtn[j] = A[rtnIndex];
        
        ++j;
    }
    for(int i=0; i<ASize; i++){
        rtn[i] = rtn[i]*rtn[i];
    }
    *returnSize = ASize;
    return rtn;
}