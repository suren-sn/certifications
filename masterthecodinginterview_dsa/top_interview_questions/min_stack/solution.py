#python3
class MinStack:

    def __init__(self):
        self.stack = []
        self.minval = float('inf')

    def push(self, val: int) -> None:
        if val < self.minval:
            self.minval = val
        self.stack.append((val,self.minval))

    def pop(self) -> None:
        self.stack.pop()
        if self.stack:
            self.minval = self.stack[-1][1]
        else:
            self.minval = float('inf')

    def top(self) -> int:
        return self.stack[-1][0]

    def getMin(self) -> int:
        return self.minval


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
