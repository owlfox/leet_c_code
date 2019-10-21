#include "1221.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>

static const char R = 'R';
static const char L = 'L';


int balancedStringSplit(char * s){
    size_t slen = strlen(s);
    size_t Rcount,Lcount;
    int rtn = 0;
    Rcount = 0; Lcount = 0;
    
    for(size_t i=0; i<slen; i++) {
        if(s[i] == R)  Rcount += 1 ;
        else  Lcount += 1 ;
        if (Lcount == Rcount) rtn += 1;
    }
    return rtn;
}

