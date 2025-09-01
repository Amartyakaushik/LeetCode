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
    int dfs(TreeNode* root, int maxVal){
        if(!root) return 0;
        int count = 0;
        if(root->val >= maxVal){
          maxVal = root->val;  
            count = 1;
        }
        maxVal = max(maxVal, root->val);
        return (count + dfs(root->left, maxVal) + dfs(root->right, maxVal));
    }
    int goodNodes(TreeNode* root){
        int count = 0;
        int ans = dfs(root, root->val);
        return ans;
    }
};