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

    bool isSubTreeMatch(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true; 
        if(p == NULL || q == NULL) return false; 
        if(p->val != q->val) return false; 

        bool leftNode = isSubTreeMatch(p->left, q->left); 
        bool rightNode = isSubTreeMatch(p->right, q->right); 

        return leftNode && rightNode; 
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false; 
        if(subRoot == NULL) return true; 

        if(root->val == subRoot->val){
            if(isSubTreeMatch(root, subRoot)){
                return true; 
            }
        }
        bool leftSide = isSubtree(root->left, subRoot);
        bool rightSide = isSubtree(root->right, subRoot); 

        return leftSide || rightSide; 
    }
};
