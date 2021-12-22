#include<stdlib.h>
#include<assert.h>

#define MAX_CALLS 3 * 10000

typedef struct {
    int *stack;
    int *minStack;
    int len;
} MinStack;


MinStack* minStackCreate() {
    MinStack *obj = (MinStack*) malloc(sizeof(MinStack));
    if(obj == NULL){
        return NULL;
    }
    
    obj->stack = (int*) malloc(sizeof(int)*MAX_CALLS);
    if(obj->stack == NULL){
        free(obj);
        return NULL;
    }
    
    obj->minStack = (int*) malloc(sizeof(int)*MAX_CALLS);
    if(obj->minStack == NULL){
        free(obj->stack);
        free(obj);
        return NULL;
    }
    
    obj->len = 0;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    if(obj == NULL) return;
    
    int *stack = obj->stack;
    int *minStack = obj->minStack;
    int len = obj->len;
    int min;
    
    if((len+1) > MAX_CALLS){
        return;
    }
    
    stack[len] = val;
    
    if(len>0){
        min = minStack[len-1];
        if(val<min)
            min = val;
    }else{
        min = val;
    }
    minStack[len] = min;
    
    obj->len++;
}

void minStackPop(MinStack* obj) {
    if(obj == NULL) return;
    
    if(obj->len > 0)
        obj->len--;
}

int minStackTop(MinStack* obj) {
    int len;
    
    assert(obj != NULL);
    len = obj->len;
    assert(len>0);
    
    return obj->stack[len-1];
}

int minStackGetMin(MinStack* obj) {
    int len;
    
    assert(obj != NULL);
    len = obj->len;
    assert(len>0);
    
    return obj->minStack[len-1];
}

void minStackFree(MinStack* obj) {
    if(obj == NULL) return;
    if(obj->minStack) free(obj->minStack);
    if(obj->stack) free(obj->stack);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
