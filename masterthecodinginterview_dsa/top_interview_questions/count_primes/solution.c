#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

bool isPrime(int n){
    if(n<2) return false;
    
    for(int i=2; i*i<=n; i++){
        if(n%i == 0) return false;
    }
    return true;
}

int countPrimes(int n){
    if(n<2) return 0;
    
    int count=0;
    char *visited = (char*)malloc(sizeof(char)*n);
    
    memset(visited, 0, n);
    
    for(int i=2; i<n; i++){
        if(visited[i] == 0){
            //if(isPrime(i)){
                count++;
                for(int j=i*2; j<n; j+=i){
                    visited[j] = 1;
                }
            //}
        }
        //visited[i] = 1;   //A number never repeats
    }
    
    free(visited);
    return count;
}
