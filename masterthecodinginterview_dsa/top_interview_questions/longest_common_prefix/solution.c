#include<stdlib.h>
#include<string.h>

char * longestCommonPrefix(char ** strs, int strsSize){
    char *prefix;
    int prefixLen=0;
    char *first;
    int i, j;
    
    if(strsSize<1){
        prefix = (char*)malloc(sizeof(char));
        *prefix = NULL;
        return prefix;
    }
    
    first = strs[0];
    for(i=0; i<strlen(first); i++){
        for(j=1; j<strsSize; j++){
            if(first[i] != strs[j][i])
                break;
        }
        if(j != strsSize)
            break;
    }
    prefixLen = i;
    
    prefix = (char*)malloc(sizeof(char)*(prefixLen+1));
    strncpy(prefix, first, prefixLen);
    prefix[prefixLen] = NULL;
    
    return prefix;
}
