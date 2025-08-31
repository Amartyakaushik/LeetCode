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
    bool check(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return true;
        if(!root1 || !root2) {
            cout<<"If or " << endl;
            return false;
        }
        cout<<"Root1 is -> " << root1-> val << " Root2 is -> " << root2->val << endl;
        if(root1->val != root2->val) {
            cout<< "if check " << endl;
            return false;
        }
        bool left = check(root1->left, root2->left);
        bool right = check(root1->right, root2->right);
        cout<<"Left is -> " << left << " Right is " << right << endl;
        return (left && right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool present = false;
        bool flag = false;
        if(!root || !subRoot) return false;
        if(root->val == subRoot->val){
            present = check(root, subRoot);
            if(present) {
                return true;
                flag = true;
            }
        }
        present = isSubtree(root->left, subRoot);
        if(present) return true;
        present = isSubtree(root->right, subRoot);
        return present;
    }
};