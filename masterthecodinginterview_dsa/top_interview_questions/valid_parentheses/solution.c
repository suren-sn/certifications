#include<string.h>
#include<stdbool.h>

bool isValid(char * s){
    int len = strlen(s);
    if((len%2 != 0) || (len<1)) return false;
    
    int qSize = len/2;
    char queue[qSize];
    int qidx = -1;
    
    for(int i=0; i<len; i++){
        if(s[i] == '(' ||
          s[i] == '{' ||
          s[i] == '['){
            if(++qidx >= qSize) return false;
            queue[qidx] = s[i];
        } else {
            if(qidx < 0) return false;
            
            char ch;
            if(s[i] == ')') ch = '(';
            else if (s[i] == '}') ch = '{';
            else ch = '[';
            
            if(queue[qidx] != ch) return false;
            qidx--;
        }
    }
    
    if(qidx > -1) return false;
    return true;
}
