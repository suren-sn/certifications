int removeDuplicates(int* nums, int numsSize){
    if(numsSize < 2) return numsSize;
    int k=0;
    
    for(int i=0; i<numsSize; i++){
        if(nums[i] != nums[k]){
            nums[++k] = nums[i];
        }
    }
    return k+1;
}
