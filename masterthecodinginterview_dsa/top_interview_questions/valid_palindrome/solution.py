#python3
class Solution:

    def isAlphaNumeric(self, c) -> bool:
        if ('a' <= c and c <= 'z') or ('0' <= c and c <= '9'):
            return True
        return False

    def isPalindrome(self, s: str) -> bool:
        i=0
        j=len(s)-1

        while i<j:
            a = s[i].lower()
            if not self.isAlphaNumeric(a):
                i+=1
                continue

            b = s[j].lower()
            if not self.isAlphaNumeric(b):
                j-=1
                continue

            if a != b:
                return False

            i+=1
            j-=1

        return True
