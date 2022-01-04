/*
Time complexity = O(n)
Space complexity = O(1)
*/
void rotate(int* nums, int numsSize, int k){
    k = k%numsSize;
    
    void reverse(int *nums, int l, int h){
        int temp;
        while(l<h){
            temp = nums[l];
            nums[l] = nums[h];
            nums[h] = temp;
            l++;
            h--;
        }
    }
    
    reverse(nums, 0, numsSize-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, numsSize-1);
}

/*
Time complexity = O(n)
Space complexity = O(n)
*/
#include<stdlib.h>
#include<string.h>
void rotateMemOn(int* nums, int numsSize, int k){
    k = k%numsSize;
    if(k<1) return;
    
    int *dup = (int*)malloc(sizeof(int)*numsSize);
    memcpy(dup, nums, sizeof(int)*numsSize);
    
    for(int i=0; i<numsSize; i++){
        nums[(i+k)%numsSize] = dup[i]; 
    }
    free(dup);
}

/*
Time complexity = O(n * k)
Space complexity = O(1)
*/
void rotateBruteForce(int* nums, int numsSize, int k){
    int i, j, v, temp;
    
    k = k%numsSize;
    if(k<1) return;
    
    for(i=0; i<k; i++){
        v = nums[numsSize-1];
        
        for(j=0; j<numsSize; j++){
            temp = nums[j];
            nums[j] = v;
            v = temp;
        }
    }
}
int main(){
    int nums[] = {1,2,3,4,5,6,7};
    int numsSize = sizeof(nums)/sizeof(int);
    int k=3;
    rotate(nums, numsSize, k);

    for(int i=0; i<numsSize; i++){
        printf("%d  ", nums[i]);
    }
    printf("\n");
}
