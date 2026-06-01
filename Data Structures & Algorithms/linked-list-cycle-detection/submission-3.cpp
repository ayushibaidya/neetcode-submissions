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
        if(head == NULL || head->next == NULL) return false; 

        unordered_set<ListNode*> s; 

        ListNode* curr = head; 

        while(curr != NULL){
            if(s.find(curr) != s.end()){
                return true; 
            }
            s.insert(curr); 
            curr = curr->next; 
        }
        return false; 
    }
};
