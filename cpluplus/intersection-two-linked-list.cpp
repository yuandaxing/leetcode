#include <iostream>
#include <stdlib.h>
//* Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
  int Size(ListNode* head)
  {
    int size = 0;
    while(head != NULL)
    {
      size++;
      head = head->next;
    }
    return size;
  }
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int size1 = Size(headA), size2 = Size(headB);
    int advance = abs(size1 - size2);
    if (size1 < size2) std::swap(headA, headB);
    while(advance != 0)
    {
      headA = headA->next;
      advance--;
    }
    while(headA != NULL && headB != NULL && headA != headB)
    {
      headA = headA->next;
      headB = headB->next;
    }
    return headA;
  }
};

int main(int argc, char *argv[])
{
  ListNode t1(1), *t2 = NULL;
  Solution sol;
  std::cout << sol.getIntersectionNode(&t1, t2) << std::endl;
  return 0;
}
