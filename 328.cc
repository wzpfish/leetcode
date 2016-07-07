/*
 * 两个指针，一个指向odd,一个指向even,然后一直往下连就行了..
 * 注意考虑全连到最后的情况.
 */
class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) return head;
    if (head->next == nullptr) return head;
    ListNode* odd_ptr = head;
    ListNode *even_ptr = head->next;
    ListNode *even_head = even_ptr;
    while (even_ptr->next) {
      odd_ptr->next = even_ptr->next;
      odd_ptr = even_ptr->next;
      even_ptr->next = odd_ptr->next;
      even_ptr = odd_ptr->next;
    }
    odd_ptr->next = even_head;
    return head;
  }
};
