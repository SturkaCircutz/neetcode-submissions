# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        
        second = slow.next
        slow.next = None
        #reverse
        prev = None

        while second:
            tmp = second.next
            second.next = prev
            prev = second
            second = tmp
        
        first, sec = head, prev
        while sec:
            tmp1, tmp2 = first.next, sec.next
            first.next = sec
            sec.next = tmp1
            first, sec = tmp1, tmp2
            