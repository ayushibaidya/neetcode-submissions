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

    int count = 0; 

    int countGoodNodes(TreeNode* root, int maxVal){
        if(root == NULL) return 0; 

        if(root->val >= maxVal){
            count++; 
            maxVal = max(maxVal, root->val); 
        }
        countGoodNodes(root->left, maxVal); 
        countGoodNodes(root->right, maxVal); 
        return count; 
    }

    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, root->val); 
    }
};
