#include<stdio.h>
#include<stdlib.h>

/* Runtime: 4 ms
 * Memory: 5.8 MB
 */
int mySqrt(int x){
    if(x<2) return x;
    
    int low=1, high=1+x/2;
    long int mid;
    int root;
    while(low<=high){
        mid = (low+high)/2;
        
        if(mid*mid < x){
            root = mid;
            low = mid+1;
        }else if(mid*mid > x){
            high = mid-1;
        }else{
            root = mid;
            break;
        }
    }
    
    return root;
}

/* Runtime: 16 ms
 * Memory: 5.5 MB
 */
int mySqrt1(int x){
    if(x<2) return x;
    
    long int n=1;
    while(n*n < x){
        n++;
    }  
    
    return n*n == x ? n:n-1;
}

int main(int argc, char **argv){
    if(argc<2){
        printf("Argument missing\n");
        return 1;
    }
    printf("sqrt: %d\n", mySqrt1(atoi(argv[1])));
    return 0;
}
