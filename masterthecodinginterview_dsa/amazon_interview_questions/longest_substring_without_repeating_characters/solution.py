#python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        hashset = set()
        l=0
        maxSubstringLen = 0
        for r in range(len(s)):
            while s[r] in hashset:
                hashset.remove(s[l])
                l+=1
            hashset.add(s[r])
            maxSubstringLen = max(maxSubstringLen, r-l+1)

        return maxSubstringLen
