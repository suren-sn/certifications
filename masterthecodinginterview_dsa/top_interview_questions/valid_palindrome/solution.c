#include<stdbool.h>
#include<string.h>
#include<ctype.h>

bool isAlphaNumeric(char c){
    if(c >= 'a' && c <= 'z') return true;
    if(c >= 'A' && c <= 'Z') return true;
    if(c >= '0' && c <= '9') return true;
    return false;
}

bool isPalindrome(char * s){
    int len=strlen(s);
    int l=0, h=len-1;
    
    while(l<h){
        if(!isAlphaNumeric(s[l])){
            l++;
            continue;
        }
        
        if(!isAlphaNumeric(s[h])){
            h--;
            continue;
        }
        
        if(tolower(s[l]) != tolower(s[h])) return false;
        l++;
        h--;
    }
    return true;
}
