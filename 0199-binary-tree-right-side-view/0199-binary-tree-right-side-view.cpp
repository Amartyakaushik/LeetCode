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
    vector<int> rightSideView(TreeNode* root) {
        // vector<int> ans;
        // if(!root) return ans;
        // ans.push_back(root->val);
        // TreeNode* parent = root;
        // unordered_map<int, bool> visited;
        // int count;
        // while(root){
        //     if(root->right && !visited[root->right->val]){
        //         root = root->right;
        //         ans.push_back(root->val);
        //         visited[root->val] = true;
        //         count++;
        //     }else if(root->left && !visited[root->left->val]){
        //         root = root->left;
        //         ans.push_back(root->val);
        //         visited[root->val] = true;
        //         count++;
        //     }else{
        //         // root = parent -> left;
        //         if(parent->left) parent = parent->left;
        //         else root = nullptr;
        //         for(int i = 0; i < --count; i++){
        //             if(parent->right){
        //                 root = parent->right;
        //                 parent = parent->right;
        //             }else{
        //                 root = parent->left;
        //                 parent = parent->left;
        //             }
        //         }
        //     }
        // }
        // return ans;

        
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                
                if(i == size - 1) ans.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
};