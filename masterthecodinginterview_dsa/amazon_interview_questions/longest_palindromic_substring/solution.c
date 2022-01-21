#include<string.h>
#include<stdlib.h>
#include<assert.h>

void getPalindromeIndices(char *s, int pivot, int *retSt, int *retE){
    const int len = strlen(s);
    int st, e;
    
    st = pivot-1;
    while(st>=0 && s[st] == s[pivot]) st--;
    e = pivot+1;
    while(e<len && s[e] == s[pivot]) e++;
    
    while(st>=0 && e<len && s[st]==s[e]){
        st--;
        e++;
    }
    
    *retSt = st+1;
    *retE = e-1;
    return;
}

char * longestPalindrome(char * s){
    const int len = strlen(s);
    int stmax, emax, st, e;
    char *result;
    int resultlen;
    
    if(len<1) return "";
    
    stmax = emax = 0;
    for(int i=0; i<len; i++){
        getPalindromeIndices(s, i, &st, &e);
        if((e-st) > (emax-stmax)){
            stmax = st;
            emax = e;
        }
    }
    
    resultlen = emax-stmax+1;
    result = (char*) malloc(sizeof(char)*(resultlen+1));
    assert(result != NULL);
    
    memcpy(result, s+stmax, resultlen);
    result[resultlen] = NULL;
    return result;
}
