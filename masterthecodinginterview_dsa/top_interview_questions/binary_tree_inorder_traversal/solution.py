#python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        """
        Iterative solution
        """
        stack = []
        result = []

        curr = root
        while curr or stack:
            # push
            # pop
            # add
            # right
            while curr:
                stack.append(curr)
                curr = curr.left

            curr = stack.pop()
            result.append(curr.val)
            curr = curr.right

        return result

    def inorderTraversal1(self, root: Optional[TreeNode]) -> List[int]:
        """
        Iterative solution
        """
        stack = []
        result = []
        visited = set()

        curr = root
        while curr:
            if curr.left and curr.left not in visited:
                stack.append(curr)
                curr = curr.left
                continue

            result.append(curr.val)
            visited.add(curr)

            if curr.right:
                curr = curr.right
            elif stack:
                curr = stack.pop()
            else:
                break

        return result

    def inorderTraversal_recur(self, root: Optional[TreeNode]) -> List[int]:
        """
        Recursive solution
        """
        if not root:
            return []

        result = []
        if root.left:
            result.extend(self.inorderTraversal(root.left))
        result.append(root.val)
        if root.right:
            result.extend(self.inorderTraversal(root.right))

        return result
