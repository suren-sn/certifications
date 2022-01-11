#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<stdio.h>

#define MAX_LEN 10000

typedef struct hashNode{
    int key;
    int value;
    struct hashNode *next;
}hashNode;

unsigned long hashFunc(int key){
    return abs(key) % MAX_LEN; 
}

void* hashInit(void){
    hashNode **h = (hashNode**) malloc(sizeof(hashNode*) * MAX_LEN);
    memset(h, 0, sizeof(hashNode*) * MAX_LEN);
    return (void*)h;
}

bool hashPush(void *hndl, int key, int value){
    hashNode **h = (hashNode**)hndl;
    unsigned long index = hashFunc(key);
    
    hashNode *node = malloc(sizeof(hashNode));
    if(node == NULL){
        return false;
    }
    
    node->key = key;
    node->value = value;
    /* Insert the new node at head */
    node->next = h[index];
    h[index] = node;
    return true;
}

bool hashGet(void *hndl, int key, int *value){
    hashNode **h = (hashNode**)hndl;
    unsigned long index = hashFunc(key);
    hashNode *node = h[index];
    
    while(node != NULL){
        if(node->key == key) {
            *value = node->value;
            return true;
        }
        node = node->next;
    }
    
    return false;
}

void hashDeinit(void *hndl){
    hashNode **h = (hashNode**)hndl;
    unsigned int i;
    hashNode *node, *temp;
    
    for (i=0; i<MAX_LEN; i++){
        node = h[i];
        while(node != NULL){
            temp = node->next;
            free(node);
            node = temp;
        }
    }
    
    free(h);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    void *complements = hashInit();
    int value;
    int *result = NULL;
    int resultSize = 0;
    int comp;
    
    for(int i=0; i<numsSize; i++){
        comp = target - nums[i];
        if(hashGet(complements, comp, &value) == true) {
            result = malloc(sizeof(int)*2);
            result[0] = value;
            result[1] = i;
            resultSize = 2;
            break;
        }
        
        hashPush(complements, nums[i], i);  // TODO: Validate return status
    }
    
    hashDeinit(complements);
    *returnSize = resultSize;
    return result;
}

int main(void)
{
    int *result;
    int nums[] = {2,7,11,15};
    int numsSize = sizeof(nums)/sizeof(int);
    int target = 9;
    int returnSize;
    
    result = twoSum(nums, numsSize, target, &returnSize);
    printf("returnSize : %d\n", returnSize);
    for(int i=0; i<returnSize; i++){
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
