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
    int answer = 0;
    long long int curr = 0;
    unordered_map<long long int, int> dp;
    void dfs(TreeNode *v, const int &x){
        if(!v){
            return;
        }
        curr += v->val;
        answer += dp[curr - x];
        ++dp[curr];
        dfs(v->left, x);
        dfs(v->right, x);
        --dp[curr];
        curr -= v->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        dp[0] = 1;
        dfs(root, targetSum);
        return answer;
    }
};
