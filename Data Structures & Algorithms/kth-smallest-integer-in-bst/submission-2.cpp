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
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0; 

        priority_queue<int> pq;
        queue<TreeNode*> q; 
        q.push(root); 

        while(!q.empty()){
            TreeNode* curr = q.front(); 
            q.pop(); 

            pq.push(curr->val); 
            while(pq.size() > k){
                pq.pop(); 
            }
            if(curr->left) q.push(curr->left); 
            if(curr->right) q.push(curr->right); 
        }
        return pq.top(); 
    }
};
