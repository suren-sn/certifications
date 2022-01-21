#python3
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head: return None

        orgListMap = {} #address:index
        dupListMap = {} #index:address

        dummy = Node(0)
        dupcurr = dummy
        orgcurr = head
        index = 0
        while orgcurr:
            dupcurr.next = Node(orgcurr.val)
            dupcurr = dupcurr.next

            orgListMap[orgcurr] = index
            dupListMap[index] = dupcurr

            orgcurr = orgcurr.next
            index+=1

        dupcurr.next = None
        duphead = dummy.next


        orgcurr = head
        dupcurr = duphead
        while orgcurr:
            if orgcurr.random:
                dupcurr.random = dupListMap[orgListMap[orgcurr.random]]
            else:
                dupcurr.random = None

            orgcurr = orgcurr.next
            dupcurr = dupcurr.next

        return duphead
