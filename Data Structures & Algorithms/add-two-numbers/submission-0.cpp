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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2; 
        if(l2 == NULL) return l1; 

        int carry = 0; 

        ListNode* h1 = l1; 
        ListNode* h2 = l2; 

        ListNode* dummy = new ListNode(); 
        ListNode* h3 = dummy; 

        while(h1 != NULL || h2 != NULL){
            int val1 = (h1 != NULL) ? h1->val : 0; 
            int val2 = (h2 != NULL) ? h2->val : 0; 

            int total = val1 + val2 + carry; 
            int digit = total%10; 
            carry = total/10; 

            h3->next = new ListNode(digit); 
            h3 = h3->next; 

            if(h1 != NULL) h1 = h1->next; 
            if(h2 != NULL) h2 = h2->next; 

            if(carry != 0){
                h3->next = new ListNode(carry); 
            }
        }

        return dummy->next; 
    }
};
