#python3
class Solution:
    def getLongestCommonPrefixLength(self, s1, s1Len, s2, s2Len):
        maxLen = min(s1Len, s2Len)

        i = 0
        for i in range(maxLen):
            if s1[i] != s2[i]: break
        else:
            i+=1
        return i

    def longestCommonPrefixDFS(self, strs: List[str]) -> str:
        commonPrefix = strs[0]
        prefixLen = len(commonPrefix)

        for i in range(1,len(strs)):
            if prefixLen == 0 or len(strs[i]) == 0: return ""
            prefixLen = self.getLongestCommonPrefixLength(commonPrefix, prefixLen,
                                                     strs[i], len(strs[i]))

        return commonPrefix[:prefixLen]

    def longestCommonPrefixBFS(self, strs: List[str]) -> str:

        i=0
        for i in range(len(strs[0])):
            for j in range(1,len(strs)):
                if i == len(strs[j]) or strs[0][i] != strs[j][i]:
                    return strs[0][:i]
        else:
            i+=1

        return strs[0][:i]

    def longestCommonPrefix(self, strs: List[str]) -> str:
        #sol = self.longestCommonPrefixDFS(strs)
        sol = self.longestCommonPrefixBFS(strs)
        return sol
