/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> st; 

        ListNode* curr = head; 

        while(curr != NULL){
            if(st.find(curr) == st.end()){
                st.insert(curr); 
                curr = curr->next; 
            }else{
                return true; 
            }
        }
        return false;
    }
};
