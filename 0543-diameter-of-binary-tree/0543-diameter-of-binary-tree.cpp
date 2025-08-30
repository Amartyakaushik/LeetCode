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
    int depth(TreeNode* root, int& maxDia){
        if(!root) return 0;
        int leftDepth = depth(root-> left, maxDia);
        int rightDepth = depth(root-> right, maxDia);
        
        maxDia = max(maxDia, leftDepth + rightDepth);
        return 1 + max(leftDepth , rightDepth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxDia = 0;
        depth(root, maxDia);
        return maxDia;
    }
};