#include<limits.h>
#include<stdio.h>

int reverse(int x){
    int rev=0;
    int digit;
    int sign = x>0 ? 1:-1;
    
    while(x){
        digit = x%10;
        x/=10;
        
        if(sign > 0){
            if(rev > (INT_MAX-digit)/10) return 0;
        }else{
            if(rev < (INT_MIN-digit)/10) return 0;
        }

        rev = rev * 10 + digit;
    }
    
    return rev;
}
int main(void){
    int inputs[] = {123, -123};
    int size = sizeof(inputs)/sizeof(int);

    for(int i=0; i<size; i++){
        printf("Rev of %d is %d\n", inputs[i], reverse(inputs[i]));
    }
    return 0;
}
