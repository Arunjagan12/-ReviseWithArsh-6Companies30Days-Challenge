/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
 const int INF = 0x3f3f3f3f;
    int ans = 0;
    
    tuple<int,int,int> dfs(TreeNode* x) {
        if (!x) return {0, 0, 0};
        auto [minl, maxl, suml] = dfs(x->left);
        auto [minr, maxr, sumr] = dfs(x->right);
        if ((x->left && (minl==INF || maxl>=x->val)) ||
            (x->right && (minr==INF || minr<=x->val)))
            return {INF, INF, 0};
        tuple<int,int,int> ret = {x->left?minl:x->val, x->right?maxr:x->val, suml+sumr+x->val};
        ans = max(ans, suml+sumr+x->val);
        return ret;
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
