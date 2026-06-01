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

        if(root == NULL) return count; 

        if(root->val >= maxVal){
            maxVal = max(maxVal, root->val); 
            count++; 
        }

        int left = countGoodNodes(root->left, maxVal); 
        int right = countGoodNodes(root->right, maxVal); 
        return max(left, right)+1; 
    }

    int goodNodes(TreeNode* root) {
        countGoodNodes(root, root->val); 
        return count; 
    }
};
