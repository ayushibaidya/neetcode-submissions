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

    int countGoodNodes(TreeNode* root, int maxNode, int &count){
        if(root == NULL) return count; 

        if(maxNode <= root->val){
            maxNode = max(maxNode, root->val); 
            count++; 
        }
        int left = countGoodNodes(root->left, maxNode, count);
        int right = countGoodNodes(root->right, maxNode, count); 
        return max(left, right)+1; 
    }

    int goodNodes(TreeNode* root) {
        int count = 0; 
        int maxNode = root->val; 
        countGoodNodes(root, maxNode, count);
        return count; 
    }
};
