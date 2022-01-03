#python3
class Solution:
    def reverseBits(self, n: int) -> int:
        count=32
        rev=0

        while n>0:
            rev = (rev<<1) | (n&1)
            n = n>>1
            count-=1

        return rev<<count
