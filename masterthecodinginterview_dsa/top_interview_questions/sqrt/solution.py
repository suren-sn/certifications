#python3
class Solution:
    def mySqrt(self, x: int) -> int:
        low=0;
        high=x//2 + 1;

        sqrt = 0
        while low <= high:         #2 <= 3
            mid = (low + high)//2  #mid = 2
            sq = mid*mid           #sqrt = 1

            if sq > x:
                high = mid-1
            elif sq < x:
                sqrt = mid
                low = mid + 1
            else:
                sqrt = mid
                break

        return sqrt

    def mySqrt1(self, x: int) -> int:
        if x <= 1: return x

        for i in range(1, x//2 + 2):
            if i * i > x:
                break
        return i-1
