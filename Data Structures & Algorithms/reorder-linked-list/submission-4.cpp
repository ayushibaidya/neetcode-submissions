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
        ListNode* slow = head;
        ListNode* fast = head; 
        while(fast != NULL && fast->next != NULL){
            slow = slow->next; 
            fast = fast->next->next; 
        }

        ListNode* secondHead = slow->next; 
        slow->next = NULL; 

        ListNode* prev = NULL; 
        ListNode* next = NULL; 

        while(secondHead != NULL){
            next = secondHead->next;
            secondHead->next = prev; 
            prev = secondHead; 
            secondHead = next; 
        }

        ListNode* firstHead = head; 
        secondHead = prev; 

        while(secondHead != NULL){
            ListNode* firstNext = firstHead->next; 
            ListNode* secondNext = secondHead->next; 
            firstHead->next = secondHead; 
            firstHead = firstNext; 
            secondHead->next = firstNext; 
            secondHead = secondNext; 
        }
    }
};
