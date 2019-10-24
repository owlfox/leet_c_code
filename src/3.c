#include "3.h"
#include <string.h>
#include <stdio.h>
int lengthOfLongestSubstring(char * s){
    /* use array as hashtable lol */
    char charSet[255] = {0};
    size_t slen = strlen(s);
    size_t windowStart = 0;
    size_t windowEnd = 0;
    int indexEnd = 0;
    int indexStart = 0;
    int maxLen = 0;
    for(size_t windowEnd = 0; windowEnd < slen; windowEnd++) {
        indexEnd = s[windowEnd];
        charSet[indexEnd] += 1;
        
        while(charSet[indexEnd] > 1) {
            indexStart = s[windowStart];
            charSet[indexStart] -= 1;
            windowStart += 1;
            
        }
        maxLen = maxLen < (windowEnd-windowStart+1) ? windowEnd-windowStart+1 : maxLen;
    }
    return maxLen;
}