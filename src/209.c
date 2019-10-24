#include "209.h"
#include <limits.h>
#include <stdio.h>
int minSubArrayLen(int s, int* nums, int numsSize){
    int windowStart = 0;
    int windowEnd = 0;
    int minsize = INT_MAX;
    int sum = 0;
    for(; windowEnd<numsSize; windowEnd++) {
        sum += nums[windowEnd];

        
        //move window right, since it's the best cast with this windowStart
        while(sum >= s){
            sum -= nums[windowStart];
            minsize = minsize > (windowEnd-windowStart+1) ? windowEnd-windowStart+1 : minsize;
            windowStart += 1;
        }
    }
    return minsize == INT_MAX ? 0 : minsize;
}