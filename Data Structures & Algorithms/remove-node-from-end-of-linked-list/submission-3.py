# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        curr = dummy
        fast = head
        while fast and n > 0:
            fast = fast.next
            n-=1
        while fast:
            fast = fast.next
            curr = curr.next
            
        curr.next = curr.next.next
        return dummy.next
        