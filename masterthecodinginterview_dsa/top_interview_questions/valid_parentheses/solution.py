#python3
class Solution:
    def isValid(self, s: str) -> bool:
        if (len(s)%2 != 0) or (len(s)<1): return False

        openingBraces = ['(','[','{']
        closingMap = {')':'(',
                      ']':'[',
                      '}':'{'}
        stack = []

        for b in s:
            if b in openingBraces:
                stack.append(b)
            elif stack: #Closing brace
                if closingMap[b] != stack[-1]:
                    return False
                stack.pop()
            else: #Closing brace with no opening brace
                return False
        return not bool(stack)
