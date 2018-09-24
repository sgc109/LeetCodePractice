// 11m 14s O(n)
// 2 try (Compile Error..)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    int dfs(TreeNode* cur){
        if(cur == NULL) return 0;
        int l = dfs(cur->left);
        int r = dfs(cur->right);
        int c = cur->val;
        ans = max(ans, l + r + c);
        return max({0, c, l + c, r + c});
    }
    int maxPathSum(TreeNode* root) {
        ans = -0x3c3c3c3c;
        dfs(root);
        return ans;
    }
};
