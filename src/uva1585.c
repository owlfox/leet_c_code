#include "uva1585.h"
// uva1585 https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=448&page=show_problem&problem=4460
#define MAIN
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#define BUFFER_SIZE 128
char BUFFER[BUFFER_SIZE];

static const char PASS='O';
static const char FAIL='X';


int getScore(const char input[]) {
    int sum = 0, score = 1;
    size_t i;
    for(i=0; i<strlen(input); i++) {
        if(input[i] == PASS) {
            sum += score;
            score ++;
            
        } else {
            
            score = 1;
        }
    }
    return sum;
}


#ifdef MAIN
int main() {
    
    int case_count = 0, rtn=0;
    if(scanf("%d", &case_count)) {
    
    while(case_count--) {
        scanf("%s", BUFFER);
        printf("%d\n", getScore(BUFFER));
    }
    } else {
        return -1;
    }

}
#endif