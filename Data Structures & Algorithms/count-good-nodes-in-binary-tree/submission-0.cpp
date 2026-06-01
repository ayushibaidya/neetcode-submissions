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

    int countGoodNodes(TreeNode* root, int maxNode){
        if(root == NULL){
            return 0; 
        } 

        int count = 0; 

        if(root->val >= maxNode){
            count = 1; 
        }

        maxNode = max(maxNode, root->val); 

        count += countGoodNodes(root->left, maxNode); 
        count += countGoodNodes(root->right, maxNode); 
    
        return count; 
    }

    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root->val); 
    }
};
