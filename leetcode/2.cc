
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    int carry = 0;
    while (l1 || l2 || carry > 0) {
      int v1 = l1 ? l1->val : 0;
      int v2 = l2 ? l2->val : 0;
      int sum = (v1 + v2 + carry) % 10;
      carry = (v1 + v2 + carry) / 10;
      cur->next = new ListNode(sum);
      cur = cur->next;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    cur = head;
    head = head->next;
    delete cur;
    return head;
  }
};
