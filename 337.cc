/*
 * 一个节点的最优值为：max(不选它，选它) 即max(left + right, left_left + left_right + right_left + right_right + cur_val)
 */
class Solution {
public:
    int dfs(TreeNode* node, int &l, int &r) {
        if (node == nullptr) return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = dfs(node->left, ll, lr);
        r = dfs(node->right, rl, rr);
        return max(root->val + ll + lr + rl + rr, l + r);
    }
    int rob(TreeNode* root) {
        int l, r;
        return dfs(root, l, r);
    }
};
