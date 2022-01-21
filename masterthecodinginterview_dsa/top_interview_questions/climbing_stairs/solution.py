#python3
class Solution:
    def climbStairs(self, n: int) -> int:
        one, two = 1, 1

        for i in range(n-1):
            temp = one
            one = one + two
            two = temp
        return one

    def climbStairs2(self, n: int, currentStep=0, resultCache=None) -> int:
        if not resultCache: resultCache = {}
        if n in resultCache: return resultCache[n]

        result = 0
        for i in [1,2]:
            s = currentStep + i

            if s == n:
                result += 1
            elif s < n:
                result += self.climbStairs(n, s, resultCache)
            else:
                break
        resultCache[n] = result
        return result


    def climbStairs1(self, n: int, currentStep=0) -> int:
        result = 0

        for i in [1,2]:
            s = currentStep + i

            if s == n:
                result += 1
            elif s < n:
                result += self.climbStairs(n,s)
            else:
                break
        return result
