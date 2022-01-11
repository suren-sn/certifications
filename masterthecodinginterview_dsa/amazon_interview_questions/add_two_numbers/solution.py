#python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1 and not l2: return ListNode(0)
        if not l1: return l2
        if not l2: return l1

        lcurr = lprev = lhead = ListNode(0)
        carry = 0
        lbig = None

        while l1 and l2:
            val = l1.val + l2.val + carry
            carry = int(val/10)

            lcurr.val = val%10
            lprev = lcurr
            lcurr.next = ListNode(0)
            lcurr = lcurr.next

            l1 = l1.next
            l2 = l2.next
        else:
            lbig = l1 if l1 else l2

        while lbig:
            val = lbig.val + carry
            carry = int(val/10)

            lcurr.val = val%10
            lprev = lcurr
            lcurr.next = ListNode(0)
            lcurr = lcurr.next

            lbig = lbig.next

        lcurr = lprev
        lcurr.next = None

        if carry != 0:
            lcurr.next = ListNode(carry)

        return lhead
