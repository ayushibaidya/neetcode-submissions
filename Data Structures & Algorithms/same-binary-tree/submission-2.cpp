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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true; 

        queue<pair<TreeNode*, TreeNode*>> qu; 
        qu.push({p, q}); 

        while(!qu.empty()){
            int size = qu.size(); 
            for(int i = 0; i < size; i++){
                TreeNode* pCurr = qu.front().first; 
                TreeNode* qCurr = qu.front().second; 
                qu.pop();
                if(!pCurr && !qCurr) continue; 
                if(!pCurr || !qCurr) return false; 
                if(pCurr->val != qCurr->val) return false;  
                qu.push({pCurr->left, qCurr->left}); 
                qu.push({pCurr->right, qCurr->right}); 
            }
        }
        return true; 
    }
};
