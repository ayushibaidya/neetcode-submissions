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
    void reorderList(ListNode* head) {
        if(head == NULL) return;

        vector<ListNode*> temp; 

        ListNode* curr = head; 
        while(curr != NULL){
            temp.push_back(curr); 
            curr = curr->next; 
        }

        int i = 0; int j = temp.size()-1; 

        while(i < j){
            temp[i]->next = temp[j]; 
            i++; 
            if(i >= j){
                break; 
            }
            temp[j]->next = temp[i]; 
            j--; 
        }
        temp[i]->next = NULL; 
    }
};
