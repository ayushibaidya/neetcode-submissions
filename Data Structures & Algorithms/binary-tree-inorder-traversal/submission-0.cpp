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

    void inorder(TreeNode* root, vector<int> &inorderT){
        if(root == NULL){
            return; 
        }

        inorder(root->left, inorderT); 
        inorderT.push_back(root->val); 
        inorder(root->right, inorderT); 
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorderT; 

        inorder(root, inorderT); 

        return inorderT; 
    }
};