#python3
class Solution:
    def getPalindromeIndices(self, pivot, s):
        st=pivot-1
        while (st>=0) and (s[st] == s[pivot]):
            st-=1

        e=pivot+1
        while (e<len(s)) and (s[e] == s[pivot]):
            e+=1

        while st>=0 and e<len(s) and s[st]==s[e]:
            st-=1
            e+=1

        return (st+1, e-1)


    def longestPalindrome(self, s: str) -> str:
        if len(s) < 2: return s
        stmax=0
        emax=0
        for i in range(len(s)):
            st,e = self.getPalindromeIndices(i, s)
            if (e-st) > (emax-stmax):
                stmax = st
                emax = e
        return s[stmax:emax+1]
