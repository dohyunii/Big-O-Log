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
    static const int mxn = 1e5 + 5;
    vector<int> g[mxn];
    bool vis[mxn];
    void dfs(TreeNode *v){
        if(v->left){
            g[v->left->val].push_back(v->val);
            g[v->val].push_back(v->left->val);
            dfs(v->left);
        }
        if(v->right){
            g[v->val].push_back(v->right->val);
            g[v->right->val].push_back(v->val);
            dfs(v->right);
        }
    }
    int solve(int v){
        int mx = 0;
        vis[v] = true;
        for(auto i : g[v]){
            if(!vis[i]){
                mx = max(mx, solve(i));
            }
        }
        return mx + 1;
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        return solve(start) - 1;
    }
};
