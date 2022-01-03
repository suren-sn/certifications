#include<stdint.h>

uint32_t reverseBits(uint32_t n) {
    if(n<1) return 0;
    
    uint32_t rev=0;
    int bit;
    int count=32;
    
    while(n>0){
        bit = n&1;
        rev = (rev<<1) | bit;
        n = n>>1;
        count--;
    }
    
    return rev<<count;
}

uint32_t reverseBits1(uint32_t n) {
    uint32_t rev=0;
    int bit;
    
    for(int i=0; i<32; i++){
        bit = n&1;
        rev = (rev<<1) | bit;
        n = n>>1;
    }
    return rev;
}
