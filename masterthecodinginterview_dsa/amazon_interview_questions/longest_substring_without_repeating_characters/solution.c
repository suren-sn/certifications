#include<string.h>

int lengthOfLongestSubstring(char * s){
    int l, r;
    int len = strlen(s);
    int maxsubstringlen;
    int substringlen;
    
    if(len<2) return len;
    
    l=0;
    maxsubstringlen=0;
    for(r=1; r<len; r++){
        //validate window l to r
        for(int i=l; i<r; i++){
            if(s[i] == s[r]){
                substringlen = r-l;
                if(substringlen > maxsubstringlen) maxsubstringlen = substringlen;
                l=i+1;
                break;
            }
        }
    }
    substringlen = r-l;
    if(substringlen > maxsubstringlen) maxsubstringlen = substringlen;
    return maxsubstringlen;
}
