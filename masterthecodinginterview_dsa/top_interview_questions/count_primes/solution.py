#python3
class Solution:
    def countPrimes(self, n: int) -> int:
        visited = [False] * n
        count = 0

        for i in range(2,n):
            if not visited[i]:
                count+=1
                for j in range(i*2,n,i):
                    visited[j] = True
        return count
