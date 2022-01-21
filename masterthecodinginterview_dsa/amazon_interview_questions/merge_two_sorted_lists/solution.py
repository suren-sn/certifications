#python3

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, l1: 'Optional[ListNode]', l2: 'Optional[ListNode]') -> 'Optional[ListNode]':
        if not l1: return l2
        if not l2: return l1

        dummyRoot = ListNode()
        l = dummyRoot

        #Linked lists l1 and l2 will be modified
        while l1 and l2:
            if l1.val < l2.val:
                l.next = l1
                l1 = l1.next
            else:
                l.next = l2
                l2 = l2.next

            l = l.next

        if l1: l.next = l1
        if l2: l.next = l2

        return dummyRoot.next
