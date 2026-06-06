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

    TreeNode* delNode(TreeNode* root){
        if(root == NULL) return NULL; 

        if(root->left == NULL && root->right == NULL){
            //delete the node and return tree 
            delete(root); 
            return NULL;  
        }else if(root->left == NULL && root->right != NULL){
            //root->right becomes child of root->parents
            //return 
            TreeNode* temp = root->right; 
            delete(root); 
            return temp; 
        }else if(root->right == NULL && root->left != NULL){
            //root->left becomes child of root->parents
            //return 
            TreeNode* temp = root->left; 
            delete(root); 
            return temp; 
        }else{
            //both children exists 
            TreeNode* succ = root->right; 
            while(succ->left){
                succ = succ->left; 
            }
            root->val = succ->val; 
            root->right = deleteNode(root->right, succ->val);
        }
        return root; 
    } 
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL; 

        if(key > root->val){
            root->right = deleteNode(root->right, key); 
        }else if(key < root->val){
            root->left = deleteNode(root->left, key); 
        }else{
            return delNode(root); 
        }
        return root; 
    }
};