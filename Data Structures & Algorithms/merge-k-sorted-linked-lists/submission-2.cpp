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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> sortedList; 

        for(auto& l:lists){
            while(l){
                sortedList.push_back(l->val);
                l = l->next; 
            } 
        }

        sort(sortedList.begin(), sortedList.end()); 

        ListNode* dummy = new ListNode(0); 
        ListNode* curr = dummy; 

        for(int node:sortedList){
            curr->next = new ListNode(node); 
            curr = curr->next; 
        }
        return dummy->next; 
    }
};
