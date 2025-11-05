/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    void preOrder(TreeNode* root, string& data){
        if(root == nullptr){
            data += "null,";
            return;
        }
        data += to_string(root->val) + ",";
        preOrder(root->left, data);
        preOrder(root->right, data);
    }
    string serialize(TreeNode* root) {
        string data = "";
        // if(root->val == nullptr) data += "null";
        preOrder(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    void makeTreePreOrder(vector<string>& tree, int &count, TreeNode*& root){
        if(count >= tree.size() || tree[count] == "null"){
            root = nullptr;
            count++;
            return;
        }
        root = new TreeNode(stoi(tree[count++]));
        makeTreePreOrder(tree, count, root->left);
        makeTreePreOrder(tree, count, root->right);
    }

    TreeNode* deserialize(string data) {
        vector<string> tree;
        string ele = "";
        stringstream str(data);
        while(getline(str, ele,',')){
            tree.push_back(ele);
        }
        TreeNode* ans = nullptr;
        int count = 0;
        makeTreePreOrder(tree, count, ans);
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));