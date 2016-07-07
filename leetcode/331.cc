/*
 * 一开始想用stack做，但始终想不清楚入栈出栈的规律.后来看了discuss，需要抓住一个重点.
 * empty tree有0个node，1个null，每当往tree里加一个节点，就多1个node，多1个null.
 * 而preorder序列可以看成是往emptry-tree里加节点的过程，因此只有判断当前的tree是否valid就可以了。
 * See:
 * https://leetcode.com/discuss/84073/straight-forward-c-solution-with-explanation
 */
class Solution {
 public:
  bool isValidSerialization(string preorder) {
    int node_cnt = 0, null_cnt = 0;
    char pre = ',';
    for (int i = 0; i < preorder.size(); ++i) {
      if (pre == ',') {
        if (preorder[i] == '#') ++null_cnt;
        else ++node_cnt;
        if (1 + node_cnt <= null_cnt && i != preorder.size() - 1) return false;
      }
      pre = preorder[i];
    }
    return 1 + node_cnt == null_cnt;
  }
};
