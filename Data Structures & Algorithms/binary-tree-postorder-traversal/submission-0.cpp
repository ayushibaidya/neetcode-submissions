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

    void postOrder(TreeNode* root, vector<int> &postOrderT){
        if(root == NULL){
            return; 
        }

        postOrder(root->left, postOrderT); 
        postOrder(root->right, postOrderT); 
        postOrderT.push_back(root->val); 
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrderT; 

        postOrder(root, postOrderT); 

        return postOrderT; 
    }
};