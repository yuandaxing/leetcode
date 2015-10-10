# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @param k, an integer
    # @return a ListNode
    def splice(self, head, k) :
        newhead, i, travel= None, 0, head
        while i < k and travel :
            travel, i = travel.next, i+1
        if i < k : return head, None
        i=0
        while i < k and head :
            cur, head = head, head.next
            cur.next, newhead = newhead, cur
            i = i+1
        return newhead, head
    def reverseKGroup(self, head, k):
        new, old = self.splice(head, k)
        last  = head
        while old :
            n1, o1 = self.splice(old, k)
            last.next = n1
            last, old = old, o1
        return new
