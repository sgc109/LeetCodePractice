// 23m 3s O(nlgn)
// 2 try
// Why on earth was I implementing O(lgn) LCA query..?

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
    map<int,int> mp;
    vector<vector<int>> G;
    vector<TreeNode*> nodes;
    vector<int> par;
    vector<int> dep;
    int N;
    void dfs1(TreeNode* cur){
        if(cur == NULL) return;
        nodes.push_back(cur);
        mp[cur->val] = N++;
        dfs1(cur->left);
        dfs1(cur->right);
    }
    void dfs2(TreeNode* cur){
        // if(cur == NULL) return;
        int u = mp[cur->val];
        if(cur->left != NULL) {
            int v = mp[cur->left->val];
            G[u].push_back(v);
            G[v].push_back(u);
            dfs2(cur->left);
        }
        if(cur->right != NULL) {
            int v = mp[cur->right->val];
            G[u].push_back(v);
            G[v].push_back(u);
            dfs2(cur->right);
        }
    }
    void dfs3(int cur, int dad){
        for(int nxt : G[cur]){
            if(nxt == dad) continue;
            par[nxt] = cur;
            dep[nxt] = dep[cur] + 1;
            dfs3(nxt, cur);
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs1(root);
        G = vector<vector<int>>(N);
        par = vector<int>(N, -1);
        dep = vector<int>(N, 0);
        dfs2(root);
        dfs3(0, -1);
        
        int u = mp[p->val];
        int v = mp[q->val];
        
        if(dep[u] > dep[v]) swap(u, v);
        while(dep[u] < dep[v]) v = par[v];
        while(u != v) u = par[u], v = par[v];
        return nodes[u];
    }
};
