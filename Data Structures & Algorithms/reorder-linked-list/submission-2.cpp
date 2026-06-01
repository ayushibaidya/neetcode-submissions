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
        //find the middle of the list 
        ListNode* slow = head; 
        ListNode* fast = head; 

        while(fast != NULL && fast->next != NULL){
            slow = slow->next; 
            fast = fast->next->next; 
        }

        //reverse the second half 
        ListNode* second = slow->next; 
        slow->next = NULL; 
        ListNode* prev = NULL; 

        while(second != NULL){
            ListNode* next = second->next; 
            second->next = prev; 
            prev = second; 
            second = next; 
        }

        //merge both lists with head to head and prev
        ListNode* first = head; 
        second = prev; 

        while(second != NULL){
            ListNode* next1 = first->next; 
            first->next = second; 
            first = next1;  
            ListNode* next2 = second->next; 
            second->next = next1;
            second = next2; 
        }
    }
};
