# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        groupprev = dummy
        def getkth(curr, k):
            while curr and k > 0:
                curr = curr.next
                k-=1
            return curr
        while True:
            kth = getkth(groupprev, k)
            if not kth:
                return dummy.next
            groupnext = kth.next
            prev, curr = kth.next, groupprev.next
            while curr != groupnext:
                tmp = curr.next
                curr.next = prev
                prev = curr
                curr = tmp
            tmp = groupprev.next
            groupprev.next = kth
            groupprev = tmp
        return dummy.next

